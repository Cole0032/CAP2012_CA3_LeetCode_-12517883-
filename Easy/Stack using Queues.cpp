#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {
    }

    void push(int x) {
        // Step 1: Push new element into the auxiliary queue q2
        q2.push(x);

        // Step 2: Transfer all elements from q1 behind x in q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Step 3: Swap q1 and q2 (q1 now stores elements in LIFO order)
        swap(q1, q2);
    }

    int pop() {
        int topVal = q1.front();
        q1.pop();
        return topVal;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
