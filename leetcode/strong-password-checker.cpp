class Solution {
public:
    const int inf = (int) 2e8;

    /**
        since we're concerned about only 3 consecutive chars,
        it's enough to use only 3 chars of each category (uppercase, lowecase, digits)
    */
    string chars = "ABCabc012";
    string s;

    int dp[22][55][10][2][256];
    int n;

    /**
    *   produces new mask value after adding a char in our resultant password
    */
    int newMask(int mask, char c) {
        if (c >= 'A' && c <= 'Z') return (mask | (1 << 0));
        if (c >= 'a' && c <= 'z') return (mask | (1 << 1));
        if (c >= '0' && c <= '9') return (mask | (1 << 2));
        return mask;
    }

    /**
        len: length of our resultant password
        pos: index of our given password
        mask: binary form of this value represents if we meet our conditions
              0th bit is 1 if resultant password contains an uppercase
              1st bit is 1 if resultant password contains an lowercase
              2nd bit is 1 if resultant password contains a digit
              so, when the mask value is 7(111 in binary) our required conditions are met
        same: when we are at i'th position in our resultant password,
              it checks if (i - 1)th and (i - 2)th chars are same or not
              true if same, false if not same
        last: previous char we used in our resultant password

    */
    int minOp(int len, int pos, int mask, int same, char last) {
        if (len > 20) return inf;
        if (pos == n && len >= 6) {
            if (mask == 7) return 0;
            return inf;
        }

        int &ret = dp[len][pos][mask][same][last];
        if (ret != -1) return ret;

        ret = inf;

        /**
            !(same && last == s[pos]) returns true if last 3 chars (including current char)
             in our resultant password are not same
        */

        /** no operations, leaving as it is*/
        if (pos < n && !(same && last == s[pos]))
            ret = min(ret, minOp(len + 1, pos + 1, newMask(mask, s[pos]), last == s[pos], s[pos]));

        ///insert
        for (int i = 0; i < 9; i++) {
            char c = chars[i];
            if (!(same && last == c))
                ret = min(ret, 1 + minOp(len + 1, pos, newMask(mask, c), last == c, c));
            /**
                we're inserting a char, so resultant password length will increase
                and index of given password will remain same
            */
        }

        ///delete
        if (pos < n) ret = min(ret, 1 + minOp(len, pos + 1, mask, same, last));
        /**
            we're deleting current char from our given password,
            so resultant password length will remain same and index of given password will increase
        */

        ///replace
        if (pos < n) {
            for (int i = 0; i < 9; i++) {
                if (chars[i] == s[pos]) continue;
                char c = chars[i];
                if (!(same && last == c))
                    ret = min(ret, 1 + minOp(len + 1, pos + 1, newMask(mask, c), last == c, c));
                /**
                    we're replacing, so both resultant password length and index of given password will increase
                */
            }
        }

        return ret;
    }

    int strongPasswordChecker(string str) {
        s = str;
        n = (int) s.size();

        memset(dp, -1, sizeof(dp));

        int ans = minOp(0, 0, 0, 0, '#');
        return ans;
    }
};
