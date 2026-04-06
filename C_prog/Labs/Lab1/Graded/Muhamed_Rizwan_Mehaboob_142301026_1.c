#include <stdio.h>

int main () {
    int n, key, j, i;
    n = 5;
    int arr[5] = {3,4,2,7,1};

    printf("Array before Sorting: ");
    for (int i=0; i<n; i++) {
        printf("%d", arr[i]);
    }
    
    printf("\n");
    for (int i=2; i<5; i++) {
        printf("\nIntermediate pass %d: ",i-1);
        for (int k=0; k<n; k++) {
        printf("%d", arr[k]);
    }
        key = arr[i];
        j = i-1;
        while (j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
    printf("\n\nArray after Sorting: ") ;
    for ( i = 0; i < n ; i ++)
        printf ("%d" , arr[i]);
    return 0;
}