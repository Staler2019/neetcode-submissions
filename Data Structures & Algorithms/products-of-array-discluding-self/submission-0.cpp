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
            int& nf = nums[i-1];
            int& ne = nums[nSize - i];

            pre[i] = pre[i - 1] * nf;
            post[i] = post[i - 1] * ne;
        }

        for (int i = 0; i < nSize; i++) {
            result[i] = pre[i] * post[nSize - i - 1];
        }

        return result;
    }
};
