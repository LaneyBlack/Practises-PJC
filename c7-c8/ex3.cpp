#include <iostream>
#include <functional>
#include <cmath>
#include "vector"

using namespace std;

struct Node {
    int data;
    Node* next;
};

bool add(Node*& head, int data){
    Node* tmp = head;
    while(tmp) {
        if (tmp->data == data)
            return false;
        tmp = tmp->next;
    }
    Node* add = new Node;
    add->data = data;
    add->next = head;
    head = add;
    return true;
}

size_t size (const Node* head){
    const Node *tmp = head;
    size_t counter = 0;
    while(tmp){
        counter++;
        tmp = tmp->next;
    }
    return counter;
}

void clear (Node *& head){
    Node * tmp = head;
    while(tmp){
        Node * del = tmp;
        tmp = tmp->next;
        cout << "Del: " << del->data << " ";
        delete del;
    }
    head = nullptr;
}

void printList(const Node * head){
    const Node * tmp = head;
    while(tmp){
        cout << tmp->data << "\t";
        tmp = tmp->next;
    }
    cout << endl;
}

int main (){
    int tab[] = {1,4,1,3,5};
    Node * head = 0;
    for (size_t i = 0, e = size(tab); i < e; ++i) {
        bool b = add(head, tab[i]);
        cout << tab[i] << (b? "   " : " NOT ") << "added" << endl;
    }
    cout << "Size of the list: " << size(head) << endl;
    printList(head);
    clear(head);
    cout << "\nSize of the list: " << size(head) << endl;
}