#include <iostream>
#include <cmath>
#include "vector"

//s24382

using namespace std;

struct Person {
    string name;
    int birthYear;
};

bool compare (Person person1, Person person2) {
    return person1.birthYear = person2.birthYear && person1.name == person2.name;
}

struct Node {
    double data;
    Node * next;
};
bool atEnd = false;
void addNode(Node *& head, double data) {
    Node* add = new Node();
    add->data = data;
    if(atEnd && head){
        Node * tmp = head;
        while(tmp->next){
            tmp = tmp->next;
        }
        tmp->next = add;
        atEnd = false;
    } else {
        add->next = head;
        head = add;
        atEnd = true;
    }
}

const Node * findMax(const Node * head){
    const Node * tmp = head;
    const Node * max = head;
    while (tmp){
        if (tmp->data > max->data)
            max = tmp;
        tmp = tmp->next;
    }
    return max;
}

void printList(const Node * head) {
    const Node * tmp = head;
    cout << "[ ";
    while (tmp){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << " ]" << endl;
}

int main(){
    cout << "------------W6------------" << endl;
    cout << (compare({"Peter",1988}, {"Peter",1988})?"true" : "false") << endl;
    cout << (compare({"Peter",1988}, {"John",1974})?"true" : "false") << endl;
    cout << "------------W7------------" << endl;
    Node * head = 0;
    addNode(head, 2.6);
    addNode(head, 3.8);
    addNode(head, 7.4);
    addNode(head, 2.2);
    addNode(head, 6.3);
    printList(head);
    const Node * max = findMax(head);
    if (max)
        cout << "Max : " << max->data << endl;
    else
        cout << "Max is null" << endl;

    head = 0;
    max = findMax(head);
    if (max)
        cout << "Max : " << max->data << endl;
    else
        cout << "Max is null" << endl;
    return 0;
}
