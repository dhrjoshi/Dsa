#include<iostream>
using namespace std;

class CircularQueue{
  public:
    int *arr;
    int qfront;
    int rear;
    int size;

    //constuctor:-
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        qfront = rear = -1;
    }

    bool enqueue(int data){
        //check weather queue is full:-
        if((qfront == 0 && rear == size-1) || (rear == (qfront-1)%(size-1)))
            return false;
        //first element:-
        else if(qfront == -1)
            qfront = rear = 0;
        //to maintain cyclic nature:-
        else if(rear == size-1 && qfront != 0)
            rear = 0;
        else
            rear++;
        //push inside queue:-
        arr[rear] = data;
        return true;
    }

    int dequeue(){
        //check if queue is empty:-
        if(qfront == -1)
            return -1;
        int ans = arr[qfront];
        arr[qfront] = -1;
        //single element is present:-
        if(qfront == rear)
            qfront = rear = -1;
        //to maintain cyclic nature:-
        else if(qfront == size-1)
            qfront = 0;
        //normal flow:-
        else
            qfront++;
        return ans;
    }

};

int main(int argc, char const *argv[])
{
    CircularQueue cq(5);
    cq.enqueue(5);
    cq.enqueue(12);
    cq.enqueue(23);

    cout<<cq.dequeue()<<endl;
    cout<<cq.dequeue()<<endl;

    return 0;
}
