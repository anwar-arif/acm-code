class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int answer = 0;
        int limit = (int) (sqrt(2 * N + 0.25) - 0.5);
        for (int k = 1; k <= limit; k++) {
            if ((N - k * (k + 1) / 2) % k == 0) {
                answer += 1;
            }
        }
        return answer;
    }
};

