class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnts;
        int maxCnt = 0;
        for(auto& num:nums){
            // cnts[num]++;
            maxCnt = max(maxCnt, ++cnts[num]);
        }

        vector<vector<int>> freq(maxCnt, vector<int>(0));

        for(auto& cnt: cnts) {
            // remember the count always > 0 so, the index 0 won't be used
            freq[cnt.second-1].emplace_back(cnt.first);
        }

        vector<int> res;
        for(int i = freq.size()-1; i >=0 && k; i--) {
            for (auto& num: freq[i]){
                if (k){
                    res.push_back(num);
                    k--;
                } else {
                    break;
                }
            }
        }

        return res;
    }
};
