class MinStack {
    static constexpr int STACK_MAX = 30002;
    int _st[STACK_MAX];
    int _minSt[STACK_MAX];
    int _size = 0;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (_size < STACK_MAX) {
            _st[_size] = val;
            _minSt[_size] = _size == 0 ? val : min(_minSt[_size - 1], val) ;
            _size++;
        }
    }
    
    void pop() {
        if (_size > 0) {
            _size--;
        }
    }
    
    int top() {
        return _st[_size - 1];
    }
    
    int getMin() {
        return _minSt[_size - 1];
    }
};
