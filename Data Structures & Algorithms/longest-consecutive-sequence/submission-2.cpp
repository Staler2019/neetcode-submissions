class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        #define all(a) std::begin(a), std::end(a)

        // o(n)
        int lengthMax = 0;
        unordered_set ns(all(nums));

        for(int n: ns) {
            int length = 1;
            int findN = n - 1;
            while (ns.find(findN) != ns.end()) {
                length++;
                findN--;
            }
            lengthMax = max(lengthMax, length);
            length = 1;
        }

        return lengthMax;
    }
};
