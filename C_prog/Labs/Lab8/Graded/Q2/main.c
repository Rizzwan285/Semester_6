#include <stdio.h>
#include "friends.h"

int main() {
    int n,m;
    printf("Enter the size of order: ");
    scanf("%d", &n);

    int order[n];

    printf("Enter the elements of order: ");
    for (int i=0; i<n; i++) {
        scanf("%d", &order[i]);
    }

    printf("Enter the size of friends: ");
    scanf("%d", &m);

    int friends[m];

    printf("Enter the elements of friends: ");
    for (int j=0; j<m; j++) {
        scanf("%d", &friends[j]);
    }

    findFriendsOrder(order, n, friends, m);

    return 0;
}