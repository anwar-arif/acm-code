#include<stdio.h>
#include<string.h>

char s[123456];
int sz = 0, arr[123456];

void solve() {
    int i = 0, len = strlen(s);
    int number = 0, sign = 1;
    while (!isdigit(s[i])) {
        i++;
    }
    for (; i < len; i++) {
        char c = s[i];
        /*current character is a digit, update the number with this digit*/
        if (isdigit(c)) {
            number = (number * 10) + (c - '0');
        } else {
            /*current character is sign for negative number, change the sign to negative*/
            if (c == '-') {
                sign = -1;
            }
            /*continuous character with no digit:12    -1*/
            else if (i > 0 && !isdigit(s[i - 1])) {
                number = 0, sign = 1;
            }
            /*we got a number, insert this to the array*/
            else {
                arr[sz++] = number * sign;
                number = 0;
                sign = 1;
            }
        }
    }
    /*last number*/
    arr[sz++] = number * sign;
}

int main() {
    for (int i = 0; i < n; i++) {
	printf("Okay\n");
}
    return 0;
}
