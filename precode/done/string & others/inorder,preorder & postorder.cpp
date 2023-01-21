#include <bits/stdc++.h>
using namespace std;

//inorder : left,root,right;

//preorder : root,left,right;

//postorder : left,right,root;

void inorder(int n)
{
    if(n == 1 || n == 2)
    {
        pf("%d ",n);
        return;
    }
    inorder(n - 2);

    pf("%d ",n);

    inorder(n-1);
}

void preorder(int n)
{
    if(n == 1 || n == 2)
    {
        pf("%d ",n);
        return;
    }

    pf("%d ",n);

    preorder(n-2);

    preorder(n-1);
}

void postorder(int n)
{
    if(n == 1 || n == 2)
    {
        pf("%d ",n);
        return;
    }

    postorder(n-2);
    postorder(n-1);

    pf("%d ",n);
}

int main()
{
    int n;
    while(sc1i(n) == 1)
    {
        pf("inorder : ");
        inorder(n);

        pf("\npreorder : ");
        preorder(n);

        pf("\npostorder : ");
        postorder(n);
        pf("\n");
    }
}

