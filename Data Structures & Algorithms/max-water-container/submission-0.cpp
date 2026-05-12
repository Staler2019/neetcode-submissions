class Solution {
public:
    int maxArea(vector<int>& heights)
    {
        int left = 0, right = static_cast<int>(heights.size()) - 1;
        int result = 0;

        while (right > left) {
            int width = right - left;

            if (heights[left] > heights[right]) {
                result = max(result, heights[right] * width);
                right--;
            }
            else {
                result = max(result, heights[left] * width);
                left++;
            }
        }

        return result;
    }
};
