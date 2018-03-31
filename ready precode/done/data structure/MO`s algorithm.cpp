
#define SIZ 300000+5

struct data{
    int L,R,i;
}q[SIZ];

//finding distinct elements in a range with MO`s algo

int a[SIZ] , cnt[1011115] ,ans[SIZ] ,answer , block ;

bool cmp(data a,data b)
{
    if(a.L/block != b.L/block)
    {
        return a.L/block < b.L/block;
    }
    return a.R < b.R;
}

void add(int pos)
{
    cnt[a[pos]]++;
    if(cnt[a[pos]] == 1)++answer;
}

void remove(int pos)
{
    cnt[a[pos]]--;
    if(cnt[a[pos]] == 0)--answer;
}

int main()
{
      #ifndef ONLINE_JUDGE
      //Read;
      //Write;
      #endif
      int n;
      while(sc1i(n) != EOF)
      {
          answer = 0;
          mem(cnt,0); mem(ans,0);

          for(int i = 0 ; i<n;i++)
          {
              sc1i(a[i]);
          }
          block = 2 + (int)sqrt(n);
          int m , l , r;
          sc1i(m);
          for(int i = 0 ; i < m;i++)
          {
              sc2i(l,r);
              l -= 1;
              r -= 1;
              q[i].L = l;
              q[i].R = r;
              q[i].i = i;
          }

          sort(q , q + m , cmp);
          answer = 0;
          int curL = 0,curR = 0;

          for(int i = 0 ;i < m;i++)
          {
              int L = q[i].L;
              int R = q[i].R;

              while(curL < L){
                  remove(curL);
                  curL++;
              }
              while(curL > L){
                  add(curL - 1);
                  curL--;
              }
              while(curR <= R){
                  add(curR);
                  curR++;
              }
              while(curR > R+1){
                  remove(curR - 1);
                  curR--;
              }
              ans[q[i].i] = answer;
          }
          for(int i = 0 ; i < m;i++)
          {
              pf("%d\n",ans[i]);
          }
      }
      return 0;
}
/*
complexity N*sqrt(N)*log N
*/
