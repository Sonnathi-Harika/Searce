
// Online IDE - Code Editor, Compiler, Interpreter

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include<stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct {
    char name[MAX_NAME];
    int age;
}person;

unsigned int hash(char *name){
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for(int i=0; i<length; i++){
        hash_value+=name[i];
        hash_value = (hash_value*name[i])%TABLE_SIZE;
    }
    return hash_value;
}

int main()
{
    printf("Tim=>%u\n",hash("Tim"));
    printf("Bea=>%u\n",hash("Bea"));
    printf("Len=>%u\n",hash("Len"));
    printf("Moe=>%u\n",hash("Moe"));
    printf("Zoe=>%u\n",hash("Zoe"));
    printf("Sue=>%u\n",hash("Sue"));
    printf("Lou=>%u\n",hash("Lou"));
    printf("Rae=>%u\n",hash("Rae"));
    printf("Max=>%u\n",hash("Max"));
    printf("Tod=>%u\n",hash("Tod"));
    return 0;
}
