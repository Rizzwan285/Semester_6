#include <stdio.h>

// Here the binaryToDecimalRec functrion calls a Tail funciton
// to proceed with the tail recursion method and then it first checks
// the base condition and if it isnt satisfied, it moves on and checks
// whether the power is 0(The first func call) and if it is, it returns
// a fucntion call such taht the power is 2 and uses the binary to
// decimal formula to convert it. Similarly we do this for the
// higher digits.

int binaryToDecimalRecTail(int bin, int base, int dec, int power) {
    if (bin<10) return (dec+((bin%10)*power));
    if (power == 0) return binaryToDecimalRecTail(bin/10,base,dec+((bin%10)*1),2);
    else return binaryToDecimalRecTail(bin/10,base,dec+((bin%10)*power),power*base);
    }

int binaryToDecimalRec(int bin, int base, int dec) {
    return binaryToDecimalRecTail(bin,base,0,0);
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int res = binaryToDecimalRec(n,2,0);
    printf("The Decimal Equivalent = %d\n", res);
    return 0;
}