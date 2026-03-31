#include <stdio.h>
#include "friends.h"

// Here i just ran a for loop through the order array and then compared it
// with the values in friends array, and then printing those which match using
// the IS_EQUAL function.

void findFriendsOrder(int order[], int n, int friends[], int m) {
    int arr[m];
    int idx=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (IS_EQUAL(order[i],friends[j])) {
                arr[idx]=order[i];
                idx++;
                break;
            }
        }
    }
    printf("Finishing Order is: ");
    for (int i=0; i<m; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}