public class Solution {
    public int[] DailyTemperatures(int[] temperatures) {
        int n = temperatures.Length;
        var result = new int[n];
        var st = new Stack<(int Num, int Idx)>();

        for (int i = 0; i < n; i++) {

            // count
            while (st.TryPeek(out var top) && top.Num < temperatures[i])
            {
                st.Pop();
                result[top.Idx] = i - top.Idx;
            }
            st.Push((temperatures[i], i));
        }

        return result;
    }
}
