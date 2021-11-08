#ifndef MYLIST_H
#define MYLIST_H
#include<iostream>

using namespace std;

typedef int Datetype;

class Node{
public:
    Node* next;
    Datetype val;

};

class Mylist{
public:
    Mylist();

    int getLen();
    int insertLinkList(Node *data,int n);
    int deleteLinkList(int n);
    void printLinkList();
    int reverseList();
    int reverseList2();
private:
    Node *head;
    int len;
    
    void reverse(Node *first,Node *pre);
};

Mylist::Mylist(){
    head = nullptr;
    len = 0;
}

int Mylist::getLen(){
    return len;
}

void Mylist::printLinkList(){
    if(head == nullptr){
        cout << "Worng the linkList is empty" << endl;
    }
    else{
        Node *ptr = head;
        while(ptr != nullptr){
            cout << ptr->val << "\t";
            ptr = ptr->next;
        }
        cout << endl;
    }
}

int Mylist::insertLinkList(Node *data,int n){
    // link list is empty;
    if(head == nullptr){
        data->next = nullptr;    
        head = data;
        ++len;
        return 1;
    }

    // insert at begin
    if(n < 2){
        Node *temp = head;
        data->next = temp;
        head = data;
    }
    // insert at end;
    else if(n > len){
        Node *ptr = head;
        while(ptr->next != nullptr){
            ptr = ptr->next; 
        }
        data->next = nullptr;
        ptr->next = data;
    }
    // insert at middle
    else{
        Node *ptr = head;
        while(n != 2){
            ptr = ptr->next;
            --n;
        }
        data->next = ptr->next;
        ptr->next = data;
    }
    ++len;
    return 0;
}

int Mylist::deleteLinkList(int n){
    if(head == nullptr){
        cout << "Wrong! LinkList is empty" << endl;
        return 0;
    }

    // delete at begin
    if(n < 2){
        Node *ptr = head;
        head = head->next;
        if(ptr != nullptr)free(ptr);
        ptr = nullptr;
    }
    // delete at end
    else if(n >= len){
        Node *ptr = head;
        // just only one node
        if(ptr->next == nullptr){
            head == nullptr;
            return 1;
        }
        // others 
        while(ptr->next->next != nullptr){
            ptr = ptr->next;
        }
        Node *temp = ptr->next;
        ptr->next = nullptr;
        free(temp);
        temp = nullptr; // set temp as null;
    }
    // delete at middle
    else{
        Node *ptr = head;
        while((n-2) != 0){
           ptr = ptr->next; 
        }
        Node *temp = ptr->next;
        ptr->next = temp->next;
        free(temp);
        temp = nullptr;
    }
    --len;
    return 1;
}

// reverse the list using stack
int Mylist::reverseList(){
    if(head == nullptr || head->next == nullptr){
        return 1;
    }

    Node *st[len];
    Node *ptr = head;
    int num = -1;
    // push the element;
    while(ptr != nullptr){
        st[++num] = ptr;
        ptr = ptr->next;
    }

    head = st[num];
    ptr = head;

    // create a new list
    while(num != 0){
        ptr->next = st[--num];
        ptr = ptr->next;
    }
    ptr->next = nullptr;
    return 1;
}

void Mylist::reverse(Node *first,Node *pre){
    Node *newhead = first->next;
    first->next = pre;
    if(newhead == nullptr){
        head = first;
    }
    else{
        reverse(newhead,first);
    }
}
// revese the list using recursion
int Mylist::reverseList2(){
    if(head == nullptr){
        return 1;
    }
    reverse(head,nullptr);
    return 1;
}
#endif
