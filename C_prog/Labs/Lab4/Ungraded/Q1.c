#include <stdio.h>
#include <stdbool.h>

bool uniqueOccurrences(int* arr, int arrSize) {
    for (int i = 0; i < arrSize - 1; i++) {
        for (int j = 0; j < arrSize - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int counts[1000];
    int idx = 0;

    for (int i = 0; i < arrSize; i++) {
        int c = 1;
        while (i + 1 < arrSize && arr[i] == arr[i + 1]) {
            c++;
            i++;
        }
        counts[idx++] = c;
    }

    for (int i = 0; i < idx - 1; i++) {
        for (int j = 0; j < idx - i - 1; j++) {
            if (counts[j] > counts[j + 1]) {
                int temp = counts[j];
                counts[j] = counts[j + 1];
                counts[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < idx - 1; i++) {
        if (counts[i] == counts[i + 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    int arr[] = {1, 2, 2, 1, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    if (uniqueOccurrences(arr, size)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}


/*
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

bool uniqueOccurrences(int* arr, int arrSize) {
    qsort(arr, arrSize, sizeof(int), compare);

    int counts[1000];
    int idx = 0;

    for (int i = 0; i < arrSize; i++) {
        int c = 1;
        while (i + 1 < arrSize && arr[i] == arr[i+1]) {
            c++;
            i++;
        }
        counts[idx++] = c;
    }

    qsort(counts, idx, sizeof(int), compare);

    for (int i = 0; i < idx - 1; i++) {
        if (counts[i] == counts[i+1]) {
            return false;
        }
    }

    return true;
}

int main() {
    int arr[] = {1, 2, 2, 1, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    if (uniqueOccurrences(arr, size)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
*/