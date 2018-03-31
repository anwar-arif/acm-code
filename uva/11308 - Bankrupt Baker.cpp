#include <bits/stdc++.h>
using namespace std;

const int N = 10000+5;

string binder , s , it;
map<string,int>msi;
vector< pair<int,string> >v;

int main(){
    int tst,cost,recipe,budget,ing,item,unit;
    scanf("%d",&tst);
    for(int cas = 0 ; cas < tst;cas++){
        getchar();
        getline(cin,binder);
        scanf("%d%d%d",&ing,&recipe,&budget);
        msi.clear();
        v.clear();
        getchar();
        for(int i = 1; i<= ing;i++){
            cin>>s>>cost;
            msi[s] = cost;
        }
        for(int i = 1 ;i<= recipe;i++){
            getchar();
            getline(cin,s);
            scanf("%d",&item);
            cost = 0;
            while(item--){
                getchar();
                cin>>it>>unit;
                cost += (unit * msi[it]);
            }
            if(cost <= budget){
                v.push_back(make_pair(cost,s));
            }
        }
        transform(binder.begin(),binder.end(),binder.begin(),::toupper);
        cout<<binder<<endl;
        sort(v.begin(),v.end());
        int len = (int)v.size();
        if(len == 0){
            printf("Too expensive!\n\n");
        }
        else{
            for(int i = 0 ; i < len;i++){
                cout<<v[i].second<<endl;
            }
            printf("\n");
        }
    }
    return 0;
}
