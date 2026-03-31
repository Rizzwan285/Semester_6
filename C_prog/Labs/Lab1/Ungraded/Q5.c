#include <stdio.h>

int main() {
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int i=0;
	int length = sizeof(arr)/sizeof(arr[0]);
	for (i=0; i<length; i++) {
		if (arr[i] % 2 ==0) arr[i] = 0;
		else arr[i] = 1; 
	}	
	for (int i =0; i<length; i++) printf("%d ", arr[i]);
	return 0;
}
