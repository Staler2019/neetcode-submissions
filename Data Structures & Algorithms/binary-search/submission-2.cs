public class Solution {
    private int SearchHelper(int[] nums, int target, int left, int right) {
        if (left > right) return -1;

        int mid = (left + right) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            return SearchHelper(nums, target, mid+1, right);
        } else {
            return SearchHelper(nums, target, left, mid-1);
        }
    }

    public int Search(int[] nums, int target) {
        int left = 0, right = nums.Count() -1;

        return SearchHelper(nums, target, left, right);
    }
}
