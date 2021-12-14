class Solution {
public:
    const int ALPHA = 26;
    
    bool presentAllChars(string source, string target) {
        vector<bool> present(ALPHA, false);
        for (char ch: source) present[ch - 'a'] = true;
        for (char ch: target) if (!present[ch - 'a']) return false;
        return true;
    }
    
    vector<vector<int>> buildDistance(string source) {
        int lens = (int) source.size();
        vector<vector<int>> where(lens + 1, vector<int> (ALPHA, lens));
        
        for (int i = lens - 1; i >= 0; i--) {
            for (int j = 0; j < ALPHA; j++) {
                where[i][j] = where[i + 1][j];
            }
            where[i][source[i] - 'a'] = i;
        }
        
        return where;
    }
    
    int shortestWay(string source, string target) {
        if (!presentAllChars(source, target)) return -1;
        
        auto where = buildDistance(source);
        
        int iter = 0;
        int counter = 1;
        int lens = (int) source.size();
        int lent = (int) target.size();
        
        for (int i = 0; i < lent; i++) {
            int id = target[i] - 'a';
            if (where[iter][id] >= lens) {
                counter += 1;
                iter = 0;
            }
            iter = where[iter][id] + 1;
        }
        
        return counter;
    }
};
