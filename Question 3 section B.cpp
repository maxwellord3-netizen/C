#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void writeIntegersToFile();
void processIntegers();
void displayFiles();

int main() {
    writeIntegersToFile();
    processIntegers();
    displayFiles();
    return 0;
}

// Function 1: Prompt user for 10 integers and store in input.txt
void writeIntegersToFile() {
    FILE *fptr;
    int num, i;

    fptr = fopen("input.txt", "w");
    if (fptr == NULL) {
        printf("Error opening input.txt for writing.\n");
        exit(1);
    }

    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++) {
        printf("Enter integer %d: ", i + 1);
        scanf("%d", &num);
        fprintf(fptr, "%d\n", num);
    }

    fclose(fptr);
    printf("\nNumbers successfully written to input.txt.\n\n");
}

// Function 2: Read integers, calculate sum & average, write to output.txt
void processIntegers() {
    FILE *fptr_in, *fptr_out;
    int num, count = 0, sum = 0;
    float avg;

    fptr_in = fopen("input.txt", "r");
    if (fptr_in == NULL) {
        printf("Error opening input.txt for reading.\n");
        exit(1);
    }

    while (fscanf(fptr_in, "%d", &num) == 1) {
        sum += num;
        count++;
    }
    fclose(fptr_in);

    if (count == 0) {
        printf("No numbers found in input.txt.\n");
        exit(1);
    }

    avg = (float)sum / count;

    fptr_out = fopen("output.txt", "w");
    if (fptr_out == NULL) {
        printf("Error opening output.txt for writing.\n");
        exit(1);
    }

    fprintf(fptr_out, "Sum = %d\n", sum);
    fprintf(fptr_out, "Average = %.2f\n", avg);

    fclose(fptr_out);
    printf("Sum and average written to output.txt.\n\n");
}

// Function 3: Display contents of both files
void displayFiles() {
    FILE *fptr;
    char ch;

    printf("Contents of input.txt:\n");
    fptr = fopen("input.txt", "r");
    if (fptr == NULL) {
        printf("Error opening input.txt for display.\n");
        exit(1);
    }
    while ((ch = fgetc(fptr)) != EOF)
        putchar(ch);
    fclose(fptr);

    printf("\nContents of output.txt:\n");
    fptr = fopen("output.txt", "r");
    if (fptr == NULL) {
        printf("Error opening output.txt for display.\n");
        exit(1);
    }
    while ((ch = fgetc(fptr)) != EOF)
        putchar(ch);
    fclose(fptr);
}