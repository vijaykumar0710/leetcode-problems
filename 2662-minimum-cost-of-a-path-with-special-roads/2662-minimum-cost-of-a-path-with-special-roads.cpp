class Solution {
public:
    vector<vector<int>> directions = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
    int minimumCost(vector<int>& start, vector<int>& target,
                    vector<vector<int>>& specialRoads) {
        int m = target[0];
        int n = target[1];
        map<pair<int, int>, int> t;
        t[{start[0], start[1]}] = 0;
        int res = abs(target[0] - start[0]) + abs(target[1] - start[1]);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        pq.push({0, start[0], start[1]});
        while (!pq.empty()) {
            auto vec = pq.top();
            pq.pop();
            int cost = vec[0];
            int x = vec[1], y = vec[2];
            res = min(res, cost+abs(x - target[0]) + abs(y - target[1]));
            for (auto r : specialRoads) {
                int x1 = r[0];
                int y1 = r[1];
                int x2 = r[2];
                int y2 = r[3];
                int c = r[4];
                int new_cost=cost+abs(x1-x)+abs(y-y1);
                if(!t.count({x2,y2}) || new_cost+c<t[{x2,y2}]){
                    t[{x2,y2}]=new_cost+c;
                    pq.push({c+new_cost,x2,y2});
                }
            }
        }
        return res;
    }
};