class Solution {


public:
    string encode(vector<string>& strs) {
        string encoded = "";
        for (auto& str: strs) {
            int size = str.length();
            string sizeStr = to_string(size);
            encoded += sizeStr + '#' + str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        int i = 0;
        int sLen = s.length();
        vector<string> decoded;

        while(i < sLen){
            
            int j = i;
            while(j < sLen && s[j] != '#') {
                j++;
            } 

            string sizeStr = s.substr(i, j-i);
            int size = stoi(sizeStr);

            j++;
            string str = s.substr(j, size);
            decoded.push_back(str);

            i = j + size;
        }

        return decoded;
    }
};
