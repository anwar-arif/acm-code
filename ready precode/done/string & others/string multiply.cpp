#include <stdio.h>
#include <string.h>

int a[100],b[100];
int ans[200]= {0};
char s1[101] , s2[101];

void mul(){
    int i,j,tmp;
    memset(ans , 0 , sizeof ans) ;
    int l1 = strlen(s1);
    int l2 = strlen(s2);

    for(i = l1 - 1 , j = 0; i >= 0; i-- , j++){
        a[j] = s1[i] - '0';
    }
    for(i = l2 - 1 , j = 0; i >= 0; i-- , j++){
        b[j] = s2[i]-'0';
    }
    for(i = 0; i < l2; i++){
        for(j = 0; j < l1; j++){
            ans[i+j] += b[i]*a[j];
        }
    }
    for(i = 0; i < l1+l2; i++){
        tmp = ans[i]/10;
        ans[i] = ans[i]%10;
        ans[i+1] = ans[i+1] + tmp;
    }
    for(i = l1+l2; i>= 0; i--){
        if(ans[i] > 0)
            break;
    }
    printf("Product : ");
    for(; i >= 0; i--){
        printf("%d",ans[i]);
    }
    printf("\n");
}

int main()
{
    while(scanf(" %s",s1)){
        scanf(" %s",s2);
        mul();
    }
    return 0;
}
