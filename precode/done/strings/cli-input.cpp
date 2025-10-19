#include<bits/stdc++.h>
using namespace std;

/*
 * To run this code, enter this command
 * g++ --std=c++11 cli-input.cpp -o out && ./out input1 input2
 * The output should contain "input1" and "input2"
 * */

int main(int argc, char *argv[]) {
    cout << "input from command line: " << endl;
    for (int i = 1; i < argc; i++) {
        cout << argv[i] << endl;
    }

    return 0;
}
