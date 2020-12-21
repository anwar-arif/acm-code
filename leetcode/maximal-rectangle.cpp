class Solution {
public:
    int histogram(vector<int> &arr) {
        int result = 0;
        stack<int> stk;
        stk.push(-1);
        
        int len = (int) arr.size();
        for (int i = 0; i < len; i++) {
            while (stk.top() != -1 && arr[stk.top()] >= arr[i]) {
                int top = stk.top(); stk.pop();
                int value = arr[top];
                result = max(result, value * (i - stk.top() - 1));
            }
            stk.push(i);
        }
        
        while (stk.top() != -1) {
            int top = stk.top(); stk.pop();
            int value = arr[top];
            result = max(result, value * (len - stk.top() - 1));
        }
        
        return result;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = (int) matrix.size();
        if (row == 0) return 0;
        
        int col = (int) matrix[0].size();
        vector<int> arr(col, 0);
        
        int answer = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '0') arr[j] = 0;
                else arr[j] += 1;
            }
            answer = max(answer, histogram(arr));
        }
        
        return answer;
    }
};
