#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int min;
    int max;
    char letter;
    char password[64];
} PasswordData;

typedef struct
{
    int length;
    PasswordData * inputs;
} InputData;

InputData
readInput()
{
    FILE * inputFile = fopen("Input.txt", "r");
    char line[256];
    PasswordData * values = malloc(sizeof(PasswordData) * 1001);
    int counter = 0;
    InputData result;

    if (inputFile != NULL)
    {
        while (fgets(line, sizeof(line), inputFile))
        {
            int min;
            int max;
            char letter;
            char password[64];

            sscanf(line, "%i-%i %c: %s", &min, &max, &letter, password);

            // printf("Min: %i, Max: %i, Letter: %c, Password: %s\n", min, max, letter, password);

            PasswordData value;
            value.min = min;
            value.max = max;
            value.letter = letter;
            strncpy(value.password, password, 64);

            values[counter] = value;
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
    result.inputs = values;
    return result;
}

int
main()
{
    InputData inputData = readInput();
    PasswordData * data = inputData.inputs;

    // * Part 1
    int rightPasswords = 0;
    for (int i = 0; i < inputData.length; i++)
    {
        // printf("Min: %i, Max: %i, Letter: %c, Password: %s\n", data[i].min, data[i].max, data[i].letter,
        // data[i].password);

        int letterCounter = 0;
        char * pw = data[i].password;
        for (int j = 0; j < strlen(pw); j++)
        {
            if (pw[j] == data[i].letter)
            {
                letterCounter++;
            }
        }

        // printf("Letter counter: %i\n", letterCounter);

        if (letterCounter <= data[i].max && letterCounter >= data[i].min)
        {
            rightPasswords++;
        }
    }
    printf("Part 1: %i\n", rightPasswords);

    // * Part 2
    int rightPasswords2 = 0;
    for (int i = 0; i < inputData.length; i++)
    {
        // printf("Min: %i, Max: %i, Letter: %c, Password: %s\n", data[i].min, data[i].max, data[i].letter,
        // data[i].password);

        char char1 = data[i].password[data[i].min - 1];
        char char2 = data[i].password[data[i].max - 1];

        if (char1 != char2 && (char1 == data[i].letter || char2 == data[i].letter))
        {
            rightPasswords2++;
        }

        // printf("Char1: %c, Char2: %c, Letter: %c\n", char1, char2, data[i].letter);
    }
    printf("Part 2: %i\n", rightPasswords2);

    free(inputData.inputs);
}
