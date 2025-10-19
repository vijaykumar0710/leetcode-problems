class Solution {
public:
vector<pair<int,int>>pairs;
void pairs_cal(vector<int>& arr, int target) {
    int n=arr.size();
    int sum = 0, i = 0;
    pairs.clear();

    for (int j = 0; j < n; j++) {
        sum += arr[j];

        while (sum > target && i <= j) {
            sum -= arr[i];
            i++;
        }

        if (sum == target) {
            pairs.push_back({i, j});
        }
    }
}


  int minTwoNonOverlap(vector<pair<int,int>>& ranges) {
    int n = ranges.size();
    if (n < 2) return -1;

    vector<int> len(n);
    for (int i = 0; i < n; i++)
        len[i] = ranges[i].second - ranges[i].first + 1;

    vector<pair<pair<int,int>,int>> byStart; 
    for (int i = 0; i < n; i++)
        byStart.push_back({ranges[i], len[i]});
    sort(byStart.begin(), byStart.end(),
         [](auto &a, auto &b){ return a.first.first < b.first.first; });

   
    vector<pair<pair<int,int>,int>> byEnd = byStart;
    sort(byEnd.begin(), byEnd.end(),
         [](auto &a, auto &b){ return a.first.second < b.first.second; });

    int j = 0;
    int minLeftLen = INT_MAX; 
    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {
        int start_i = byStart[i].first.first;
        int len_i   = byStart[i].second;

        while (j < n && byEnd[j].first.second < start_i) {
            minLeftLen = min(minLeftLen, byEnd[j].second);
            j++;
        }

        if (minLeftLen != INT_MAX)
            ans = min(ans, len_i + minLeftLen);
    }

    return (ans == INT_MAX ? -1 : ans);
}
    int minSumOfLengths(vector<int>& arr, int target) {
        int res=INT_MAX;
        pairs_cal(arr,target);
        return minTwoNonOverlap(pairs);
    }
};