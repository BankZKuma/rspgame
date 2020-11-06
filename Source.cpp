#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// input
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
char playerShape() {
    char shape;
    printf("[r]ock, [p]aper, [s]cissors, [q]uit :");
    scanf_s(" %c", &shape);
    return tolower(shape);
}

char computerShape() {
    char s[] = { 'r', 'p', 's' };
    int a = rand() % 3;
    int b = rand() % 2;
    swap(&b,&a);
    return s[a];
}

int main() {
    // seed number
    srand(time(NULL));

    char player, computer;
    player = playerShape();
    while (player != 'q') {
        computer = computerShape();
        printf("player -> %c, computer -> %c: ", player, computer);
        if (player == computer) {
            printf("tie.\n");
        }
        else {
            if ((player == 'r' && computer == 's') ||
                (player == 'p' && computer == 'r') ||
                (player == 's' && computer == 'p')) {
                printf("you won.\n");
            }
            else {
                printf("you lose.\n");
            }
        }
        player = playerShape();
    }
}