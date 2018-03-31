
const int N = 500 + 5;

const ll M1 = 10000009;
const ll B1 = 33;
const ll M2 = 10000007;
const ll B2 = 163;

string s;

ll h1[100010] , h2[100010];
ll pow1[100010] , pow2[100010];

void init()
{
    int n = s.size() , i;

    pow1[0] = pow2[0] = 1;
    h1[0] = h2[0] = 0 ;

    for(i = 1; i <= n; i++)///  calculate power
    {
        pow1[i] = (B1 * pow1[i-1]) % M1;

        pow2[i] = (B2 * pow2[i-1]) % M2;
    }

    for(i = 1; i <= n; i++) /// calculate hash value
    {
        h1[i] = (B1 * h1[i-1] + s[i-1] - 'a' + 1) % M1;

        h2[i] = (B2 * h2[i-1] + s[i-1] - 'a' + 1) % M2;
    }
}

ll getHash1(int l , int r)/// get hash value of range l to r
{
    int len = r - l + 1;

    ll ret = (h1[r] - (h1[l-1] * pow1[len]) % M1 + M1) % M1;

    return ret;
}

ll getHash2(int l , int r)/// double hash
{
    int len = r - l + 1;

    ll ret = (h2[r] - (h2[l-1] * pow2[len]) % M2 + M2) % M2;

    return ret;
}

int main()
{
    int n , q , i;
    while( cin>>s )
    {
        n = s.size();
        init();/// set hash value
        sc1i(q);
        while(q--)
        {
            int x1,y1,x2,y2;

            sc2i(x1 , y1);
            sc2i(x2 , y2);

            if(y1 - x1 == y2 - x2)/// length equal
            {
                pair < ll , ll > H1(getHash1(x1,y1),getHash2(x1,y1));
                pair < ll , ll > H2(getHash1(x2,y2),getHash2(x2,y2));
                if(H1 == H2)
                    pf("Yes\n");
                else
                    pf("No\n");
            }
            else
                printf("No\n");
        }
    }
    return 0;
}
/*
const int BASE = 31;
const int MOD = (int)1e9+7;

map<long long, int> hash;
    for (int i = 0; i < n; ++i) {
        long long hashVal = 0;

        for (char ch : v[i]) {
            int d = ch - 'a' + 1;
            hashVal = hashVal * BASE + d;
            if (hashVal >= MOD) {
                hashVal %= MOD;
            }

            if (hash.find(hashVal) != hash.end()) {
                hash.erase(hash.find(hashVal));
            }
        }
        hash[hashVal] = i;

    }
*/
