#include<bits/stdc++.h>
using namespace std;

int main() {
    char ch = 'A';
    int n = 12345;
    string val = "9876";

    // string to int
    cout << stoi(val) << endl;

    // string to long long
    cout << stoll(val) << endl;

    // int to string 
    cout << to_string(n) << endl;

    // tolower; remember that tolower() returns an int
    cout << char(tolower(ch)) << endl;

    // toupper; remember that toupper() returns an int
    cout << char(toupper(ch)) << endl;
    return 0;
}