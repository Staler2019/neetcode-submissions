class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> strs_map;

        for (auto& str: strs) {
            vector<int> str_cnt(26, 0);
            
            for (auto& c: str) {
                str_cnt[c-'a']++;
            }

            string key = "";
            for(int i = 0; i < str_cnt.size(); i++){
                key += str_cnt[i];
            }
            // cout << key << "\t" << str << endl;

            strs_map[key].emplace_back(str);
        }

        vector<vector<string>> result;
        for(auto& it: strs_map) {
            result.emplace_back(it.second);
        }

        return result;
    }
};
