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
        Circular_linked_list(){
            size = 0;
            current = nullptr;
        }

        ~Circular_linked_list(){
            if(current == nullptr){
                return;
            }

            node * temp= current;
            while(temp->getNext() != current){
                node * tempForDelete = temp;
                temp= temp->getNext();
                delete tempForDelete;
            }
            delete temp;
            temp = nullptr;
            current = nullptr;
            size = 0;
        }

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

      void pop(){
            // empty list
            if(current == nullptr){
                return;
            }

            // one node left
            if(size == 1){
                delete current;
                current = nullptr;
                size--;
                return;
            }

            // select the last node
            node * last = current;
            while(last->getNext() != current){
                last = last->getNext();
            }

            node * first = current;
            current = current->getNext();
            current->setPrev(last);
            delete first;
            first = nullptr;
            last->setNext(current);
            size--;
        }

        void pop(int data){
            // empty list
            if(current == nullptr){
                return;
            }

            node * toBeRemoved = current, * prevNode = nullptr;
            while(toBeRemoved->getData() != data){
                if(toBeRemoved->getNext() == current){
                    cout << data << " is not in the list!" << endl;
                    return;
                }
                prevNode = toBeRemoved;
                toBeRemoved = toBeRemoved->getNext();
            }

            // Check if node is the only node in list
            if (toBeRemoved->getNext() == current && prevNode == nullptr){ // size == 1
                delete toBeRemoved;
                size = 0;
                current = nullptr;
                return;
            }

            // deleting first node
            if(toBeRemoved == current){
                this->pop();
                return;
            }

            // deleting last node
            if(toBeRemoved->getNext() == current){ // current->getPrev() == toBeRemoved
                prevNode->setNext(current);
                current->setPrev(prevNode);
                delete toBeRemoved;
                size--;
                return;
            }

            // deleting a middle node
            node * nextNode = toBeRemoved->getNext();
            prevNode->setNext(nextNode);
            nextNode->setPrev(prevNode);
            delete toBeRemoved;
            size--;
        }

        void push_after(int new_data,int pa_data){
            node * new_node = new node();
            new_node->setData(new_data);

            node * temp = current;
            while(temp->getData() != pa_data){
                // the case where pa_data does not exist
                if(temp->getNext() == current){
                    cout << pa_data << " is not in the list to push after it!" << endl;
                    return;
                }

                temp = temp->getNext();
            }
            node * nextNode = temp->getNext();
            temp->setNext(new_node);
            new_node->setPrev(temp);
            new_node->setNext(nextNode);
            nextNode->setPrev(new_node);
            size++;
        }

        void push_before(int new_data,int pb_data){
            node * new_node = new node();
            new_node->setData(new_data);

            node * temp = current;
            while(temp->getData() != pb_data){
                // the case where pb_data does not exist
                if(temp->getNext() == current){
                    cout << pb_data << " is not in the list to push after it!" << endl;
                    return;
                }

                temp = temp->getNext();
            }

            // for the first node to correctly set the * current
            if(temp == current){
                this->push(new_data);
                return;
            }

            node * prevNode = temp->getPrev();
            temp->setPrev(new_node);
            new_node->setNext(temp);
            new_node->setPrev(prevNode);
            prevNode->setNext(new_node);
            size++;
        }

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
    list.pop(12);
    list.push(32);
    list.print();
    list.push_after(85, 22);
    list.print();
    list.push_before(1400, 32);
    list.print();

    list.pop();
    list.push_after(666, 85);
    list.print();

    list.push_before(99, 666);
    list.print();

    cout << "Size of list : " << list.getSize() << endl;

    return 0;
}
