class Solution {
public:
    const int MOD = 1e9 + 7;
    using Matrix = vector<vector<long long>>;
    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < n; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }
    vector<long long> multiplyMatrixVector(const Matrix& A, const vector<long long>& v) {
        int n = A.size();
        vector<long long> res(n, 0);
        for (int i = 0; i < n; i++) {
            long long sum = 0;
            for (int j = 0; j < n; j++) {
                sum = (sum + A[i][j] * v[j]) % MOD;
            }
            res[i] = sum;
        }
        return res;
    }
    int zigZagArrays(int n, int l, int r) {
        int K = r - l + 1;
        if (n == 1) return K;
        int S = 2 * K;
        vector<long long> state(S, 0);
        for (int x = 0; x < K; x++) {
            state[x] = x;              
            state[K + x] = K - 1 - x;  
        }
        if (n == 2) {
            long long ans = 0;
            for (int i = 0; i < S; i++) {
                ans = (ans + state[i]) % MOD;
            }
            return ans;
        }
        Matrix T(S, vector<long long>(S, 0));
        for (int x = 0; x < K; x++) {
            for (int y = 0; y < x; y++) {
                T[x][K + y] = 1;
            }
        }
        for (int x = 0; x < K; x++) {
            for (int y = x + 1; y < K; y++) {
                T[K + x][y] = 1;
            }
        }
        long long power = n - 2;
        while (power > 0) {
            if (power & 1) {
                state = multiplyMatrixVector(T, state);
            }
            T = multiply(T, T);
            power >>= 1;
        }
        long long ans = 0;
        for (int i = 0; i < S; i++) {
            ans = (ans + state[i]) % MOD;
        }
        return ans;
    }
};