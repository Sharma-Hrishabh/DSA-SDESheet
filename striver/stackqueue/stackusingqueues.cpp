class MyStack {
public:
    queue<int>q1;
    queue<int>q2;
    MyStack() {
        
    }
    
    void push(int x) {
        if(q2.empty()){
            q1.push(x);
        }
        else{
            q2.push(x);
        }
    }
    
    int pop() {
        int x;
        if(!q1.empty()){
            //q1 has all elements
            while(q1.size()!=1){
                int save = q1.front();
                q1.pop();
                q2.push(save);
            } 
            x= q1.front();
            q1.pop();
        }
        else{
            //q2 has all elements
            while(q2.size()!=1){
                int save = q2.front();
                q2.pop();
                q1.push(save);
            } 
            x= q2.front();
            q2.pop();
        }
        return x;
    }
    
    int top() {
        int x;
        if(!q1.empty()){
            //q1 has all elements
            while(q1.size()!=1){
                int save = q1.front();
                q1.pop();
                q2.push(save);
            } 
            x= q1.front();
            q1.pop();
            q2.push(x);
        }
        else{
            //q2 has all elements
            while(q2.size()!=1){
                int save = q2.front();
                q2.pop();
                q1.push(save);
            } 
            x= q2.front();
            q2.pop();
            q1.push(x);
        }
        return x;   
    }
    
    bool empty() {
        if(q1.empty() && q2.empty()) return true;
        return false;
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



//usong one queue
class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        int s = q.size();
        q.push(x);

        for(int i=0;i<s;i++){
            q.push(q.front());
            q.pop();
        }

    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.size()==0) reutn true;
        return false;
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