//
// Created by paula on 22.04.20.
//

#ifndef DYNAMICRANKINGS_SETTING_H
#define DYNAMICRANKINGS_SETTING_H


typedef struct _profile {
    int agents;
    int attributes;
    int** alternativesByAttribute; //[attribute][list of alternatives]
    int* approvedAttribute; //[voter]->[exactly 1 attribute]
    int* cutoffs;   //voter-specific (approx.) normally distributed cutoffs; used for converting .soc preferences to approval based
    //int** voters;       //[alternatives][voters]
    //int* approves; //amount of approved alternatives for voter i (dated)
    int* approvalScore; //approval score of an attribute
    int* amountRanked; //amount of candidates from given attribute that are ranked in either tau or r

}profile;

typedef struct _ranking {
    int* r;
    int* tau;
    int nR;
    int nTau;
}ranking;

struct weightToAttribute {
    double weight;
    int attribute;
};

typedef struct _simulationPresets {
    int mode; //handwritten/preflib; see definitions up top
    int uniqueProfiles; //mostly relevant for reading from .soi files
    int amountAgents;
    int amountAttributes;
    int automaticImplementationStart;
    int automaticImplementationEnd;
    int amountSimulations;
    int fromWherePreflib;
    int* rules; //for each iteration, save the rule you want to use
    FILE* file;//fp for output creation
    FILE* inputFile;// fp for piped-in input
    int h; //max len of tau
    int l; //max len of r
}simulationPresets;

int compare_weightToAttribute (const void *a,const void *b);

void preSetup(simulationPresets* preset);
profile* setup (simulationPresets* preset);
ranking* setUpRanking(int l, int h);

void freeEverything(profile* input, ranking* result, simulationPresets* preset);
void freePreset(simulationPresets* preset);

int implementAlternative(simulationPresets* preset, ranking* result);
void refreshResults (ranking* results, profile* input);
void resetResults (ranking* results, profile* input, simulationPresets* preset);
int compare_function(const void *a,const void *b);
profile* checkIfHandwritten(simulationPresets* preset);
void printProfile(profile* input, simulationPresets* preset);

int approvalCutoff(int amountAlternatives);

#endif //DYNAMICRANKINGS_SETTING_H
