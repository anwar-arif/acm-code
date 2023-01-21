int n, m, q;

long long c[2520][2520];

//update the rectangel
// x,x+1,x+2...row
// y,y+1,y+2...col
void update(int x, int y, long long z) {
	for (int i = x; i <= n; i += i & -i) {
		for (int j = y; j <= m; j += j & -j) {
			c[i][j] += z;
		}
	}
}

//return the value of cell ( x , y )
long long query(int x, int y) {
	long long ret = 0;
	for (int i = x; i > 0; i -= i & -i) {
		for (int j = y; j > 0; j -= j & -j) {
			ret += c[i][j];
		}
	}
	return ret;
}

int main() {

}
