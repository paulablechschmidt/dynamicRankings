//
// Created by paula on 16.10.20.
//

#include "inputOutput.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>


void format_time(char *output){
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    sprintf(output, "%d-%d-%d--%d-%d-%d",timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
}


void inputAmountAlternatives(int* target){
    while(1) {
        int alternatives;
        fprintf(stdout, "How many alternatives should the profile have? (enter natural number)\n");
        scanf("%i", &alternatives);
        if ((alternatives > 0) && alternatives < INT_MAX) {
            *target = alternatives;
            break;
        } else fprintf(stdout, "Invalid number, please try again.\n");
    }
}
void inputAmountAgents(int* target){
    while(1) {
        int agents;
        fprintf(stdout, "How many agents should the profile have? (enter natural number)\n");
        scanf("%i", &agents);
        if ((agents > 0) && agents < INT_MAX) {
            *target = agents;
            break;
        } else fprintf(stdout, "Invalid number, please try again.\n");
    }
}

void inputAmountSims(int* target){
    while(1) {
        int amountSims;
        fprintf(stdout, "How many simulations do you want to run? (enter a number)\n");
        scanf("%i", &amountSims);
        if ((amountSims > 0) && amountSims < INT_MAX) {
            *target = amountSims;
            break;
        } else fprintf(stdout, "Invalid number, please try again.\n");
    }
}

void inputLandH (int* target1, int* target2){
    while(1){
        int h;
        fprintf(stdout, "Until which length of tau (h) should be iterated? (enter a number)\n");
        scanf("%i", &h);
        if ((h > 0) && h < INT_MAX) {
            *target1 = h;
            break;
        } else fprintf(stdout, "Invalid number, please try again.\n");
    }
    while(1){
        int l;
        fprintf(stdout, "Until which length of r (l) should be ranked? (enter a number)\n");
        scanf("%i", &l);
        if ((l > 0) && l < INT_MAX) {
            *target2 = l;
            break;
        } else fprintf(stdout, "Invalid number, please try again.\n");
    }
}

void inputRules(int* target, int amountSims){
    while(1) {
        int rules[totalAmountRules];
        int sum = 0;
        fprintf(stdout, "How often should each rule be used? [0:Dynamic D'Hondt./1:Lazy D'Hondt]\n(enter %i natural numbers, sum equaling %i)\n",
                totalAmountRules, amountSims);
        for(int i = 0; i < totalAmountRules; i++) {
            fprintf(stdout, "%i:", i);
            scanf("%i", &rules[i]);
            if(rules[i] < 0){
                fprintf(stdout, "Negative numbers are invalid, please try again.\n");
                break;
            }
            sum += rules[i];
            if(sum > amountSims){
                //fprintf(stdout, "Sum too large, please try again.\n");
                break;
            }
        }
        if (sum == amountSims) {
            for(int j = 0; j < totalAmountRules; j++) {
                target[j] = rules[j];} break;
        } else fprintf(stdout, "Sum too small/large, should be %i, but is %i. Please try again.\n", amountSims, sum);
    }
}
void inputImplementation(int* targetStart, int* targetEnd, int amountAlternatives){
    while(1) {
        int autoImplement;
        fprintf(stdout, "From which interval should the automatic implementation randomly choose?\nPlease enter the higher rank [0 to %i] (-1 for manual implementation)",
                amountAlternatives);
        scanf("%i", &autoImplement);
        if ((autoImplement >= 0) && autoImplement <= amountAlternatives) {
            *targetStart = autoImplement;
        } else if(autoImplement == -1){
            *targetStart = -1;
            break;
        } else {
            fprintf(stdout, "Invalid number, please try again.\n");
        }

        fprintf(stdout, "Now please enter the lower rank [%i to %i]", *targetStart, amountAlternatives);
        scanf("%i", &autoImplement);
        if ((autoImplement >= *targetStart) && autoImplement <= amountAlternatives) {
            *targetEnd = autoImplement;
            break;
        } else fprintf(stdout, "Invalid number, please try again.\n");
    }
}

void printCurrentRanking(FILE* fp, int* tau, int* r, int nTau, int nR){
    fprintf(stdout, "\nThis is the current ranking:\n");
    fprintf(stdout, "t:\n");
    fprintf(fp, "t:");
    for(int i = 0; i < nTau; i++){
        fprintf(stdout, "%i.: n%i\n", i, tau[i]);
        fprintf(fp, "%i", tau[i]);
        if(i != nTau-1){
            fprintf(fp, ",");
        }
    }
    fprintf(fp, "\n");
    fprintf(stdout, "r:\n");
    fprintf(fp, "r:");
    for(int i = 0; i < nR; i++){
        fprintf(stdout, "%i.: n%i\n", i, r[i]);
        fprintf(fp, "%i", r[i]);
        if(i != nR-1){
            fprintf(fp, ",");
        }
    }
    fprintf(fp, "\n");
}

int openFile(FILE** fp){
    char* time = calloc(1, 40);
    format_time(time);
    char* filename = calloc(1, 36);
    strcpy(filename, "./results/");
    strcat(filename, time);

    *fp = fopen(filename, "w");

    if(!*fp){
        fprintf(stderr, "Couldn't open file \"%s\". Try creating a directory named \"/results\".\n", filename);
        free(filename);
        free(time);
        return  -1;
    }
    free(filename);
    free(time);
    return 0;
}