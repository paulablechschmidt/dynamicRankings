//
// Created by paula on 04.05.20.
//

#ifndef DYNAMICRANKINGS_DYNWSEQPAV_H
#define DYNAMICRANKINGS_DYNWSEQPAV_H

#include "../setting.h"

typedef struct _pattern {
    int patternLen;
    int patternbegin;
}pattern;

void dynDHondt(profile* input, ranking* result, simulationPresets* preset);

#endif //DYNAMICRANKINGS_DYNWSEQPAV_H