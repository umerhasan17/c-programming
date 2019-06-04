#include <stdio.h>
#include <comip.h>
#include <assert.h>

char *createCommand(size_t size) {
    printf("Creating command\n");
    char* str[size];
    return str;
}

char **createCommands(int n) {
    char *array[n];
    memset(array, NULL, n*sizeof(char*));
    return array;
}

char *getCommand(size_t size) {
    char* word = createCommand(size);
    printf("Command returned\n");
    int n = strlen(word);
    if (n>0 && word[n-1]=='\n') { word[n-1] = 0; }
    printf("> ");
    fgets(word, size, stdin);
    return word;
}

char **getCommands(int n, size_t size) {
    printf("Creating commands\n");
    char** array = createCommands(n);
    printf("Getting commands\n");
    for (int i = 0; i < n; i ++) {
        printf("Get command %d\n", i);
        array[i] = getCommand(size);
    }
    return array;
}

void printCommands(char **commands, int n) {
    for (int i = 0; i < n; i ++) {
        printf("> %s\n", commands[i]);
    }
}

void freeCommands(char **commands, int n) {
    for (int i = 0; i < n; i ++) {
        free(&commands[i]);
    }
}

int main(int argc, char **argv) {
    assert(argc > 2);
    int number = strtol(argv[1], &argv[1], 10);
    int size = strtol(argv[2], &argv[2], 10);
    assert(size >= 50);
    printf("Getting commands\n");
    char** commands = getCommands(number, size);
    printf("Printing commands\n");
    printCommands(commands, number);
    printf("Freeing commands\n");
    freeCommands(commands, number);
    printf("Done!\n");
    return 0;
}