class Solution {
public:
    long long maxArea(vector<vector<int>>& pts) {
         long long maxArea = -1LL;
        
        if (pts.size() < 3) {
            return -1LL;
        }

        std::map<int, std::pair<int, int>> xMap; // {x: {min_y, max_y}}
        std::map<int, std::pair<int, int>> yMap; // {y: {min_x, max_x}}

        int minX = std::numeric_limits<int>::max();
        int maxX = std::numeric_limits<int>::min();
        int minY = std::numeric_limits<int>::max();
        int maxY = std::numeric_limits<int>::min();

        for (const auto& p : pts) {
            int x = p[0];
            int y = p[1];

            minX = std::min(minX, x);
            maxX = std::max(maxX, x);
            minY = std::min(minY, y);
            maxY = std::max(maxY, y);

            if (xMap.find(x) == xMap.end()) {
                xMap[x] = {y, y};
            } else {
                xMap[x].first = std::min(xMap[x].first, y);
                xMap[x].second = std::max(xMap[x].second, y);
            }

            if (yMap.find(y) == yMap.end()) {
                yMap[y] = {x, x};
            } else {
                yMap[y].first = std::min(yMap[y].first, x);
                yMap[y].second = std::max(yMap[y].second, x);
            }
        }

        for (const auto& entry : yMap) {
            int yVal = entry.first;
            int minXOnY = entry.second.first;
            int maxXOnY = entry.second.second;

            long long baseLen = maxXOnY - minXOnY;
            if (baseLen == 0) continue;

            long long h1 = std::abs(minY - yVal);
            long long h2 = std::abs(maxY - yVal);
            long long maxH = std::max(h1, h2);

            if (maxH == 0) continue;

            maxArea = std::max(maxArea, baseLen * maxH);
        }

        for (const auto& entry : xMap) {
            int xVal = entry.first;
            int minYOnX = entry.second.first;
            int maxYOnX = entry.second.second;

            long long baseLen = maxYOnX - minYOnX;
            if (baseLen == 0) continue;

            long long h1 = std::abs(minX - xVal);
            long long h2 = std::abs(maxX - xVal);
            long long maxH = std::max(h1, h2);
            
            if (maxH == 0) continue;

            maxArea = std::max(maxArea, baseLen * maxH);
        }

        return maxArea;
    }
};