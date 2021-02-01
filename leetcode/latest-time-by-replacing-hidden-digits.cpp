/**
 * @file latest-time-by-replacing-hidden-digits
 * @author Anwar Hossain <anwararif727@gmail.com>
 *
 * @date Sunday January 24 2021
 *
 * @brief 
 */
class Solution {
public:
    string maximumTime(string time) {
        int best = 0, H = 0, M = 0;
        for (int h1 = 0; h1 < 10; h1++) {
            for (int h2 = 0; h2 < 10; h2++) {
                for (int m1 = 0; m1 < 10; m1++) {
                    for (int m2 = 0; m2 < 10; m2++) {
                        int hour = time[0] == '?' ? h1 : time[0] - '0';
                        hour = hour * 10;
                        hour = hour + (time[1] == '?' ? h2 : time[1] - '0');
                        int minute = time[3] == '?' ? m1 : time[3] - '0';
                        minute = minute * 10;
                        minute = minute + (time[4] == '?' ? m2 : time[4] - '0');

                        int total = hour * 60 + minute;
                        if (hour < 24 && minute < 60 && total > best) {
                            best = total;
                            H = hour, M = minute;
                        }
                    }
                }
            }
        }
        string answer = (H / 24) + '0';
        answer += (H % 24) + '0';
        answer += (M / 24) + '0';
        answer += (M % 24) + '0';
        return answer;
    }
};