class Solution {
public:
	double findMedianSortedArrays(vector<int>& first, vector<int>& second) {
		if (first.size() > second.size()) swap(first, second);

		int lenf = (int) first.size();
		int lens = (int) second.size();

		int leftSize = (lenf + lens + 1) / 2;
		int odd = (lenf + lens) & 1;

		int lo = 0, hi = lenf;
		while (lo <= hi) {
			int mf = lo + (hi - lo) / 2;
			int ms = leftSize - mf;
			
            int xl = (mf == 0) ? INT_MIN : first[mf - 1];
			int xr = (mf < lenf) ? first[mf] : INT_MAX;

			int yl = (ms == 0) ? INT_MIN : second[ms - 1];
			int yr = (ms < lens) ? second[ms] : INT_MAX;
			
			if (xl <= yr && yl <= xr) {
				if (odd) return (double) max(xl, yl);
				else return (double) ((max(xl, yl) + min(xr, yr) + 0.0)) / 2.0;
			} else if (xl > yr) {
				hi = mf - 1;
			} else {
				lo = mf + 1;
			}
		}
        return 0.0;
	}
};

