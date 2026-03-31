#include <stdio.h>
#include <stdlib.h>

/*
Here im working on the assumption that, input of arrival time cannot be 
unsorted. Like a person having arrival time of 2 cannot be given as input
before a person having arrival time of 0. So kindly bear that in mind
while giving test cases.
*/

/*
Okay here what i did is, i used the treated array to store the flag (0,1) 
where the patient is treated or not. The treat variable is used to store
the index(1-based indexing) of the current priority person until we find
a better one. Then i run the iteration for the
number of elements of the array and first check if the person is treated or not
using the treated array, then check if he arrived or not, by checking if his
arrival time is before or equal to the current time which is i. Then i check
whether the treat variable is 0 or not, if it is 0, then that patient is the
current priority until we find a better one. Then i check if his severity is 
highest, if its same as the current priority person, we check their arrival
time and finally we print the treat variable value. We do this for the
entire array elements which will go through all patients.
*/

int selectPatient(int *arrival, int *severity, int *treated, int n, int currentTime) {
    printf("Treatment Order:");


    for (int i=0; i<n;i++) {
        int treat = 0;
        for (int j=0; j<n; j++) {
            if ((*(treated+j)==0) && (*(arrival+j)<=i)) {
                if (treat!=0) {
                    if ((*(severity+j))>(*(severity+treat-1))){
                        treat = j+1;
                    }
                    else if ((*(severity+j))==(*(severity+treat-1))) {
                        if ((*(arrival+j))>(*(arrival+treat-1))) {
                                treat = j+1;
                        }
                    }
                }
                else treat = j+1;
            }
        }
        *(treated+treat-1) = 1;
        printf(" %d", treat);
    }
    printf("\n");
    return 0;
}

int main() {
    int n, currentTime=0;
    scanf("%d", &n);
    int* arrival = (int *)malloc(n*sizeof(int));
    int* severity = (int *)malloc(n*sizeof(int));
    int* treated = (int *)malloc(n*sizeof(int));

    if (arrival == NULL || severity == NULL || treated == NULL) {
        printf("Memory Allocation Failed!!!");
        return 1;
    }

    for (int i=0;i<n;i++) {
        *(treated+i)=0;
        scanf("%d", arrival+i);
        scanf("%d", severity+i);
    }
    selectPatient(arrival,severity,treated,n,currentTime);
    free(arrival);
    free(severity);
    free(treated);

    return 0;
}



// Ignore these codes please. Just kept here for safety.

/*  int treat = 0;
    for (int j=0; j<n; j++) {
            if (*(treated+j)==0) {
                if (*(arrival+j)<=0) {
                    if (treat!=0) {
                        if ((*(severity+j))>(*(severity+treat-1))){
                            treat = j+1;
                        }
                        else if ((*(severity+j))==(*(severity+treat-1))) {
                            if ((*(arrival+j))>(*(arrival+treat-1))) {
                                    treat = j+1;
                            }
                        }
                    }
                    else treat = j+1;
                }
        }
    }
    *(treated+treat-1) = 1;
    printf("%d", treat);

*/

/*

#include <stdio.h>
#include <stdlib.h>

void maxHeapify(int *heap, int *arrival, int *severity, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && (severity[heap[left]] > severity[heap[largest]] ||
                      (severity[heap[left]] == severity[heap[largest]] && arrival[heap[left]] < arrival[heap[largest]]))) {
        largest = left;
    }

    if (right < n && (severity[heap[right]] > severity[heap[largest]] ||
                       (severity[heap[right]] == severity[heap[largest]] && arrival[heap[right]] < arrival[heap[largest]]))) {
        largest = right;
    }

    if (largest != i) {
        // Swap heap[i] with heap[largest]
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        
        // Recursively heapify the affected subtree
        maxHeapify(heap, arrival, severity, n, largest);
    }
}

void buildMaxHeap(int *heap, int *arrival, int *severity, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(heap, arrival, severity, n, i);
    }
}

int selectPatient(int *heap, int *arrival, int *severity, int *treated, int n) {
    if (n == 0) {
        return -1; // No patient left
    }

    int patientIndex = heap[0]; // The root of the max heap
    treated[patientIndex] = 1;  // Mark as treated

    // Swap the root with the last element
    heap[0] = heap[n - 1];
    n--;

    // Reheapify the heap
    maxHeapify(heap, arrival, severity, n, 0);

    return patientIndex;
}

int main() {
    int n;
    scanf("%d", &n);

    int *arrival = (int *)malloc(n * sizeof(int));
    int *severity = (int *)malloc(n * sizeof(int));
    int *treated = (int *)calloc(n, sizeof(int));  // To track treated patients
    int *heap = (int *)malloc(n * sizeof(int));    // Max heap to store patient indices

    // Read patient data
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arrival[i], &severity[i]);
        heap[i] = i;  // Initialize the heap with patient indices
    }

    // Build the max heap
    buildMaxHeap(heap, arrival, severity, n);

    int treatedCount = 0;
    int currentTime = 0;

    printf("Treatment order: ");

    while (treatedCount < n) {
        int patient = selectPatient(heap, arrival, severity, treated, n);

        if (patient == -1) {
            currentTime++;
            continue;
        }

        printf("%d ", patient + 1);  // Print patient number (1-based index)
        treatedCount++;
        currentTime++;
    }

    // Free allocated memory
    free(arrival);
    free(severity);
    free(treated);
    free(heap);

    return 0;
}
*/


