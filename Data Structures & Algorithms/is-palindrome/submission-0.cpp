class Solution {

    string toLower(string s)
    {
        string rlt = "";
        for (auto& i : s) {
            rlt += tolower(i);
        }

        return rlt;
    }

public:

    bool isPalindrome(string s)
    {
        int front = 0, rear = s.length();
        s = toLower(s);

        while (front <= rear) {
            char& fc = s[front];
            char& rc = s[rear];

            if (!isalnum(fc)) {
                front++;
                continue;
            }

            if (!isalnum(rc)) {
                rear--;
                continue;
            }

            if (fc != rc) return false;
            front++;
            rear--;
        }
        return true;
    }
};
