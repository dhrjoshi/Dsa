#include<iostream>
using namespace std;

class TwoStack{
  public:
    int *arr;
    int top1;
    int top2;
    int size;
    
    TwoStack(int s){
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[5];
    }
    //push in stack1:-
    void push1(int num){
        //atleat a empty space should be present:-
        if(top2-top1 > 1){
            top1++;
            arr[top1] = num;
        } else
            cout<<"Stack Overflow";
    }
    //push in stack2:-
    void push2(int num){
        if(top2-top1 > 1){
            top2--;
            arr[top2] = num;
        } else  
            cout<<"Stack Overflow";
    }
    //pop from stack1:-
    int pop1(){
        if(top1 >= 0){
            int ans = arr[top1];
            top1--;
            return ans;
        } else{
            cout<<"Stack Underflow";
            return -1;
        }
    }
    //pop from stack2:-
    int pop2(){
        if(top2 < size){
            int ans = arr[top2];
            top2++;
            return ans;
        } else{
            cout<<"Stack Underflow";
            return -1;
        }
    }

};

int main(int argc, char const *argv[])
{
    TwoStack s(5);
    s.push1(12);
    s.push1(32);
    s.push1(44);
    cout<<s.top1<<endl;
    cout<<s.top2<<endl;
    s.push2(344);
    cout<<s.top2<<endl;
    cout<<s.pop1()<<endl;
    cout<<s.top1;
    


    return 0;
}
