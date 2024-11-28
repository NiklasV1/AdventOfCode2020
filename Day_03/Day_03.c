#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int length;
    char ** inputs;
} InputData;

InputData
readInput()
{
    FILE * inputFile = fopen("Input.txt", "r");
    char line[256];

    char ** inputs = malloc(sizeof(char *) * 1001);
    int counter = 0;
    InputData result;

    if (inputFile != NULL)
    {
        while (fgets(line, sizeof(line), inputFile))
        {
            char * input = malloc(sizeof(char) * 256);

            sscanf(line, "%s", input);

            inputs[counter] = input;
            counter++;
        }
        fclose(inputFile);
        printf("Total values: %i\n", counter);
    }
    else
    {
        fprintf(stderr, "Unable to open!\n");
    }
    result.length = counter;
    result.inputs = inputs;
    return result;
}

int
evaluateSlope(char ** inputs, int inputLength, int right, int down)
{
    int treeCounter = 0;
    int xPos = 0;

    for (int yPos = 0; yPos < inputLength; yPos += down)
    {
        if (inputs[yPos][xPos] == '#')
        {
            treeCounter++;
        }
        xPos = (xPos + right) % strlen(inputs[0]);
    }
    return treeCounter;
}

int
main()
{
    InputData inputData = readInput();

    // * Part 1
    int result1 = evaluateSlope(inputData.inputs, inputData.length, 3, 1);
    printf("Part 1: %i\n", result1);

    // * Part 2

    int slope1 = evaluateSlope(inputData.inputs, inputData.length, 1, 1);
    int slope2 = evaluateSlope(inputData.inputs, inputData.length, 3, 1);
    int slope3 = evaluateSlope(inputData.inputs, inputData.length, 5, 1);
    int slope4 = evaluateSlope(inputData.inputs, inputData.length, 7, 1);
    int slope5 = evaluateSlope(inputData.inputs, inputData.length, 1, 2);

    int result2 = slope1 * slope2 * slope3 * slope4 * slope5;

    printf("Part 2: %i\n", result2);

    free(inputData.inputs);
}
