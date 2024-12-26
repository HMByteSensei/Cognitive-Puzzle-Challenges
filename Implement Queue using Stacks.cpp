static const bool __boost = []() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return std::ios_base::sync_with_stdio(false);
};

class MyQueue {
private:
    std::stack<int> sta;
    std::stack<int> sta2;
public:
    MyQueue() {}
    
    void push(int x) {
        sta.push(x);
    }
    
    int pop() {
        if(sta2.empty()) {
            while(!sta.empty()) {
                sta2.push(sta.top());
                sta.pop();
            }
        }
        int rez = sta2.top();
        sta2.pop();
        return rez;
    }
    
    int peek() {
        int rez = this->pop();
        sta2.push(rez);
        return rez;
    }
    
    bool empty() {
        return (sta.empty() && sta2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
