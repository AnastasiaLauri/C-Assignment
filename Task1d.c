#include <stdio.h>

char beforeSpace(char mistake[153], int c);
char missingSpace(int t, const char lineToBeCorrected[]);
char afterSpace(char mistake[153], int c);



int main() {

    FILE *fp;                                //A pointer was allocated to the file used
    fp = fopen("Textfile for 1d).txt", "r"); //The file was opened and read

    int position = ftell(fp);
    fseek(fp, 0, SEEK_END);
    const int length = ftell(fp);
    fseek(fp, position, SEEK_SET);

    char line[length], character;
    int i = 0;
    fread(line, (size_t) length, 1, fp);
    line[length] = '\0';


    if (fp == NULL)   ///if the pointer points to nothing then output to the uder that there is no file
    {
        printf("ERROR in opening file.");
        return 0;
    }


    int lettercounter = 0;
    while (i < length) {

        character = line[i];
        if (character != ' ')
        {
            lettercounter++;
            i++;

            if (lettercounter >= 12)

            {
                missingSpace(i, line);
                lettercounter = 0;
            }
        }
        else
        {
            lettercounter = 0;
            if (line[i + 1] == ' ')
            {
              afterSpace(line, i+1);

            }
            else if (line[i + 1] == ',' || line[i + 1] == '.')
            {
                beforeSpace(line, i);

            }
            else
                i++;

        }
    }
    printf("\n%s",line);
}


    char afterSpace(char mistake[40], int c)
    {
        for (int j = c; j<40; j++)
        {
            mistake[j]= mistake [j+1];
        }
        return *mistake;
    }

char beforeSpace(char mistake[153], int c)
{
    for (int j = c; j<153; j++)
    {
        mistake[j]= mistake [j+1];
    }
    return *mistake;
}

    char missingSpace(int t, const char lineToBeCorrected[])
    {
        int long_word = t-12;
        char c;
        int i = 0;
        c = lineToBeCorrected[long_word];
        while(c >= 65 && c <= 96 || c >= 97 && c <= 122){
            i++;
            printf("%c", c);
            c = lineToBeCorrected[long_word + i];
        }
        printf("\n");
        printf("This word is more than 12 letters long. Please check if there are any missing spaces.");
    }