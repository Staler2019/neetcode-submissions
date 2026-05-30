class Solution {
public:
    int trap(vector<int>& height)
    {
        const int n = static_cast<int>(height.size());
        vector<int> frontMax(n, 0);
        vector<int> rearMax(n, 0);
        int vol = 0;

        for (int i = 1; i < n; i++) {
            frontMax[i] = max(frontMax[i - 1], height[i - 1]);
        }
        for (int i = (n - 2); i >= 0; i--) {
            rearMax[i] = max(rearMax[i + 1], height[i + 1]);
        }

        for (int i = 1; i < (n -1);i++){
            vol += max(0,min(frontMax[i], rearMax[i]) - height[i]);
        }
        return vol;
    }
};
