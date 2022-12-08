#include<iostream>
using namespace std;

class Queue{
  public:
    int *arr;
    int qfront;
    int rear;
    int size;

    //constructor:-
    Queue(){
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    bool isEmpty(){
        if(qfront == rear)
            return true;
        else    
            return false;
    }

    void enqueue(int data){
        if(rear == size)
            cout<<"Queue is Full"<<endl;
        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue(){
        if(qfront == rear)
            return -1;
        else{
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == rear){
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }
    int front(){
        if(qfront == rear)
            return -1;
        return arr[qfront];
    }
};

int main(int argc, char const *argv[])
{
    
    Queue q;
    cout<<q.isEmpty()<<endl;
    q.enqueue(4);
    q.enqueue(5);
    cout<<q.isEmpty()<<endl;
    cout<<q.front()<<endl;
    q.enqueue(6);
    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    return 0;
}
