public class Solution {
    public int[] DailyTemperatures(int[] temperatures) {
        var temperatureCnt = temperatures.Length;
        var resultList = new int[temperatureCnt];
        var st = new Stack<int>();

        for (int i = 0 ; i < temperatureCnt; i++) {
            while(st.Count != 0 && temperatures[st.Peek()] < temperatures[i]) {
                int idx = st.Pop();
                resultList[idx] = i-idx;
            }
            st.Push(i);
        }

        return resultList.ToArray();
    }
}
