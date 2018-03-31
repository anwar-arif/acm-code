#include < bits/stdc++.h>
using namespace std;

const int N = 50 + 5;

stack<int>st;
int a[N]  , n ;

int histogram(){
    while(!st.empty())st.pop();
    int area = 0, mx_area = 0;
    int i;
    for(i = 1; i <= n;){
        if(st.empty() || a[ st.top() ] <= a[i]){
            st.push(i++);
        }
        else{
            int top = st.top(); st.pop();
            if(st.empty())area = a[top] * (i - 1);
            else{
                area = a[top] * ( i - st.top() - 1 );
            }
            mx_area = max(mx_area , area);
        }
    }
    while(!st.empty()){
        int top = st.top();
        st.pop();
        //if stack is empty means everything till i has to be
        //greater or equal to input[top] so get area by
        //input[top] * i;
        if(st.empty()){
            area = a[top] * (i - 1);
        }
        //if stack is not empty then everythin from i-1 to input.peek() + 1
        //has to be greater or equal to input[top]
        //so area = input[top]*(i - stack.peek() - 1);
        else{
            area = a[top] * (i - st.top() - 1);
        }
        mx_area = max(area , mx_area);
    }
    return mx_area;
}

///complexity O(n) ; n = size of array

int main(){
    int x;
    while(sc1i(n) != EOF){
        for(int i = 1; i <= n;i++){
            sc1i(x);
            a[i] = x;
        }
        int ans = histogram();
    }
    return 0;
}
