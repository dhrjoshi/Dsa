#include<iostream>
using namespace std;

class Stack{
  public:
    int *arr;
    int top;
    int size;
    //constructor:-
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int element){
        if(size - top > 1){
            top++;
            arr[top] = element;
        } else
            cout<<"Stack Overflow";
    }
    void pop(){
        if(top >= 0)
            top--;
        else    
            cout<<"Stack Underflow";
    }
    int peek(){
        if(top >= 0)
            return arr[top];
        else{
            cout<<"Stack is Empty";
            return -1;
        }
    }
    bool isEmpty(){
        if(top == -1)
            return true;
        else    
            return false;
    }
};

int main(int argc, char const *argv[])
{
    Stack s(5);
    s.push(23);
    s.push(32);
    s.push(122);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    s.pop();
    if(s.isEmpty())
        cout<<"Stack is Empty";
    else
        cout<<"Stack is not Empty";
    return 0;
}
