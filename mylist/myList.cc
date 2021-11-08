#include<iostream>
#include"myList.h"

using namespace std;


int main(int argc,char *argv[]){
    Mylist a;

    Node *data = new Node;
    data->val = 1;
    data->next = nullptr;
    a.insertLinkList(data,0);
    a.printLinkList();



    Node *x = new Node;
    x->val = 2;
    x->next = nullptr;
    a.insertLinkList(x,0);
    a.printLinkList();
    

    a.reverseList2();


    Node *y = new Node;
    y->val = 3;
    y->next = nullptr;
    a.insertLinkList(y,4);
    a.printLinkList();

    //a.deleteLinkList(1);
    //a.printLinkList();

    //a.reverseList();
    a.reverseList2();
    a.printLinkList();
    return 0;
}
