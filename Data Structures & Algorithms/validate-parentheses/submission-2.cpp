class Solution {
public:
    bool isValid(string s) {
        stack<char> leftStack;

        for (auto &c:s) {
            if (c == '(' || c == '{' || c == '[')  {
                leftStack.push(c);
                continue;
            }

            if (leftStack.empty()) return false;
            
            auto last = leftStack.top();
            if (c == ')' && last == '(') {
                leftStack.pop();
            }
            else if (c == '}' && last == '{') {
                leftStack.pop();
            }
            else if (c == ']' && last == '[') {
                leftStack.pop();
            } else {
                return false;
            }
        }

        return !leftStack.size();
    }
};
