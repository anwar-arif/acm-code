#include<stdio.h>

char str[100000] ;

int main(){
    int cnt = 0, i ;
    while( gets(str) ) {
        int len = strlen(str) ;
        for( i = 0 ; i < len ; i++ ) {
            if( str[i] == '"' ) {
                cnt++ ;
                if( cnt % 2 == 1 ) printf("``") ;
                else printf("''") ;
            }
            else {
                printf("%c" , str[i] ) ;
            }
        }
        printf("\n") ;
    }
    return 0 ;
}
