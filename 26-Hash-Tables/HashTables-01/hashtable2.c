#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct
{
    char name[MAX_NAME];
    int age;
    //...add other stuff later, maybe
} person;

person * hash_table[TABLE_SIZE];

unsigned int hash(char *name) //Hash function
{
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i=0; i < length; i++)
    {
        hash_value += name[i];
        // This insures that the numbers land between 0 and Table size - 1
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void init_hash_table()
{
    for(int i=0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
    // table is empty
}

void print_table()
{
    printf("Start\n");
    for(int i=0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i] == NULL)
        {
            printf("\t%i\t---\n", i);
        }
        else
        {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
    printf("End\n");
}

bool hash_table_insert(person *p)
{
    if (p == NULL) return false;
    int index = hash(p->name);
    if (hash_table[index] != NULL) 
    {
        return false;
    }
    hash_table[index] = p;
    return true;
}

int main()
{
    init_hash_table();
    print_table();

    person jacob = {.name="Jacob", .age=256"};
    person kate = {.name="kate", .age=27"}; 
    person mpho = {.name="mpho", .age=14"};


    printf("Jacob => %u\n", hash("Jacob"));
    printf("Natalie => %u\n", hash("Natalie"));
    printf("Sara => %u\n", hash("Sara"));
    printf("Mpho => %u\n", hash("Mpho"));
    printf("Tebogo => %u\n", hash("Tebogo"));
    printf("Ron => %u\n", hash("Ron"));
    printf("Jane => %u\n", hash("Jane"));
    printf("Maren => %u\n", hash("Maren"));
    printf("Bill => %u\n", hash("Bill"));
    return 0;
}