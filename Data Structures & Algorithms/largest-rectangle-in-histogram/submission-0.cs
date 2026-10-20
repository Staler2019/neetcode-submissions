public class Solution {
    public int LargestRectangleArea(int[] heights) {
        heights = heights.Append(0).ToArray();
        Stack<int> st = new Stack<int>();
        int ans = 0;

        for (int i = 0; i < heights.Count(); i++) {
            while(st.TryPeek(out var peekIdx) && heights[peekIdx] >= heights[i]){
                int h = heights[peekIdx];
                st.Pop();

                int left = st.TryPeek(out var leftPeekIdx) ? leftPeekIdx : -1;
                ans = Math.Max(ans, h * (i- left - 1));
            }
            st.Push(i);
        }

        return ans;
    }
}
