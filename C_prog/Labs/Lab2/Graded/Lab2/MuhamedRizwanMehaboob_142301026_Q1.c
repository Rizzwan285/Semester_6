#include <stdio.h>

/* [TASK 1: SELECTION SORT ?]
Fill in the question mark in the for loop of Selection Sort
*/
/* [TASK 2: Fix OFFSET]
* The Selection Sort below still doesn't work as it relies on calculating an offset
index.
* The macro expansion order is messing up the math.
* Run 'gcc -Wall -save-temps your_file_name.c -o your_file_name' and check
'your_file_name.i'
* Observe how OFFSET logic expands inside the 'for' loops.
* Fix the OFFSET macro statement below
*/
#define OFFSET(i) (i) * 2
/* [TASK 3: ASSEMBLY CHECK]
* Find the pre-calculated value of this token.
* ACTION: Run 'gcc -Wall -save-temps your_file_name.c -o your_file_name' and open
'your_file_name.s'.

* Look for the value of 'auth_token'.
* You will see a single integer or hex value (e.g., 12345 or $12345).
* Write that value in the 'RECOVERED_TOKEN' variable below.
*/
int auth_token = (0xABCD & 0xACDC) + (100 * 5) - (0x5A | 0x05);
int RECOVERED_TOKEN = 43617; // <-- PUT THE VALUE FOUND IN .s FILE HERE
/* [TASK 4: LINKER ERROR]
* The TOTAL function is missing.
* ACTION: Create 'lib2.c', and inside it write 'int TOTAL(int *arr, int n) { int
sum = 0; for (int i=0; i<n; ++i){ sum += arr[i]; } return sum; }',
* and compile both files using: gcc your_file_name.c lib2.c -o your_file_name
*/

int TOTAL(int *arr, int n);
int main() {
    // Sorting specific elements at even indices: 0, 2, 4, 6, 8
    // The macro helps us jump 2 steps at a time.

    int arr[] = {10, 99, 50, 99, 30, 99, 20, 99, 40, 99}; // DO NOT CHANGE THE VALUES
    int n = 5; 
    
    // Sorting the 5 real numbers (10, 50, 30, 20, 40)
    // SELECTION SORT: Fill in the question mark
    // DO NOT CHANGE ANYTHING ELSE EXCEPT THE QUESTION MARK
    
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i; j < n; j++) {
            if (arr[OFFSET(j + 0)] < arr[OFFSET(min_idx+0)])
                min_idx = j;
        }
        int temp = arr[OFFSET(min_idx + 0)];
        arr[OFFSET(min_idx + 0)] = arr[OFFSET(i + 0)];
        arr[OFFSET(i + 0)] = temp;
        for (int i=0; i<10; i++) {
            printf("%d ",arr[i]);
        }
        printf(" Exit\n");
    }


    if (RECOVERED_TOKEN != auth_token) {
        printf("ALERT: You didn't find the correct token in the assembly file.\n");
        return 1;
    }
    else {
        printf("%d\n", RECOVERED_TOKEN);
    }

    // TOTAL OF FIRST FIVE ELEMENTS
    printf("%d\n", TOTAL(arr, n));
    

    for (int i=9; i>=0; i--) {
        if (arr[i]!=99) {
        printf("%d\n", arr[i]);
        }
    }
    // [TASK 5: GO THROUGH ALL THE 10 ELEMENTS OF THE ARRAY IN REVERSE ORDER USING A FOR LOOP BELOW AND PRINT ONLY THE FIVE ELEMENTS THAT ARE NOT 99]
    return 0;
}