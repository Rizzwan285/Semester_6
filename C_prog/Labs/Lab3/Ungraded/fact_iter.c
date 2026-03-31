#include <stdio.h>

int fact(int n) {
    int res =1;
    if (n==0) return 1;
    if (n==1) return 1;
    for (int i=n; i>0;i--) {
        res*=i;
    }
    return res;
    
}

int main() {
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    int x = fact(n);
    printf("%d\n", x);
    return 0;
}