#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    float sum=0, avg;
    scanf("%d",&n);
    if (n<=0) {
        printf("Invalid input");
        return 0;
    }

    float *arr = (float *)malloc(sizeof(float)*n);
    if (arr == NULL) {
        printf("Memory allocation failed!!!\n");
        return 1;
    }

    for (int i=0; i<n; i++) {
        scanf("%f", &arr[i]);
        sum+=arr[i];
    }

    avg = sum/n;
    
    printf("\nSum = %.3f\n",sum);
    printf("Average = %.3f\n",avg);
    
    free(arr);
    
    return 0;

}