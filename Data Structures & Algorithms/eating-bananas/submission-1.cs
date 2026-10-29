public class Solution {
    public int MinEatingSpeed(int[] piles, int h) {
        int left = 1;
        int right = piles.Max();
        int minSpeed = right;

        while (left <= right)
        {

            int mid = (left + right) / 2;

            long time = 0;
            for (int i = 0; i < piles.Length; i++)
            {
                time += (int)Math.Ceiling((double)piles[i] / mid);
            }

            if (time > h)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
                minSpeed = mid;
            }
        }

        return minSpeed;
    }
}
