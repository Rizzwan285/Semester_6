#include <stdio.h>

/*
This function counts the number of factors of the provided number using
recursion where the function call increaments the i value every time and
adds one to the function call whenever the i value is a factor.
*/
int countFactors(int n, int i) {
    if (i==n) return 1;
    if (n%i == 0) return 1 + countFactors(n,i+1);
    else return countFactors(n,i+1);
}


/*
Basically we use the idea taht no of factors of a perfect square number are
odd. So for each element in the array we check the number of factors and then
if its odd then its a perfect square and we just print it else we continue. 
*/
void printPerfectSquares(int arr[], int n){
    for (int i=0; i<n; i++) {
        if (countFactors(arr[i], 1) % 2 == 0) continue;
        else {
            printf("%d ",arr[i]);
        }
    }
}

int main() {
    int n;
    printf("Enter the array size: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array:");
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    printPerfectSquares(arr, n);
    return 0;

}
