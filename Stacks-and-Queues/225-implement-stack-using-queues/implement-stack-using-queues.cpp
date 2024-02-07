class MyStack {
    queue <int> q;
public:
    MyStack() {

    }
    
    void push(int x) {
        int s = q.size();
        q.push(x);
        for(int i=0;i<s;i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int n = q.front();
        q.pop();
        return n;
        
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.size()==0)return true;
        return false;
        
    }
};
// class MyStack {
//     queue<int> q1;
//     queue<int> q2;
//     int topEle;
// public:
//     MyStack() {
        
//     }
    
//     void push(int x) {
//         q2.push(x);
//         while(!q1.empty()){
//             q2.push(q1.front());
//             q1.pop();
//         }
//         queue<int> temp = q2;
//         q2=q1;
//         q1=temp;
//     }
    
//     int pop() {
//         int x = q1.front();
//         q1.pop();
//         return x;
//         }
//     int top() {
//         return q1.front();
//     }
    
//     bool empty() {
//         if(!q1.empty()){
//             return false;
//         }
//         else 
//         return true;
//     }
// };
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */