class Solution {
public:
    vector<int> parent;

    // DSU find with path compression
    int find(int day) {
        if (parent[day] != day)
            parent[day] = find(parent[day]);
        return parent[day];
    }

    int maxEvents(vector<vector<int>>& events) {
        // Sort events by end time (greedy for earliest available day)
        sort(events.begin(), events.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        int max_day = 0;
        for (auto &e : events) max_day = max(max_day, e[1]);

        // Initialize DSU
        parent.resize(max_day + 2);
        for (int i = 0; i <= max_day + 1; i++) {
            parent[i] = i;
        }

        int count = 0;
        for (auto &e : events) {
            int start = e[0], end = e[1];
            int day = find(start);
            if (day <= end) {
                count++;
                // Mark this day as used
                parent[day] = find(day + 1);
            }
        }
        return count;
    }
};
