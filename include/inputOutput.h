//
// Created by paula on 16.10.20.
//

#ifndef DYNAMICRANKINGS_INPUTOUTPUT_H
#define DYNAMICRANKINGS_INPUTOUTPUT_H

#define handwritten 1
#define preflib 2

#define allRules "Dynamic D'Hondt, Lazy D'Hondt"
#define totalAmountRules 2
#define ddhondt 1
#define lazydhond 2

#define fromTop 1
#define fromBottom 2
#define fromRandom 3

#include <stdio.h>

void inputAmountSims(int* target);
void inputLandH (int* target1, int* target2);
void inputRules(int* target, int amountSims);
void inputImplementation(int* targetStart, int* targetEnd, int amountAlternatives);

void printCurrentRanking(FILE* fp, int* tau, int* r, int nTau, int nR);

int openFile(FILE** fp); //opens file and saves filepointer in fp, returns -1 on error

#endif //DYNAMICRANKINGS_INPUTOUTPUT_H
