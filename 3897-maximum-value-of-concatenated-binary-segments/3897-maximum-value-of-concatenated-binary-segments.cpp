class Solution {
public:
    const int M = 1e9 + 7;
        long long power(long long a, long long b) {
        long long res = 1;
        a %= M;
        while (b > 0) {
            if (b % 2 == 1) res = (res * a) % M;
            a = (a * a) % M;
            b /= 2;
        }
        return res;
    }
    static vector<long long> normalize(long long a, long long b, long long c) {
        long long arr[3] = {a, b, c};
        sort(arr, arr + 3); 
        
        if (arr[0] == arr[1] && arr[1] == arr[2]) {
            return {arr[0] + 1, arr[0]};
        } else if (arr[0] == arr[1]) {
            long long x = arr[0] + 1;
            long long y = arr[2];
            if (x == y) return {x + 1};
            else return {max(x, y), min(x, y)};
        } else if (arr[1] == arr[2]) {
            long long x = arr[0];
            long long y = arr[1] + 1;
            return {max(x, y), min(x, y)};
        } else {
            return {arr[2], arr[1], arr[0]}; 
        }
    }
   static bool compareSegs(const pair<int, int>& A, const pair<int, int>& B) {
        long long LA = A.first + A.second;
        long long LB = B.first + B.second;
        long long zA = A.second;
        long long zB = B.second;
        vector<long long> LHS = normalize(LA + zB, LB, zA);
        vector<long long> RHS = normalize(LB + zA, LA, zB);       
        for (int i = 0; i < min(LHS.size(), RHS.size()); i++) {
            if (LHS[i] != RHS[i]) {
                return LHS[i] > RHS[i];
            }
        }
        return LHS.size() > RHS.size();
    }
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n = nums1.size();
        vector<pair<int, int>> nums;
            for (int i = 0; i < n; i++) {
            nums.push_back({nums1[i], nums0[i]});
        }
        sort(nums.begin(), nums.end(), compareSegs);
        long long res = 0;
        for (int i = 0; i < n; i++) {
            int ones = nums[i].first;
            int zeros = nums[i].second;
                if (ones > 0) {
                long long p_ones = power(2, ones);
                res = (res * p_ones) % M;
                res = (res + p_ones - 1 + M) % M; 
            }
            if (zeros > 0) {
               long long p_zeros = power(2, zeros);
               res = (res * p_zeros) % M;
            }
        }
        return res;
    }
};