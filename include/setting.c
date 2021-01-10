//
// Created by paula on 22.04.20.
//
#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <dirent.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#include "setting.h"
#include "inputOutput.h"

const char* preflibPath = "./preflib/";

profile* parseProfile(simulationPresets* preset, FILE* input);
profile* setupProfile(simulationPresets* preset);

int compare_weightToAttribute (const void *a,const void *b) {
    struct weightToAttribute *x = (struct weightToAttribute *) a;
    struct weightToAttribute *y = (struct weightToAttribute *) b;

    if(*(const double *)&x->weight < *(const double *)&y->weight)
        return -1;
    return *(const double*)&x->weight > *(const double *)&y->weight;
}

int compare_function(const void *a,const void *b) {
    int *x = (int *) a;
    int *y = (int *) b;
    return *x - *y;
}

profile* handwrittenPresets(simulationPresets* preset){
    return parseProfile(preset, stdin);
}

char* choosePrefLibFile(simulationPresets* preset){
    char** addresses = calloc(1000, sizeof(char*));
    int i = 0;
    DIR* directory;
    struct dirent *dir;
    directory = opendir(preflibPath);
    if(directory) {
        while ((dir = readdir(directory)) != NULL) {
            addresses[i] = dir->d_name;
            i++;
        }

        char *filename = calloc(1, 1000);
        //fprintf(stdout, "Found %i preflib .soc files, choosing one randomly now.. ", i);
        int r = rand() % (i-1) +2;
        //fprintf(stdout, "Chose file at position %i, named %s.\n", r, addresses[r]);
        fprintf(preset->file, "%s\n", addresses[r]);
        fprintf(stdout, "%s\n", addresses[r]);
        strcpy(filename, preflibPath);
        strcat(filename, addresses[r]);

        free(addresses);
        free(dir);
        closedir(directory);

        return filename;

    }else{
        fprintf(stdout, "directory not found, ");
        return "";
    }
}

profile* preflibPresets(simulationPresets* preset){
    /*while(1) {
        int where;
        fprintf(stdout, "Which preflib profiles should be used? from bottom/from top/random (%i/%i/%i)\n", fromBottom, fromTop, fromRandom);
        scanf("%i", &where);
        if ((where == fromRandom) || (where == fromTop) || (where == fromBottom)){
            preset->fromWherePreflib = where;
            break;
        } else fprintf(stdout, "Invalid number, please try again.\n");
    }*/
    FILE* file;
    char* filename = choosePrefLibFile(preset);
    file = fopen(filename, "r");
    if(!file){
        fprintf(stdout, "could not open file\n");
        return NULL;
    }
    profile* profile = parseProfile(preset, file);
    fclose(file);
    free(filename);
    return profile;
}

void preSetup(simulationPresets* preset){
    if(preset->mode != handwritten){//if not automatically set, set as random preflib
        preset->mode = preflib;
    }

    inputAmountSims(&preset->amountSimulations);
    inputLandH(&preset->h, &preset->l);
    preset->rules = calloc(totalAmountRules, sizeof(int));
    inputRules(preset->rules, preset->amountSimulations);
    inputImplementation(&preset->automaticImplementationStart, &preset->automaticImplementationEnd, preset->l);

    if(preset->mode == handwritten){
        fprintf(preset->file, "n=%i,m=%i,simulations=%i,l=%i,h=%i\n", preset->amountAgents, preset->amountAttributes,
                preset->amountSimulations, preset->l, preset->h);
        fprintf(preset->file, "autoimplement:%i,%i", preset->automaticImplementationStart, preset->automaticImplementationEnd);
    }
}

profile* setup (simulationPresets* preset){
    if(openFile(&preset->file) == -1){
        return NULL;
    }

    profile* profile = NULL;

    fprintf(stdout, "\n_____________________________________\n");
    fprintf(stdout, "\n");
    fprintf(preset->file, "mode:p,");
    profile = preflibPresets(preset);
    if(!profile){
        fprintf(stderr, "Error initializing profile\n");
        return NULL;
    }
    //fprintf(stdout, "Profile created successfully\n");

    fprintf(preset->file, "n=%i,m=%i,simulations=%i,l=%i,h=%i\n", preset->amountAgents, preset->amountAttributes,
            preset->amountSimulations, preset->l, preset->h);
    fprintf(preset->file, "autoimplement:%i,%i", preset->automaticImplementationStart, preset->automaticImplementationEnd);
    return profile;
}

//declares and returns new ranking
ranking* setUpRanking(int l, int h){
    ranking* result = calloc(1, sizeof(ranking));
    result->r = calloc(1, sizeof(int)*l);
    result->tau = calloc(1, sizeof(int)*h);
    result->nR = 0;
    result->nTau = 0;
    return result;
}

//reads and creates agents from soc/soi file
void parseAgents(simulationPresets* preset, FILE* stream){
    char* agents = NULL;
    size_t len = 0;
    getline(&agents, &len, stream);
    len = strlen(agents);

    //iterate through until comma, saving every char into target.
    //then atoi the number and reposition (+1)
    int count = 0; //amount of finished inputs in source string
    int posCurr = 0; //position in the source string
    int posTotal = 0; //position in the target string
    do{
        posCurr = 0;
        char curr[11]; //number you currently want
        memset(curr, '\0', 11);
        while ((agents[posTotal] != ',') && (posTotal < len-1)){
            curr[posCurr] = agents[posTotal];
            posTotal++;
            posCurr++;
        }
        posTotal++; //advance 1 char in source string to skip the comma
        count++;
        switch (count) {
            case 1: preset->amountAgents = atoi(curr);
                fprintf(stdout, "%i agents and ", preset->amountAgents); break;
            case 2: break; //amount of total votes, does not matter to us
            case 3: preset->uniqueProfiles = atoi(curr);
                fprintf(stdout, "%i unique voting profiles.\n", preset->uniqueProfiles); break; //amount of unique profiles
        }//translate current number and move on
    } while (posTotal < len);

    free(agents);
    return;
}

//reads and creates attributes from soc/soi file
void parseAttributes(simulationPresets* preset, FILE* stream){
    char* attributes = NULL;
    size_t len = 0;
    getline(&attributes, &len, stream);
    len = strlen(attributes);
    preset->amountAttributes = atoi(attributes);

    fprintf(stdout, "%i attributes, ", preset->amountAttributes);

    for(int i = 0; i < preset->amountAttributes; i++){//discard all the lines that just state the attributes
        char* buffer = NULL;
        len = 0;
        getline(&buffer, &len, stream);
        free(buffer);
    }
    free(attributes);
    return;
}

//declares and returns new profile
profile* setupProfile(simulationPresets* preset){
    profile* input = calloc(1, sizeof(profile));
    input->approvedAttribute = calloc(preset->amountAgents+1, sizeof(int));
    //input->cutoffs = calloc(preset->amountAgents+1, sizeof(int));
    input->agents = preset->amountAgents;
    input->attributes = preset->amountAttributes;
    input->approvalScore = calloc(preset->amountAttributes+1, sizeof(int));
    input->amountRanked = calloc(preset->amountAttributes+1, sizeof(int));
    //input->alternativesByAttribute = calloc(1, sizeof(int*));
    //input->approves = calloc(1, sizeof(int)*preset->amountAgents+1);
    //input->isRanked = calloc(1, sizeof(int)* preset->amountAttributes);

    return input;
}

//line by line, fills attributes with voters
void fillProfile(simulationPresets* preset, profile* input, FILE* stream){
    int agentsTotal = 0;
    for(int i = 0; i < preset->uniqueProfiles; i++) {
        char* newSet = NULL;
        size_t len = 0;
        getline(&newSet, &len, stream);
        len = strlen(newSet);

        //fprintf(stdout, "%s", newSet);
        int posCurr = 0; //position in the source string
        int posTotal = 0; //position in the target string
        int agentsN = 0; //amount of agents voting with current profile

        do {
            posCurr = 0;
            char curr[11]; //number you currently want
            memset(curr, '\0', 11);
            while ((newSet[posTotal] != ',') && (posTotal < len-1)){ //if upcoming char is not eol or a comma, then save and move to next
                curr[posCurr] = newSet[posTotal];
                posTotal++;
                posCurr++;
            }
            posTotal++; //advance 1 char in source string to skip the comma
            if(agentsN == 0){//first number is the amount of agents voting with this profile
                agentsN = atoi(curr);
                if(agentsN == 0)
                    break;
            } else{
                int newAttr = atoi(curr)-1; //Attribute this chunk of voters belongs to
                for(int i = agentsTotal; i < agentsTotal+agentsN; i++){
                        input->approvedAttribute[i] = newAttr;
                        input->approvalScore[newAttr] ++;
                }
                break;
            }
        } while (posTotal < len);
        free(newSet);
        agentsTotal += agentsN;
    }
}

profile* parseProfile(simulationPresets* preset, FILE* stream){
    if(preset->mode != handwritten)
        parseAttributes(preset, stream);
    parseAgents(preset,stream);
    profile* input = setupProfile(preset);

    // for every line in the input, read the amount of votes, save it and add it to total voter amount
    // treat highest ranked alternative as attribute the entire chunk of voters is in favor of
    fillProfile(preset, input, stream);

    return input;
}

void freePreset(simulationPresets* preset){
    free(preset->rules);
    free(preset);
}
void freeEverything(profile* input, ranking* result, simulationPresets* preset){
    //for(int i = 0; i < input->attributes; i++){
    //    if(input->alternativesByAttribute[i])
    //        free(input->alternativesByAttribute[i]);
    //}
    free(input->approvedAttribute);
    //free(input->cutoffs);
    free(input->approvalScore);
    free(input->amountRanked);

    free(result->tau);
    free(result->r);
    free(result);
    free(input);

    fclose(preset->file);
}

int implementAlternative(simulationPresets* preset, ranking* result){

    //fprintf(stdout, "start: %i, end: %i\n", preset->automaticImplementationStart, preset->automaticImplementationEnd);

    int implement = -1;
    if(preset->automaticImplementationStart == -1) {
        printCurrentRanking(preset->file, result->tau, result->r, result->nTau, result->nR);
        fprintf(stdout, "\nWhich alternative do you want to implement? [rank or -1 to implement none]\n");
        char *choice = calloc(1, 10);
        int good = 0;
        while (good == 0) {
            scanf("%s", choice);
            if (atoi(choice) == -1) {
                return 1;
            } else if (((0 <= atoi(choice)) && (atoi(choice) < result->nR))) {
                good = 1;
            } else fprintf(stdout, "that didn't work, try again please.\n");
        }
        implement = atoi(choice);
        free(choice);
    } else if (preset->automaticImplementationStart != -1){//if automatic implementation

        if (preset->automaticImplementationStart == preset->automaticImplementationEnd){ //and the window is just one alternative wide
            //fprintf(stdout, "\nnR = %i\n", result->nR);
            if (preset->automaticImplementationEnd < result->nR){ //and the rank is not larger than size of r
                //fprintf(stdout, "\nAutomatically implementing the alternative at rank %i.\n",
                        //preset->automaticImplementationStart);
                implement = preset->automaticImplementationStart;
            } else { //if the alternative can't be implemented cause it is out of range of r, default to 0
                //fprintf(stdout, "\nSince r is shorter than %i, implementing the alternative at rank 0.\n", preset->automaticImplementationStart);
                implement = 0;}
        }
        else if (preset->automaticImplementationStart != preset->automaticImplementationEnd) { //if window is larger than 1 rank
            if (preset->automaticImplementationStart < result->nR) { //and the start of the window is still in range of r
                int range;
                if(result->nR < preset->automaticImplementationEnd) {
                    range = result->nR-1 - preset->automaticImplementationStart;
                } else {
                    range = preset->automaticImplementationEnd - preset->automaticImplementationStart;}
                //fprintf(stdout, "range:%i\n", range);
                implement = preset->automaticImplementationStart+(rand() %(range+1));
            } else { //if the alternative can't be implemented cause it is out of range of r, default to 0
                implement = 0; }
        }
    }
    result->tau[result->nTau] = result->r[implement];
    result->nTau++;
    fprintf(preset->file, "i:%i\n"
                          "=============\n", result->r[implement]);
    return 0;
}

profile* checkIfHandwritten(simulationPresets* preset){
    //get first line from stdin, if it's non-empty set mode to handwritten and parse amountattributes
    if(!isatty(fileno(stdin))) {
        char *attributes = NULL;
        size_t len = 0;
        getline(&attributes, &len, stdin);
        len = strlen(attributes);
        if (len > 1) {
            preset->amountAttributes = atoi(attributes);

            for (int i = 0;
                 i < preset->amountAttributes; i++) {//discard all the lines that just state the attributes
                char *buffer = NULL;
                len = 0;
                getline(&buffer, &len, stdin);
                free(buffer);
            }
            preset->mode = handwritten;
        }
        free(attributes);

        if(openFile(&preset->file) == -1){
            return NULL;
        }
        profile* profile = NULL;
        fprintf(preset->file, "mode:h\n");
        profile = handwrittenPresets(preset);
        freopen("/dev/tty", "r", stdin);
        return profile;
    }
}

void refreshResults (ranking* results, profile* input){
    for(int i = 0; i < input->attributes; i++){
        input->amountRanked[i] = 0;
    }

    for(int i = 0; i < results->nR; i++){
        results->r[i] = 0;
    }
    results->nR = 0;

    for(int i = 0; i < results->nTau; i ++){
        input->amountRanked[results->tau[i]]++;
    }
}

void resetResults (ranking* results, profile* input, simulationPresets* preset){
    for(int i = 0; i < preset->h; i++) {
        results->tau[i] = 0;
    }
    for (int i = 0; i < preset->l; ++i) {
        results->r[i] = 0;
    }
    results->nR = 0;
    results->nTau = 0;
    for(int i = 0; i < input->attributes; i++){
        input->amountRanked[i] = 0;
    }
}

int digits(int x){
    return floor(log10 (abs(x))) + 1;
}

void printProfile(profile* input, simulationPresets* preset){
    int dig = digits(input->attributes);
    for(int i = 0; i < input->attributes; i++){
        fprintf(preset->file, "a%i:", i);
        int digI = digits(i);
        if(i == 0)
            digI = 1;
        for(int d = 0; d < (dig-digI+1); d++){
            fprintf(preset->file, " ");
        }
        fprintf(preset->file, "%i", input->approvalScore[i]);
        fprintf(preset->file, "\n");
    }
}

