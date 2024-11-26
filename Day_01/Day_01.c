#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int length;
    int * inputs;
} InputData;

InputData
readInput()
{
    FILE * inputFile = fopen("Input.txt", "r");
    char line[256];
    int * values = malloc(sizeof(int) * 1000);
    int counter = 0;
    InputData result;

    if (inputFile != NULL)
    {
        while (fgets(line, sizeof(line), inputFile))
        {
            values[counter] = atoi(line);
            counter++;
        }
        fclose(inputFile);
        result.length = counter;
        result.inputs = values;
    }
    else
    {
        fprintf(stderr, "Unable to open!\n");
    }

    return result;
}

int
main()
{
    InputData inputData = readInput();

    for (int i = 0; i < inputData.length; i++)
    {
        for (int j = i + 1; j < inputData.length; j++)
        {
            if (inputData.inputs[i] + inputData.inputs[j] == 2020)
            {
                printf("Result Part 1: %i\n", inputData.inputs[i] * inputData.inputs[j]);
            }
        }
    }

    for (int i = 0; i < inputData.length; i++)
    {
        for (int j = i + 1; j < inputData.length; j++)
        {
            for (int k = j + 1; k < inputData.length; k++)
            {
                if (inputData.inputs[i] + inputData.inputs[j] + inputData.inputs[k] == 2020)
                {
                    printf("Result Part 2: %i\n", inputData.inputs[i] * inputData.inputs[j] * inputData.inputs[k]);
                }
            }
        }
    }

    free(inputData.inputs);
}
