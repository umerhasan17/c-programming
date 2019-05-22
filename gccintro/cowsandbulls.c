#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define SIZE 4

int * readGuess(void) {
    int *guess[SIZE];
    for (int i = 0; i < SIZE; i ++) {
        printf("Enter element %i", i + 1);
        scanf("%d", guess[i]);
    }
    return guess;
} 

int blackScore(char guess[SIZE], char code[SIZE]) {
    int count = 0;
    for (int i = 0; i < SIZE; i ++) {
        if (guess[i] == code[i]) {
            count ++;
        }
    }
    return count;
}

int whiteScore(char guess[SIZE], char code[SIZE]) {
    int count = 0;
    for (int i = 0; i < SIZE; i ++) {
        for (int j = 0; j < SIZE; j ++) {
            if (guess[i] == code[j]) {
                count ++;
            }
        }
    }
    count = count - blackScore(guess, code);
    return count;
}

void printScore(char guess[SIZE], char code[SIZE]) {
    printf("(%d, %d)", blackScore(guess, code), whiteScore(guess, code));
}

bool anotherGame(void) {
    char ans;
    printf("Would you like to play another game?");
    scanf("%c", &ans);
    if (toupper(ans) == 'Y') {
        return true;
    } else {
        return false;
    }
}

int main(void) {
    while (true) {
        int code[SIZE] = {1, 8, 9, 2};
        int guess[SIZE] = readGuess();
        while (blackScore(guess, code) != SIZE) {
            printScore(guess, code);
            guess[SIZE] = readGuess();
        }

        printf("Well done, you have guessed correctly!");
        bool another = anotherGame();
        if (!another) {
            break;
        }
    }
}