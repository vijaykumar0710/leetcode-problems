class Solution {
public:
    vector<int> parent;
    int find(int day) {
        if (parent[day] == day) return parent[day];
        return parent[day] = find(parent[day]);
    }
void Union(int x,int y){
    parent[x]=y;
}
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        int max_day = 0;
        for (auto &e : events) max_day = max(max_day, e[1]);
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
                Union(day,day+1);
            }
        }
        return count;
    }
};
