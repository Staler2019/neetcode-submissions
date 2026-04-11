class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // n^2
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if (target == (nums[i] + nums[j])) return vector<int>{i, j};
            }
        }
        return vector<int>{}; // should never be here;
    }
};
