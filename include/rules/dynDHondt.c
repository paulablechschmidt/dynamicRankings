//
// Created by paula on 04.05.20.
//

#include <stdio.h>
#include <stdlib.h>
#include "dynDHondt.h"

void searchPattern(pattern* p, int l, int* list){
    //int* potP = calloc(l, sizeof (int)); //potential pattern
    int pos = 0; //current position in the list
    int stop = 0;

    for(p->patternbegin = 0; p->patternbegin <= l; p->patternbegin++){
        for(p->patternLen = 1; p->patternLen <= (int)l/2; p->patternLen++){
            if(p->patternbegin+p->patternLen < l) {
                stop = 0;
                pos = p->patternbegin;
                while (stop == 0) {
                    pos += p->patternLen;
                    int j = p->patternbegin;
                    for (int i = pos; i < pos + p->patternLen; i++) {
                        if (i == l) {
                            //end iteration, if end of list is reached.
                            //The found pattern is then described by patternLen and patternbegin
                            return;
                        }
                        if (list[j] != list[i]) {
                            stop = 1;
                            break;
                        }
                        j++;
                    }
                }
            }
            else break;
        }
    }
    return;
}

void patternWrapper(int l, int* list, FILE* file){
    pattern* p = calloc(1, sizeof(pattern));
    //int test[] = {1,1,2,3,1,2,3};
    //l=7;
    searchPattern(p, l, list);
    if(p->patternbegin >= l){
        fprintf(file, "FOUND NO PATTERN (IN THE GIVEN %i ELEMENTS.)\n", l);
        fprintf(stdout, "FOUND NO PATTERN (IN THE GIVEN %i ELEMENTS.)\n", l);
    } else {
        fprintf(file, "FOUND FOLLOWING PATTERN. begin:%i, length:%i\n", p->patternbegin, p->patternLen);
        fprintf(stdout, "FOUND FOLLOWING PATTERN. begin:%i, length:%i\n", p->patternbegin, p->patternLen);
    }
    free(p);
}

int simulateDynDHondt(profile* input, ranking* result, simulationPresets* preset){
    struct weightToAttribute* weights = calloc(1, sizeof(struct weightToAttribute)*input->attributes);

    //repeat until l candidates ranked in r
    for(int o = 0; o < preset->l; o++) {
        //calculate weights ad hoc according to candidates ranked in tau and r
        for (int i = 0; i < input->attributes; i++) {
            weights[i].attribute = i;
            weights[i].weight = (double)input->approvalScore[i]/(double)(input->amountRanked[i]+1);
        }
        //sort the alternatives small to large according to the weights we just calculated
        qsort(weights, input->attributes, sizeof(struct weightToAttribute), compare_weightToAttribute);

        //fprintf(stderr, "Ranked a%i\n", weights[input->attributes-1].attribute);
        result->r[result->nR] = weights[input->attributes-1].attribute;
        result->nR++;
        input->amountRanked[weights[input->attributes-1].attribute]++;

        //reset weights
        for(int i = 0; i < input->attributes; i++)
            weights[i].weight = 0;
    }
    free(weights);
    return 0;
}

void dynDHondt(profile* input, ranking* result, simulationPresets* preset){
    //fprintf(stderr, "\nCalculating Dynamic D'Hondt ranking with ");
    //fprintf(stderr, "%i attributes and %i agents...\n\n", input->attributes, input->agents);
    fprintf(preset->file, "Dynamic D'Hondt\n=============\n");
    fprintf(stdout, "\n");

    int cont = 1;
    while(cont == 1) {
        cont += simulateDynDHondt(input, result, preset);
        patternWrapper(preset->l, result->r, preset->file);
        if(cont != 1)
            return;
        cont += implementAlternative(preset, result);
        if (result->nTau == preset->h)
            return;
        refreshResults(result, input);
    }
}