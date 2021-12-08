#include<bits/stdc++.h>
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
};

struct DateUtil {
    const string DefaultFormat = "%Y-%m-%d";
    tm baseTime;

    DateUtil(){
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
    
};


struct Photo {
    string name;
    string city;
    string date;

    Photo(){}
    Photo(string _name, string _city, string _date) {
        name = _name, city = _city, date = _date;
    }

    bool operator < (const Photo &other) const {
        if (city != other.city) return city < other.city;
        else {
            auto first = DateUtil{}.stringToTime(date);
            auto second = DateUtil{}.stringToTime(other.date);
            int cmp = DateUtil{}.compareTime(first, second);
            return cmp <= 0 ? 1 : 0;
        }
    }
};

class Solution {
    StringUtil S = StringUtil();
    DateUtil D = DateUtil();
public:
    string solve(string photoInfo) {
        
        auto splits = S.split(photoInfo, ';');
        vector<Photo> photos;
        for (auto photo: splits) {
            auto p = S.split(S.trim(photo), ',');
            photos.push_back(Photo(p[0], p[1], p[2]));
        }
        sort(photos.begin(), photos.end());
        for (auto photo: photos) {
            cout << photo.name << " " << photo.city << " " << photo.date << endl;
        }
        return "";
    }
};

int main() {
    Solution sln;
    string photos = "saintmartin1.jpg,Bandarban,2021-10-06;saintmartin2.jpg,Chittagong,2021-10-05;saintmartin3.jpg,Chittagong,2021-10-06";
    sln.solve(photos);
    return 0;
}