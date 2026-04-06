#include <stdio.h>

// Here the Recursion has a attribute maxx that holds the current maximum
// or largest digit in the number and then it recursively runs through
// the digits checking if any digit is higher than the maximum.

int largestdigit(int n, int maxx) {
    if (n<10) {
        if ((n)>maxx) {
            return n; 
        }
        else return maxx;
    }    
    else if ((n%10)>maxx) return largestdigit(n/10,n%10);
    else return largestdigit(n/10, maxx);
}


int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int res = largestdigit(n,0);
    printf("%d\n", res);
    return 0;
}