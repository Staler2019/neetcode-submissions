public class Solution {
    public int Search(int[] nums, int target) {
        int left = 0;
        int right = nums.Length - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        int pivot = left;

        if (nums[pivot] <= target && target <= nums[^1])
        {
            return BinarySearch(nums, target, pivot, nums.Length - 1);
        }
        
        return BinarySearch(nums, target, 0, pivot - 1);
    }

    private int BinarySearch(int[] nums, int target, int start, int end)
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target)
            {
                return mid;
            } else if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return -1;
    }
}
