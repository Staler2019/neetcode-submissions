class Solution {
public:
    int trap(vector<int>& height)
    {
        int left = 0, right = (static_cast<int>(height.size()) - 1);
        int leftMax = 0, rightMax = 0, vol = 0;

        while (left < right) {

            if (height[left] > height[right]) {
                rightMax = max(rightMax, height[right]);
                vol += (rightMax - height[right]);
                right--;
            }
            else {
                leftMax = max(leftMax, height[left]);
                vol += (leftMax - height[left]);
                left++;
            }
        }
        return vol;
    }
};
