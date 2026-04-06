#include <stdio.h>

int countOnLamps(int n) {
    // Base Condition
    if (n == 1) return 1;
    
    // Checking the count of factors for the given switch number
    // Inorder to determine if the switch will be off or on at the end.
    // Basically if the count of factors is even its on or else its off 
    int c=0;
    for (int i=1; i<= n; i++) {
        if (n%i == 0) c++;
    }

    if (c%2==0) return countOnLamps(n-1);
    else return 1 + countOnLamps(n-1);
}

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);
    int res = countOnLamps(n);
    printf("Number of lamps ON = %d\n", res);
    return 0;
}


