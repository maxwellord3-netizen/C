#include <stdio.h>

int main() {
    int scores[2][2] = {
        {65, 92},
        {35, 70}
    };

    // Printing the array using a nested for loop
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", scores[i][j]);
        }
        printf("\n"); // Move to the next line after each row
    }

    return 0;
}