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
    /*
        struct tm
        {
        int tm_sec;			// Seconds.	[0-60] (1 leap second) 
        int tm_min;			// Minutes.	[0-59] 
        int tm_hour;			// Hours.	[0-23] 
        int tm_mday;			// Day.		[1-31] 
        int tm_mon;			// Month.	[0-11] 
        int tm_year;			// Year	- 1900.
        int tm_wday;			// Day of week.	[0-6] 
        int tm_yday;			// Days in year.[0-365]	
        int tm_isdst;			// DST.		[-1/0/1]
    */
    tm* getTime(int year, int month, int day, int hour = 0, int minute = 0, int second = 0) {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        ltm->tm_year = year - 1900;
        ltm->tm_mon = month - 1;
        ltm->tm_mday = day;
        ltm->tm_hour = hour;
        ltm->tm_min = minute;
        ltm->tm_sec = second;
        return ltm;
    }

    string timeToString(tm* ltm, string format = "") {
        if (format.empty()) format = "%d/%m/%Y %H:%M:%S";
        const char* fmt = format.c_str();
        char buffer[256];
        strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", ltm);
        return string(buffer);
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

    void testing() {
        tm *ltm = getTime(2021, 12, 4);

        cout << "Year:" << 1900 + ltm->tm_year<<endl;
        cout << "Month: "<< 1 + ltm->tm_mon<< endl;
        cout << "Day: "<< ltm->tm_mday << endl;
        cout << "Time: "<< ltm->tm_hour << ":";
        cout << ltm->tm_min << ":";
        cout << ltm->tm_sec << endl;

        cout << timeToString(ltm) << endl;

    }
    
};

int main() {
    DateUtil{}.testing();
}