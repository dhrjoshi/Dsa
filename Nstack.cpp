#include<iostream>
using namespace std;

class NStack{
  public:
    int *arr;
    int *top;
    int *next;
    int n;
    int s;
    int freespot;

    NStack(int N , int S){
        this->n = N;
        this->s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        //top initialise:-
        for(int i=0;i<n;i++)
            top[i] = -1;
        //next initialise:-
        for(int i=0;i<s;i++)
            next[i] = i+1;
        //update last index value to -1:-
        next[s-1] = -1;
        //initialise freespot:-
        freespot = 0;
    }
    /**
     * the below function pushes x into the mth stack, returns true if it 
     * gets pushed and false otherwise...
     */
    bool push(int x , int m){
        //check for overflow:-
        if(freespot == -1)
            return false;
        //find index:-
        int index = freespot;
        //insert element into array:-
        arr[index] = x;
        //update freespot:-
        freespot = next[index];
        //update next:-
        next[index] = top[m-1];
        //update top:-
        top[m-1] = index;
        return true;
    }
    /**
     * pops top element from the mth stack. returns -1 if the stack is empty
     * otherwise returns the poped element...
     */
    int pop(int m){
        //check underflow conditions:-
        if(top[m-1] == -1)
            return -1;
        //the reverse the steps of push operation...
        int index = top[m-1];
        top[m-1] = next[index];
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};

int main(int argc, char const *argv[])
{
    NStack s(3,5);
    s.push(10,1);
    cout<<s.push(20,1)<<endl;
    s.push(21,3);
    s.push(32,2);
    cout<<s.pop(2)<<endl;
    cout<<s.pop(1)<<endl;
    s.push(65,1);
    cout<<s.pop(1)<<endl;

    return 0;
}
