#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/rules/dynDHondt.h"
#include "include/rules/lazyDHondt.h"
#include "include/setting.h"
#include "include/inputOutput.h"


int main(int argc, char* argv[]) {
    if (argc > 2) {//+1 because of standard input
        fprintf(stderr, "Invalid number of arguments, expected 0 or 1, it is %i. Look at README for further help.\n", argc-1);
        return -1;
    }
    simulationPresets* preset = calloc(1, sizeof(simulationPresets));
    profile* input = checkIfHandwritten(preset);
    preSetup(preset);
    srand(time(NULL));

    int total = 0;
    for(int i = 1; i <= totalAmountRules; i++) {
        for(int j = 0; j < preset->rules[i-1]; j++) {

            //profile *input;
            ranking *result;

            if(preset->mode != handwritten)
                input = setup(preset);
            if (!input) {
                fprintf(stderr, "Something went wrong, program crashed.\n");
                if (preset->file) {
                    fprintf(preset->file, "\n========================================="
                                          "\n There was an error, simulation stopped."
                                          "\n=========================================");
                    fclose(preset->file);
                }
                return -1;
            }
            result = setUpRanking(preset->l, preset->h);

            fprintf(preset->file, "\n\n%i.", total + 1);
            total++;
            fprintf(stdout, "\nRun number %i\n", total);
            resetResults(result, input, preset);
            switch (i) {
                case ddhondt:
                    dynDHondt(input, result, preset);
                    break;
                case lazydhond:
                    lazyDHondt(input, result, preset);
                    break;
                default:
                    fprintf(stderr, "Wrong Ranking Rule parameter, was %i. Look at README for further help.\n",
                            i);
                    fprintf(preset->file, "\n========================================="
                                          "\n There was an error, simulation stopped."
                                          "\n=========================================");
                    fclose(preset->file);
                    return -1;
            }
            printProfile(input, preset);
            freeEverything(input, result, preset);
        }
    }
    freePreset(preset);
    return 0;
}