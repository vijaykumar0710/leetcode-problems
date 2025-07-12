class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<long long> rooms(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            occupiedRoom;
        priority_queue<int, vector<int>, greater<int>> freeRoom;
        for (int i = 0; i < n; i++)
            freeRoom.push(i);
        for (auto& meet : meetings) {
            long long start = meet[0];
            long long end = meet[1];
            while (!occupiedRoom.empty() && start >= occupiedRoom.top().first) {
                freeRoom.push(occupiedRoom.top().second);
                occupiedRoom.pop();
            }
            if (!freeRoom.empty()) {
                int free = freeRoom.top();
                freeRoom.pop();
                rooms[free]++;
                occupiedRoom.push({end, free});
            } else {
                auto [finish, room_no] = occupiedRoom.top();
                occupiedRoom.pop();
                rooms[room_no]++;
                occupiedRoom.push({finish + end - start, room_no});
            }
        }
        long long room = -1, idx = -1;
        for (int i = 0; i < n; i++) {
            if (rooms[i] > room) {
                idx = i;
                room = rooms[i];
            }
        }
        return idx;
    }
};
