//
// Created by paula on 10.12.20.
//

#include <stdio.h>
#include <stdlib.h>
#include "dynDHondt.h"


int simulateLazyDHondt(profile* input, ranking* result, simulationPresets* preset){
    struct weightToAttribute* weights = calloc(1, sizeof(struct weightToAttribute)*input->attributes);

    //calculate weights ad hoc according to candidates ranked in tau
    for (int i = 0; i < input->attributes; i++) {
        weights[i].attribute = i;
        weights[i].weight = (double)input->approvalScore[i]/(double)(input->amountRanked[i]+1);
    }
    //repeat until l candidates ranked in r
    for(int o = 0; o < preset->l; o++) {
        //sort the alternatives small to large according to the weights we just calculated
        qsort(weights, input->attributes, sizeof(struct weightToAttribute), compare_weightToAttribute);

        fprintf(stderr, "Ranked n%i\n", weights[input->attributes-1].attribute);
        result->r[result->nR] = weights[input->attributes-1].attribute;
        result->nR++;

    }
    free(weights);
    return 0;
}

void lazyDHondt(profile* input, ranking* result, simulationPresets* preset){
    fprintf(stderr, "\nCalculating Lazy D'Hondt ranking with ");
    fprintf(stderr, "%i attributes and %i agents...\n\n", input->attributes, input->agents);
    fprintf(preset->file, "Lazy D'Hondt\n=============\n");

    int cont = 1;
    while(cont == 1) {
        cont += simulateLazyDHondt(input, result, preset);
        if(cont != 1)
            return;
        cont += implementAlternative(preset, result);
        if (result->nTau == preset->h)
            return;
        refreshResults(result, input);
    }
}