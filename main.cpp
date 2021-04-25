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

        void push(int data){
            node * new_node = new node;

            // first node
            if(current == nullptr){
                new_node->setData(data);
                new_node->setNext(new_node);
                new_node->setPrev(new_node);
                current = new_node;
                size++;
                return;
            }

            // select last node
            node * last = current->getPrev();

            new_node->setData(data);
            new_node->setNext(current);
            new_node->setPrev(last);

            last->setNext(new_node);
            current->setPrev(new_node);

            current = new_node;
            size++;
        }

        void pop();
        void pop(int data);
        void push_after(int new_data,int pa_data);
        void push_befor(int new_data,int pb_data);

        void print(){
            if(current == nullptr){
                cout << "List is empty" << endl;
                return;
            }

            node * temp = current;
            do{
                cout << temp->getData() << "\t";
                temp = temp->getNext();
            }
            while (temp != current);
            cout << endl;
        }


};



int main(){
    Circular_linked_list list;
    list.push(12);
    list.push(22);
    list.push(32);
    list.print();

    return 0;
}
