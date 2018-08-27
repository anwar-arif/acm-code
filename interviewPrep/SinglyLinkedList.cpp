#include<bits/stdc++.h>
using namespace std ;

struct node{
    int data ;
    node *nxt ;
};

class LinkedList{
private:
    node *head , *tail ;
public :

    LinkedList() {
        head = NULL ;
        tail = NULL ;
    }

    void InsertAtEnd( int value ) {
        node *tmp = new node ;
        tmp->data = value ;
        tmp->nxt = NULL ;
        if( head == NULL ) {
            head = tmp ;
            tail = tmp ;
        }
        else {
            tail->nxt = tmp ;
            tail = tmp ;
        }
    }

    void InsertAtBegin( int value ) {
        node *tmp = new node ;
        tmp->data = value ;
        tmp->nxt = head ;
        head = tmp ;
    }

    void InsertAtPos( int pos , int value ) {
        node *pre = new node ;
        node *cur = new node ;
        node *tmp = new node ;
        cur = head ;
        for( int i = 1 ; i < pos ; i++ ) {
            pre = cur ;
            cur = cur->nxt ;
        }
        tmp->data = value ;
        tmp->nxt = cur ;
        pre->nxt = tmp ;
    }

    void DeleteFirst() {
        node *tmp = new node ;
        tmp = head ;
        head = head->nxt ;
        delete tmp ;
    }

    void DeleteLast() {
        node *cur = new node ;
        node *pre = new node ;
        cur = head ;
        while( cur->nxt != NULL ) {
            pre = cur ;
            cur = cur->nxt ;
        }
        pre->nxt = NULL ;
        tail = pre ;
        delete cur ;
    }

    void DeletePos( int pos ) {
        node *pre = new node ;
        node *cur = new node ;
        cur = head ;
        for( int i = 1 ; i < pos ; i++ ) {
            pre = cur ;
            cur = cur->nxt ;
        }
        pre->nxt = cur->nxt ;
        delete cur ;
    }

    void Display() {
        node *tmp = new node ;
        tmp = head ;
        while( tmp != NULL ) {
            cout << tmp->data << " " ;
            tmp = tmp->nxt ;
        }
        cout << endl ;
    }

};

int main() {
    LinkedList ls ;
    for( int i = 1 ; i <= 7 ; i++ ) {
        ls.InsertAtEnd(i) ;
    }
    ls.Display() ;
    ls.InsertAtPos(2 , 9) ;
    ls.Display() ;
    ls.DeletePos(3) ;
    ls.Display() ;
    ls.DeleteFirst() ;
    ls.Display() ;
    ls.DeleteLast() ;
    ls.Display() ;
    return 0 ;
}
