#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numbertoguess, userguess;
    int attempts = 0;

    srand(time(0));

    numbertoguess = rand() % 100 + 1;

    printf("Welcome to the Guess the Number game!\n");
    printf("I'm thinking of a number between 1 and 100.\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &userguess);
        attempts++;
        
	if	(userguess!=numbertoguess) {
            printf("Try again.\n");
        }
	 else {
            printf("Congratulations! You guessed the number %d in %d attempts.\n", numbertoguess, attempts);
        }
    } while (userguess!=numbertoguess);

    return 0;
}
