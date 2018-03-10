class MinStack {
private:
    vector<pair<int,int>> stack;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x){
        int minVal = stack.empty() ? x : min(getMin(), x);
        stack.push_back(make_pair(x, minVal));
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack.back().first; 
    }
    
    int getMin() {
        return stack.back().second;
    }
};