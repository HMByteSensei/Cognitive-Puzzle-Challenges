class MyStack {
    std::queue<int> red{};
    int topp = 0;
public:
    MyStack() {}
    
    void push(int x) {
        red.push(x);
        topp = x;
    }
    
    int pop() {
        int zzz=red.size()-2;
        for(int i=0; i<zzz; i++) {
            red.push(red.front());
            red.pop();
        }
        int elem = topp;
        topp = red.front();
        red.push(topp);
        red.pop();
        red.pop();
        return elem;
    }
    
    int top() {
        if(!empty()) return topp;
        return -1;
    }
    
    bool empty() {
        return red.empty();
    }
};
