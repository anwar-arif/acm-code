#include<bits/stdc++.h>
using namespace std;

struct ABBA {
string canObtain(string initial, string target) {
    string ret;
    while (initial.size() < target.size()) {
        if (target[target.size() - 1] == 'B') {
            target = target.substr(0, target.size() - 1);
            reverse(target.begin(), target.end());
        } else {
            target = target.substr(0, target.size() - 1);
        }
    }
    ret = (initial == target) ? "Possible" : "Impossible";
    return ret;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "B"; string Arg1 = "ABBA"; string Arg2 = "Possible"; verify_case(0, Arg2, canObtain(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "AB"; string Arg1 = "ABB"; string Arg2 = "Impossible"; verify_case(1, Arg2, canObtain(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "BBAB"; string Arg1 = "ABABABABB"; string Arg2 = "Impossible"; verify_case(2, Arg2, canObtain(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "BBBBABABBBBBBA"; string Arg1 = "BBBBABABBABBBBBBABABBBBBBBBABAABBBAA"; string Arg2 = "Possible"; verify_case(3, Arg2, canObtain(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "A"; string Arg1 = "BB"; string Arg2 = "Impossible"; verify_case(4, Arg2, canObtain(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
ABBA ___test;
___test.run_test(-1);
int gbase;
cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
