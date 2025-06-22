class Solution {
public:
    int primeSubarray(vector<int>& nums, int k) {
        const int MAX_VAL = 50001;
        vector<bool> isPrime(MAX_VAL, true);

        // Sieve of Eratosthenes
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <=MAX_VAL; i++) {
            if (isPrime[i]) {
                for (int j = 2; i*j <= MAX_VAL; j++) {
                    isPrime[i*j] = false;
                }
            }
        }

        int n = nums.size();
        vector<pair<int, int>> primes;  // (value, index)
        for (int i = 0; i < n; i++) {
            if (isPrime[nums[i]])
                primes.emplace_back(nums[i], i);
        }

        int m = primes.size();
        if (m < 2) return 0;

        // Left padding
        vector<long long> leftPad(m);
        for (int i = 0; i < m; i++) {
            int prevIndex = (i == 0 ? -1 : primes[i - 1].second);
            leftPad[i] = primes[i].second - prevIndex;
        }

        // Prefix sum of leftPad
        vector<long long> prefixSum(m);
        prefixSum[0] = leftPad[0];
        for (int i = 1; i < m; i++) {
            prefixSum[i] = prefixSum[i - 1] + leftPad[i];
        }

        long long total = 0;
        multiset<int> mst;  // Stores prime values (not pair)
        int l = 0;

        for (int r = 0; r < m; r++) {
            mst.insert(primes[r].first);  // Only insert value, not pair

            // Shrink window if prime gap exceeds k
            while (!mst.empty() && *mst.rbegin() - *mst.begin() > k) {
                mst.erase(mst.find(primes[l].first));
                l++;
            }

            if (mst.size() >= 2) {
                // Right padding
                long long rightPad = (r == m - 1) ?
                    (n - primes[r].second) :
                    (primes[r + 1].second - primes[r].second);

                // Sum of leftPads from l to r-1
                long long leftSum = prefixSum[r - 1];
                if (l > 0) leftSum -= prefixSum[l - 1];

                total += leftSum * rightPad;
            }
        }

        return total;
    }
};
