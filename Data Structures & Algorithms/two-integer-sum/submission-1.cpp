class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // // n^2
        // for(int i = 0; i < nums.size(); i++) {
        //     for(int j = i + 1; j < nums.size(); j++) {
        //         if (target == (nums[i] + nums[j])) return vector<int>{i, j};
        //     }
        // }

        // create mapper for item, change the finding way
        unordered_map<int, int> value_indexes;

        for (int i = 0; i < nums.size(); i++) {
            int remains = target - nums[i];
            auto it = value_indexes.find(remains);

            if (it != value_indexes.end()){
                return vector<int>{it->second, i};
            }

            value_indexes[nums[i]] = i;
        }

        return vector<int>{}; // should never be here;
    }
};
