#include <stdio.h>

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int sum = 0;
    int arraySize = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < arraySize; ++i) {
        sum += numbers[i];
    }

    double average = (double) sum / arraySize;
    printf("Sum: %d\n", sum);
    printf("Average %.2f\n", average);
    return 0;
}
