class Solution {
    vector<int> allZero (int size) {
        return vector<int>(size,0 );
    }

public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int nSize = nums.size();
        int zeroCnt = 0;
        vector<int> pre(nSize, 1);
        vector<int> post(nSize, 1);
        vector<int> result(nSize);

        for (auto& n : nums) {
            if (!n) zeroCnt++;
        }

        if (zeroCnt >= 2) return allZero(nSize);

        for (int i = 1; i < nSize; i++) {
            pre[i] = pre[i - 1] * nums[i - 1];
        }

        for (int i = nSize-2; i >= 0; i--) {
            post[i] = post[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < nSize; i++) {
            result[i] = pre[i] * post[i];
        }

        return result;
    }
};
