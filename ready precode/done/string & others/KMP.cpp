#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 2e6 + 10 ;
const int inf = (int) 2e9 ;

int *lps ;
string text , pat ;

void cal_lps() {
    int len = (int) pat.size() , indx = 0 ;
    lps = new int [len + 2] ;
    lps[0] = 0 ;
    for( int i = 1 ; i < len ; ) {
        if( pat[i] == pat[indx] ) {
            lps[i] = indx + 1 ;
            i++ , indx++ ;
        }
        else {
            if( indx != 0 ) {
                indx = lps[indx - 1] ;
            }
            else {
                lps[i] = 0 ;
                i++ ;
            }
        }
    }
}

void kmp() {
    cal_lps() ;
    int i = 0 , j = 0 ;
    int text_len = (int) text.size() ;
    int pat_len = (int) pat.size() ;

    ///i for text and j for pat
    while( i < text_len ) {
        if( text[i] == pat[j] ) {
            i++ , j++ ;
        }
        if( j == pat_len ) {
            printf("pat found at %d\n" , i - j ) ;
            j = lps[j - 1] ;
//            return (i - j) ;
        }
        else if( i < text_len && text[i] != pat[j] ) {
            if( j != 0 ) {
                j = lps[j - 1] ;
            }
            else {
                i++ ;
            }
        }
    }
}

int main(){
//    freopen("in.txt" , "r" , stdin ) ;
    cin >> pat >> text ;
    kmp() ;
    return 0 ;
}

/* complexity : O(m + n )*/
