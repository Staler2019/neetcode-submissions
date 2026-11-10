public class TimeMap {

    Dictionary<string, List<(int TimeStamp, string Value)>> _keyTimeValues;

    public TimeMap() {
        this._keyTimeValues = new Dictionary<string, List<(int TimeStamp, string Value)>>();
    }
    
    public void Set(string key, string value, int timestamp) {
        if (!this._keyTimeValues.ContainsKey(key))
        {
            this._keyTimeValues.Add(key, new List<(int TimeStamp, string Value)>());
        }
        this._keyTimeValues[key].Add((timestamp, value));
    }

    public string Get(string key, int timestamp)
    {
        if (!this._keyTimeValues.TryGetValue(key, out List<(int TimeStamp, string Value)> list))
        {
            return "";
        }

        int left = 0;
        int right = list.Count - 1;
        int result = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int midTimeStamp = list[mid].TimeStamp;

            if (midTimeStamp > timestamp)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
                result = mid;
            }
        }
        
        return result >= 0 ? list[result].Value : "";
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.Set(key,value,timestamp);
 * string param_2 = obj.Get(key,timestamp);
 */