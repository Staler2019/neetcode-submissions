class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (!nums.size()) return 0;

        #define all(a) std::begin(a), std::end(a)

        // o(nlong(n))
        int lengthMax = 1;
        sort(all(nums));
        // int currIndex = 0;
        int cntIndex = 1;
        for (int i = 1; i < nums.size(); i++) {
            if ((nums[i] - nums[i - 1]) > 1) {
                lengthMax = max(lengthMax, cntIndex);
                cntIndex = 1;
                // currIndex = i;
            }
            if ((nums[i] - nums[i - 1]) == 1) cntIndex++;
        }
        lengthMax = max(lengthMax, cntIndex);

        return lengthMax;
    }
};
