#include <stdio.h>

int multiply(int a, int b) {
    int result = 0;
    for (int i = 0; i < b; i++) {
        result += a;
    }
    return result;
}

int main() {
    int a,b;
    printf("Enter the number: ");
    scanf("%d %d", &a,&b);
    int res = multiply(a,b);
    printf("%d",res);
    return 0;
}