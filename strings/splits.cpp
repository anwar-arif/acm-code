#include<bits/stdc++.h>
using namespace std;

// split by char
void splitByChar() {
    cout << "splitByChar" << endl;
    string sentence = " practice makes perfect! yes perfect!";
    stringstream ss(sentence);
    string cur;
    char delim = ' ';

    while (getline(ss, cur, delim)) {
        cout << cur << endl;
    }

}

// split by word
void splitByWord() {
    cout << "splitByWord" << endl;
    string sentence = "practice makes perfect! yes perfect!";
    stringstream ss(sentence);
    string cur;
    string delim = "perfect";

    int start = 0;
    int end = sentence.find(delim);
    int len = (int) sentence.size();

    vector<string> tokens;
    while (end >= 0) {
        tokens.push_back(sentence.substr(start, end - start));
        start = end + delim.length();
        end = sentence.find(delim, start);
    }

    for (auto token: tokens) {
        cout << token << endl;
    }
}

int main() {
    splitByChar();
    splitByWord();
}