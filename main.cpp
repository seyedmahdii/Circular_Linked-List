#include<iostream>
using namespace std;

class node{
    private:
        int data;
        node* next;
        node* prev;
    public:
        int getData(){
            return data;
        }
        void setData(int data){
            this->data = data;
        }
        node * getNext(){
            return next;
        }
        void setNext(node * next){
            this->next = next;
        }
        node * getPrev(){
            return prev;
        }
        void setPrev(node * prev){
            this->prev = prev;
        }
};
class Circular_linked_list{
    private:
        int size;
        node* current;
    public:
        Circular_linked_list();
        ~Circular_linked_list();

        int getSize(){
            return size;
        }

        void push();
        void pop();
        void pop(int data);
        void push_after(int data);
        void push_befor(int data);
        void print();


};



int main(){


}
