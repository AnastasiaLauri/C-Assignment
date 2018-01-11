//
// Created by Anastasia on 11/01/2018.
//


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pair     //creating a struct to store the key and value pairs
{
    char *key;         //pointer to the inputted key
    char *value;       //pointer to the inputted value
}Pair;

typedef struct row      //creating a struct for the columns in which the collision of pairs will be inputted
{
   Pair ** pair;        //pointer to key and value pair
    int row_length;     //maximum number of columns allowed
}Row;

typedef struct hashtable //creating a struct to store the hash table (including all the columns and rows)
{
    Row ** row;           //pointer to the row
    int sizeofHashTable; //size of hash table
}HashTable;


HashTable* initialisingHashTable(int size)          //initialising of hash table and setting the needed space for the hash table
{
    HashTable *hashTable = calloc(1,sizeof(hashTable)); //sets the space needed for the hash table
    hashTable->row= calloc(size, sizeof(Row));          //sets the space needed for each row which is equal to the space needed for the hash table ?
    hashTable->sizeofHashTable = size;                  //stores the space needed for the hash Table in hashTable

    return  hashTable;
}

int hashfunction(char key[], HashTable *hashTable)
    {
        int total = 0;                               //variable set to store sum of ASCII code of characters
        int length = hashTable->sizeofHashTable;     //variable length is used to store the size of the hash table
        for (int i = 0; i < strlen(key); i++)
        {

            total =+ key[i];                        //the value of the total obtained is added to the key[i] each time the i is incremented
                                                    //until the i reaches the length of the key.

        }
        return total % length;                      //the function returns the modulus of the total divided by the length (size of
                                                    //the hash table)
    }




int insertPair(HashTable * hashTable, char * key, char * value){

    int hashValue = hashfunction(hashTable,key); //calculate hashValue

    if(hashTable->row[hashValue]==NULL){//if bucket doesnt exist

        hashTable->row[hashValue] = malloc(sizeof(row)); //allocate mem for new bucket

        if (hashTable->row[hashValue] == NULL) { //error check
            printf("Failed to allocate memory for new bucket at hashValue: %d.",hashValue);
            return 1;//fail
        }

        hashTable->bucket[hashValue]->max_c = INITIAL_MAX_C; //max collisions set initially to 3
        hashTable->bucket[hashValue]->pair = calloc(INITIAL_MAX_C, sizeof(Pair)); //allocate mem for three pairs in bucket









void hash_length()
{

    char *original_length = malloc(50);
    char *new_length = NULL;
    new_length = realloc( sizeof(int) );
    original_length = new_length;
}


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


