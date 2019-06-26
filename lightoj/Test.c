#include<stdio.h>

int x[101], y[101];

int process(int n) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    for (i = 0; i < n; i++) {
        printf("%d %d\n", x[i], y[i]);
    }
    return 0;
}

int main() {

    return 0;
}
