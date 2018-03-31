#include<bits/stdc++.h>
using namespace std ;

const int N = 10000+5;
const int M = 26;

int a[N][M],cnt[N];
int id , root;

int new_node(){
    for(int i = 0 ; i< M;i++){
        a[id][i] = -1;
    }
    cnt[id] = 0;
    return id++;
}

void add(string s){
    int len = s.size();
    int cur = 0 , typ;
    for(int i = 0 ; i< len;i++){
        typ = s[i] - '0';
        if(a[cur][typ] == -1){
            a[cur][typ] = new_node();
        }
        cur = a[cur][typ];
        cnt[cur]++;
    }
}

int main()
{
      int tst,cas = 0 ;
      scanf("%d" , &tst ) ;
      while(tst--){
          id = 0;
          root = new_node();
          scanf("%d" , &n ) ;
          string s;
          for(int i = 0 ; i < n;i++){
             cin>>s;
             add(s);
          }
      }
      return 0;
}
