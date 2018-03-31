
#define SIZ 10000+5
#define ub upper_bound

int main()
{
      int n,q;
      while(sc2i(n,q) != EOF)
      {
          int sq = (int)sqrt(n);
          vector<vector<int> > act,input;

          int s = n / sq;
          for(int i = 0  ;i < s;i++)
          {
              vector<int>temp;
              int x;
              for(int j = 0;j < sq;j++)
              {
                  sc1i(x);
                  temp.pb(x);
              }
              act.pb(temp);
              input.pb(temp);
          }
          if(s*sq != n)
          {
              vector<int>temp;
              int x;
              for(int i = s*sq ;i < n;i++)
              {
                  sc1i(x);
                  temp.pb(x);
              }
              act.pb(temp);
              input.pb(temp);
          }

          int siz = input.size();

          for(int i = 0 ; i < siz; i++)
          {
              sort(input[i].begin(),input[i].end());
          }
          getchar();
          ///find the number of value which are smaller than x within range l,r
          while(q--)
          {
              char ch;
              int st,en;
              sc("%c",&ch);
              if(ch == 'C')
              {
                  int x;
                  sc3i(st,en,x);
                  getchar();
                  st--;en--;///cause zero based

                  int beg = st/sq;
                  int endd = en/sq;

                  st -= beg*sq;
                  en -= endd*sq;

                  if(beg == endd)
                  {
                      int cnt = 0;
                      for(int i = st;i<=en;i++)
                      {
                          if(act[beg][i] <= x)++cnt;
                      }
                      pf("%d\n",cnt);
                  }
                  else
                  {
                      int cnt = 0;
                      for(int i = st ; i < act[beg].size();i++)
                      {
                          if(act[beg][i] <= x)++cnt;
                      }
                      for(int i = 0;i <= en;i++)
                      {
                          if(act[endd][i] <= x)++cnt;
                      }
                      for(int i = beg+1;i<endd;i++)
                      {
                          cnt += upper_bound(input[i].begin(),input[i].end(),x)-input[i].begin();
                      }
                      pf("%d\n",cnt);
                  }
              }
              else{
                  int id,x;
                  sc2i(id,x);
                  getchar();
                  id--;
                  int beg = id/sq;
                  id -= beg*sq;
                  act[beg][id] = x;
                  input[beg] = act[beg];
                  sort(input[beg].begin(),input[beg].end());
              }
          }
      }
      return 0;
}

