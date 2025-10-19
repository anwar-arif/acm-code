#include <bits/stdc++.h>
using namespace std;

const int N = 10000+5;

/*
S[i][j] is the solution for the problem with the first i numbers available to form the sum j,

S[i-1][j] is the solution for the problem with the first i-1 numbers available to form the sum j,

S[i-1][j-A[i]] is the solution for the problem with the first i-1 numbers available to form the sum j-A[i].
*/

int main()
{
    int A[] = {0, 1, 3, 5, 11}; // The first entry is a dummy

    int n = 4;
    int W = 6;

    bool S[n+1][W+1];

    for (int i=0; i<=n; i++) S[i][0] = true;
    for (int j=1; j<=W; j++) S[0][j] = false;

    for (int j=1; j<=W; j++) {
        for (int i=1; i<=n; i++){
            if (j < A[i]){  // we cannot use A[i]

                S[i][j] = S[i-1][j];
            }
            else {     // we can use A[i]

                S[i][j] = S[i-1][j] || S[i-1][j-A[i]];
            }
        }
    }
    if (S[n][W]) {
        cout << "We can represent W = " << W << " by a subset sum of A.\n";
    }
    else {
        cout << "We cannot represent W = " << W << " by a subset sum of A.\n";
    }


    cout << "Printing the subset:\n";
    if (S[n][W]) {
        int j = W;
        for (int i=n; i>=1; i--) {
            if (!S[i-1][j]){
                cout << "Pick A[" << i << "] = " << A[i] << "\n";
                j -= A[i];
            }
        }
    }

    return 0;
}

