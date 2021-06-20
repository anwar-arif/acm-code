#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    const double eps = 1e-7;

    bool canReach(int speed, vector<int>& dist, double hour) {
        int length = (int) dist.size();
        double travelTime = 0.0;

        for (int i = 0; i < length - 1; i++) {
            travelTime += ceil((double) dist[i] / (double) speed);
        }
        travelTime += (double) dist[length - 1] / (double) speed;

        return  travelTime <= hour;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int length = (int) dist.size();
        int speed = -1, lo = 1, hi = (int) 1e7, mid;

        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (canReach(mid, dist, hour)) {
                speed = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }   

        return speed;
    }
};

int main() {
    Solution sln;
    vector<int> dist = {1,1,100000};
    double hour = 2.01;

    cout << sln.minSpeedOnTime(dist, hour) << endl;
    return 0;
}