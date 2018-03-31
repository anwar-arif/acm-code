#include <bits/stdc++.h>
using namespace std;
#define SZ(a) (int)a.size()
#define pf printf

const int N =  10000+5;

string text,pat;
int lps[N+5];

void cal_lps(){

    int indx = 0;
    lps[0] = 0;
    int len = SZ(pat);
    for(int i = 1 ;i < len; ){

        if(pat[i] == pat[indx]){

            lps[i] = indx + 1;
            i++; indx++;
        }
        else{

            if(indx != 0){

                indx = lps[indx - 1];
            }
            else{

                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmp(){

    cal_lps();

    int i = 0 , j = 0 ;
    int cnt  = 0;
    ///i for text and j for pat
    while(i < SZ(text)){

        if(pat[j] == text[i]){

            i++; j++;
        }
        if(j == SZ(pat)){
            pf("pat found at %d\n",i - j);
            j = lps[j - 1];
        }
        else if(i < SZ(text) and pat[j] != text[i]){

            if(j != 0){
                j = lps[j - 1];
            }
            else{
                i++;
            }
        }
    }
}

int main()
{
      while(cin>>text>>pat){

          kmp();
      }
      return 0;
}
///complexity O(m+n)
