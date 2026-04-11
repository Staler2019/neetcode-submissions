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
        vector<string> decoded;

        while(i < s.length()){
            string sizeStr = "";
            int j = i;
            do {
                sizeStr += s[j];
                j++;
            } while(s[j] !='#');

            j++;
            int size = stoi(sizeStr);
            string str = s.substr(j, size);
            decoded.push_back(str);
            i = j + size;
        }

        return decoded;
    }
};
