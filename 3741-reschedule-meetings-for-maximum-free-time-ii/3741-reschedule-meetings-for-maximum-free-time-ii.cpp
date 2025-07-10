class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = startTime.size();
        unordered_map<int, vector<pair<int, int>>> mp;
        mp[startTime[0] - 0].push_back({startTime[0], 0});
        mp[eventTime - endTime[n - 1]].push_back({endTime[n - 1], eventTime});
        for (int i = 1; i < n; i++) {
            int start = startTime[i];
            int end = endTime[i - 1];
            mp[start - end].push_back({end, start});
        }
        int res = 0;
        int prevEnd = 0;
        for (int i = 0; i < n; i++) {
            int currSt = startTime[i], currEnd = endTime[i], nextSt;
            if (i + 1 < n)
                nextSt = startTime[i + 1];
            else
                nextSt = eventTime;
            int Dur = currEnd - currSt;
            int temp = (currSt - prevEnd) + (nextSt - currEnd);
            prevEnd = currEnd;
            bool flag = false;
            for (auto& [key, vec] : mp) {
                if (key >= Dur) {
                    for (auto& [x, y] : vec) {
                        if (x != currSt && x != currEnd && y != currSt &&
                            y != currEnd) {
                            temp += Dur;
                            flag = true;
                            break;
                        }
                    }
                }
                if (flag == true)
                    break;
            }
            res = max(res, temp);
        }
        return res;
    }
};