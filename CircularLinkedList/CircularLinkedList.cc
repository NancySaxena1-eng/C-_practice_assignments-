#include<iostream>
#include<list>
#include<ostream>
#include<string>
#include<sstream>
#include"CircularLinkedList.h"
using std::stringstream;
using std::ostream;
using std::string;
using std::cout;
using std::endl;
CircularLinkedList::CircularLinkedList(){
    head = NULL;
    len = 0;

}

CircularLinkedList::~CircularLinkedList(){
    Node* p = head;
    if (head==NULL){
        return;
    }
    else{
        while(head->next != head){
            p=head->next;
            p->next->prev=head;
            head->next = p->next;
            delete p;
        }
        delete(head);
    }
}

void CircularLinkedList::push (int i ,ClockDirection d){
    Node* newnode = new Node(); 
    Node* ptr= head;
    Node* prv;
    Node* temp;

    newnode->data=i;
    len++;
    if (head == NULL){
        head =  newnode;
        newnode->data = i;
        newnode->next=newnode;
        newnode->prev=newnode;
        head= newnode;
    } else{

        if (d == CounterClockWise){
            // DOING PREVIOUS SETTLEMENT

            temp = head->prev;
            head->prev = newnode;
            newnode->prev =temp;
            //NEXT SETTLEMENT 
            newnode->next = head;
            temp->next = newnode;
            head= newnode;
        }

        else{
            Node* temp;
            temp = head->next;
            head->next = newnode;
            newnode->next = temp;
            newnode->prev= head;
            temp->prev =  newnode;
            head=newnode;
        }

    }
}

std::string
CircularLinkedList::print() {
    Node* cur = head;
    stringstream ss;
    if(head ==NULL){
    }
    else if(cur->next == head){
        ss << head->data <<endl;
    }
    else{
        do {
            ss << cur->data << "->"; 
            cur =cur->next;
        } while(cur->next != head);
        ss << cur->data << endl;
    }
    return ss.str();
}

int CircularLinkedList::pop(ClockDirection d){

    if(head==NULL){
        throw "The link list is empty"; 
    } else {
        len--;
        Node* temp;
        temp = head;
        int m_integer = head->data;
        if (head->next !=head){
            if (d==CounterClockWise){
                head = head->prev;
            } else {
                head = head->next;

            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        } else {
            head = NULL;
        }
        return m_integer;
    }
}


void CircularLinkedList::rotate(unsigned int n, ClockDirection d){
    Node* ptr=head;
    if (head== NULL) {
        throw "The link list is empty"; 
    }
    else if (ptr->next == head){

    }
    else{
        n = n % len;
        //rotatong counter clock wise
        if (n > 0) {
            //check if the n is bigger than the length of the list ;rotate one more time
            while( n > 0) {
                if (d==CounterClockWise) {
                    ptr=ptr->prev;
                } else {
                    ptr=ptr->next;
                }
                n--;
            }
            head = ptr;
        }
    }
}

int CircularLinkedList::peek(){
    if (head != NULL) {
        return head->data;
    } else {
        throw "The link list is empty"; 
    }
}




std::ostream &operator<<(ostream  &os,CircularLinkedList &object){
    os << object.print();
    return os;
}





