class Solution {
public:
    bool isValid(string s) {
        stack<char> chars;

        for(char c : s) {
            switch (c) {
                case '(':
                case '{':
                case '[': {
                    chars.push(c);
                    break;
                }
                case ')': {
                    if (!chars.empty() && chars.top() == '(') {
                        chars.pop();
                    } else {
                        return false;
                    }
                    break;
                }
                case '}': {
                    if (!chars.empty() && chars.top() == '{') {
                        chars.pop();
                    } else {
                        return false;
                    }
                    break;
                }
                case ']': {
                    if (!chars.empty() && chars.top() == '[') {
                        chars.pop();
                    } else {
                        return false;
                    }
                    break;
                }
            }
        }

        return chars.empty();
    }
};
