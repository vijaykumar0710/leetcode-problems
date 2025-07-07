class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        int last_day = 0;
        for (auto& event : events)
            last_day = max(last_day, event[1]);
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0, res = 0;
        for (int day = 1; day <= last_day; day++) {
            while (i < n && events[i][0] == day) {
                pq.push(events[i][1]);
                i++;
            }
            while (!pq.empty() && pq.top() < day)
                pq.pop();
            if (!pq.empty()) {
                res++;
                pq.pop();
            }
        }
        return res;
    }
};