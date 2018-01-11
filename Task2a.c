//
// Created by Anastasia on 03/01/2018.
//

#include <stdio.h>
#include <string.h>

struct pair
{
    char key[200];
    char value[200];
};

struct pair hash_table[5][5];

int set_hash()
{

    for (int j=0; j<=5; j++)
    {
        for (int k=0; k<=5; k++)
        {
            strcpy(hash_table[j][k].key, "EMPTY");
        }
    }
    return 0;
};


int hashfunction(char key[])
{
    int total = 0;
    for (int i = 0; i < strlen(key); i++)
    {

        total =+ key[i];

    }
    return total % 5;
}

void main() {
    static char greeting[10][10] = {
            "hello",
            "hi",
            "bongu",
            "bonjour",
            "bonsoir"

    };
    static char name[10][10] = {
            "Ana",
            "Andrew",
            "Randy",
            "Sean",
            "Giulia"

    };

    set_hash();

        int i = 0;
        for (i = 0; i <= 5; i++) {
            int hash = hashfunction(greeting[i]);
            printf("hash is %d \n",hash);

            int t = 0;

            while (t <= 5) {

                if (strcmp(hash_table[hash][t].key, "EMPTY") == 0)
                {
                    printf("contents of has table key is :  ");
                    printf(hash_table[hash][t].key);
                    printf ("\n");
                    strcpy(hash_table[hash][t].value, name [i]);
                    strcpy(hash_table[hash][t].key, greeting[i]);
                    printf(hash_table[hash][t].key);
                    printf("\n");
                    printf(hash_table[hash][t].value);
                    printf("\n");
                    printf("value of t is %d \n",t);
                    t = 6;
                } else {
                    t++;
                    printf("not empty t is %d \n",t);
                }
            }
        }
    }


