#include<bits/stdc++.h>
// #include<iomanip>
// #include<ctime>
using namespace std;

struct StringUtil {
    const char* t = " \t\n\r\f\v";

    // trim from end of string (right)
    inline string& rtrim(string& s) {
        s.erase(s.find_last_not_of(t) + 1);
        return s;
    }

    // trim from beginning of string (left)
    inline string& ltrim(string& s) {
        s.erase(0, s.find_first_not_of(t));
        return s;
    }

    // trim from both ends of string (right then left)
    inline string& trim(string& s) {
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
    const string DefaultFormat = "%d-%m-%Y %H:%M:%S";
    tm baseTime;

    DateUtil() {
        init();
    }
    
    // initialize baseTime e.g year in base time 1970
    void init() {
        time_t now = time(0);
        baseTime = *localtime(&now);
        baseTime.tm_year = 100; // 100 + 1900, provided value will be added with 1900.
        baseTime.tm_mon = 0;
        baseTime.tm_mday = 0;
        baseTime.tm_hour = 0;
        baseTime.tm_min = 0;
        baseTime.tm_sec = 0;
    }

    // building time with provided values
    tm buildTime(int year, int month, int day, int hour = 0, int minute = 0, int second = 0) {
        time_t now = time(0);
        tm ltm = *localtime(&now);
        ltm.tm_year = year - 1900;
        ltm.tm_mon = month - 1;
        ltm.tm_mday = day;
        ltm.tm_hour = hour;
        ltm.tm_min = minute;
        ltm.tm_sec = second;
        return ltm;
    }

    // converts a time to string
    string timeToString(tm ltm, string format = "") {
        if (format.empty()) format = DefaultFormat;
        const char* fmt = format.c_str();
        ostringstream oss;
        oss << put_time(&ltm, fmt);
        string timeString = oss.str();
        return timeString;
    }

    // converts a string to time
    tm stringToTime(string dateTime, string format = "") {
        if (format.empty()) format = DefaultFormat;
        struct tm tm;
        char buf[255];
        const char* fmt = format.c_str();
        const char* date = dateTime.c_str();

        memset(&tm, 0, sizeof(struct tm));
        strptime(date, fmt, &tm);
        strftime(buf, sizeof(buf), fmt, &tm);
        return tm;
    }

    // printing time
    void showTime(tm ltm) {
        cout << "showing time" << endl;
        cout << "Year: " << ltm.tm_year + 1900 << endl;
        cout << "Month: " << ltm.tm_mon + 1 << endl;
        cout << "Day: " << ltm.tm_mday << endl;
        cout << "Hour: " << ltm.tm_hour << endl;
        cout << "Minute: " << ltm.tm_min << endl;
        cout << "Second: " << ltm.tm_sec << endl;
        cout << "completed showing time" << endl;
    }

    // returns total second since baseTime we initiated in init() function
    unsigned long long epoch(tm first) {
        unsigned long long seconds = 0;
        int dYear = (unsigned long long) abs(first.tm_year - baseTime.tm_year);
        int dMon = (unsigned long long) abs(first.tm_mon - baseTime.tm_mon);
        int dDay = (unsigned long long) abs(first.tm_mday - baseTime.tm_mday);
        int dHour = (unsigned long long) abs(first.tm_hour - baseTime.tm_hour);
        int dMinute = (unsigned long long) abs(first.tm_min - baseTime.tm_min);
        int dSecond = (unsigned long long) abs(first.tm_sec - baseTime.tm_sec);

        seconds += dYear * 365 * 24 * 60 * 60;
        seconds += dMon * 30 * 24 * 60 * 60;
        seconds += dDay * 24 * 60 * 60;
        seconds += dHour * 60 * 60;
        seconds += dMinute * 60;
        seconds += dSecond;

        return seconds;
    }

    // returns [-1, 0, 1] based on comparing the second time with first time
    // -1 if first < second
    // 0 if first == second
    // 1 if first > second
    int compareTime(tm first, tm second) {
        unsigned long long eFirst = epoch(first);
        unsigned long long eSecond = epoch(second);
        if (eFirst == eSecond) return 0;
        return (eFirst < eSecond) ? -1 : 1;
    }

    // executes kinda testing 
    void run() {
        // building time
        tm ltm = buildTime(2021, 12, 4, 15, 30, 45);

        // time to string
        string timeStr = timeToString(ltm);
        cout << "time to string: " << timeStr << endl;
        showTime(ltm);

        // string to time
        tm ntm = stringToTime(timeStr);
        showTime(ntm);

        tm ftm = buildTime(2021, 12, 4, 15, 30, 40);
        cout << "epoch: " << epoch(ftm) << endl;

        tm gtm = buildTime(2021, 12, 4, 15, 30, 35);
        cout << "epoch: " << epoch(gtm) << endl;

        cout << "compare: " << compareTime(ftm, gtm) << endl;
    }
    
};

int main() {
    DateUtil D = DateUtil();
    StringUtil S = StringUtil();
    D.run();
}

/*
StringUtil
- trim (done)
- split (done)
- replace (done)

DateUtil
- buildDate (done)
- dateToString (done)
- stringToDate (done)
- compareDate (done)
*/