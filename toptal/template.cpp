#include<bits/stdc++.h>
using namespace std;

struct StringUtil {
    const char* t = " \t\n\r\f\v";

    // trim from end of string (right)
    inline string& rtrim(string& s)
    {
        s.erase(s.find_last_not_of(t) + 1);
        return s;
    }

    // trim from beginning of string (left)
    inline string& ltrim(string& s)
    {
        s.erase(0, s.find_first_not_of(t));
        return s;
    }

    // trim from both ends of string (right then left)
    inline string& trim(string& s)
    {
        return ltrim(rtrim(s));
    }

    // split string with delimiter char
    vector<string> split(string &s, char delim) {
        stringstream ss(s);
        string item;
        vector<string> elems;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

    // replace word in string with another word
    void replace(string& subject, string search, string replace) {
        size_t pos = 0;
        while ((pos = subject.find(search, pos)) != std::string::npos) {
            subject.replace(pos, search.length(), replace);
            pos += replace.length();
        }
    }
};


// https://en.cppreference.com/w/c/chrono/strftime
// https://www.cplusplus.com/reference/ctime/strftime/
struct DateUtil {
    void testing() {
        time_t now = time(0);
        char *dt = ctime(&now);
        cout << dt << endl;

        tm *ltm = localtime(&now);
        cout << "Year:" << 1900 + ltm->tm_year<<endl;
        cout << "Month: "<< 1 + ltm->tm_mon<< endl;
        cout << "Day: "<< ltm->tm_mday << endl;
        cout << "Time: "<< 5+ltm->tm_hour << ":";
        cout << 30+ltm->tm_min << ":";
        cout << ltm->tm_sec << endl;

        char buffer[256];
        strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", ltm);
        cout << buffer << endl;
    }

    tm parseDateTime() {
        struct tm tm;
        char buf[255];
        memset(&tm, 0, sizeof(struct tm));
        strptime("2001-11-12 18:31:01", "%Y-%m-%d %H:%M:%S", &tm);
        strftime(buf, sizeof(buf), "%d %b %Y %H:%M", &tm);
        puts(buf);
        return tm;
    }
    
};

int main() {
    // string str = " anwar,hossain arif ";
    // cout << str << endl;
    // cout << StringUtil{}.trim(str) << endl;
    // auto splits = StringUtil{}.split(str, ',');
    // cout << splits.size() << endl;
    // for (auto s: splits) {
    //     cout << s << endl;
    // }
    // str = "anwar anwar anwar";
    // StringUtil{}.replace(str, "anwar", "anwar2");
    // cout << str << endl;
    // DateUtil{}.testing();
    DateUtil{}.parseDateTime();
    
}