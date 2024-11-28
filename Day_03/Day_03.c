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
main()
{
    InputData inputData = readInput();
    
    // * Part 1
    int treeCounter = 0;
    int xPos = 0;

    for (int yPos = 0; yPos < inputData.length; yPos++)
    {
        if (inputData.inputs[yPos][xPos] == '#')
        {
            treeCounter++;
        }
        xPos = (xPos + 3) % strlen(inputData.inputs[0]);
    }
    printf("Part 1: %i", treeCounter);
    

    free(inputData.inputs);
}
