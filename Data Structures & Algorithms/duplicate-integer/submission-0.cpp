class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> set_n(nums.begin(), nums.end());

        return nums.size() != set_n.size();
    }
};