#include <bits/stdc++.h> 
class Stack {
	// Define the data members.
    queue<int> q1 , q2;

   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q1.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return q1.empty();
    }

    void push(int element) {
        // Implement the push() function.
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(element);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop() {
        // Implement the pop() function.
        int ans;
        if(!q1.empty()){
            ans = q1.front();
            q1.pop();
        }else
            ans = -1;
        return ans;
    }

    int top() {
        // Implement the top() function.
        if(q1.empty())
            return -1;
        return q1.front();
    }
};
