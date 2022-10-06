//#ifdef Circular_linked_list_h
//#define Circular_linked_list_h
#include<iostream>
#include<list>
#include<ostream>
#include"ClockDirection.h"
#include<string>

using std::ostream;
class CircularLinkedList{
    public:
        CircularLinkedList();
        virtual ~CircularLinkedList();
        void push (int i ,ClockDirection d);
        int pop(ClockDirection d);
        void rotate(unsigned int n, ClockDirection d);
        int peek();
        friend ostream &operator<<(ostream &os,CircularLinkedList &object);
    private:
        ClockDirection d;
        struct Node{
            int data;
            struct Node* next;
            struct Node* prev;

        };
        struct Node* head;
        int len;
        
        std::string print();
};

//#endif
