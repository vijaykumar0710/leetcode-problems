#include <vector>
#include <string>
#include <numeric>

using namespace std;

// Helper Class: Fenwick Tree (Binary Indexed Tree)
// Used for efficient Point Updates and Range Sum Queries.
class FenwickTree {
private:
    vector<int> tree;

public:
    // Fenwick Tree constructor. Size n is for 0-based indices 0 to n-1.
    FenwickTree(int n) {
        // Internal array size is n + 1 for 1-based indexing
        tree.resize(n + 1, 0); 
    }

    // Updates the value at 0-based index 'i' by 'delta'
    void update(int i, int delta) {
        // Convert to 1-based index
        i = i + 1; 
        while (i < tree.size()) {
            tree[i] += delta;
            i += i & (-i); // Move to the next relevant node
        }
    }

    // Returns the prefix sum from index 0 up to 'i' (inclusive)
    int query(int i) {
        // Convert to 1-based index
        i = i + 1;
        int sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= i & (-i); // Move to the parent node
        }
        return sum;
    }

    // Returns the sum in the range [left, right] (both inclusive)
    int query_range(int left, int right) {
        if (left > right) return 0;
        return query(right) - query(left - 1);
    }
};

class Solution {
public:
    /**
     * Solves the minDeletions problem using a Fenwick Tree.
     * The minimum number of deletions in s[l..r] is the count of adjacent equal characters 
     * in the range [l, r-1].
     */
    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        int n = s.length();
        
        // The Fenwick Tree tracks violations for indices 0 to n-2. 
        // A violation at index i means s[i] == s[i+1].
        // We initialize the BIT with a size for n-1 elements.
        FenwickTree bit(n - 1); 
        
        // Stores the current violation status for each index i (s[i] == s[i+1])
        vector<int> current_violations(n, 0); 
        
        // 1. Build initial state
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i+1]) {
                current_violations[i] = 1;
                bit.update(i, 1);
            }
        }
                
        vector<int> results;

        for (const auto& q : queries) {
            int type = q[0];
            
            if (type == 1) {
                // Type 1: Flip character at index j
                int idx = q[1];
                
                // Flip the character
                s[idx] = (s[idx] == 'A' ? 'B' : 'A');
                
                // The flip only affects the violation status at indices idx-1 and idx
                for (int i : {idx - 1, idx}) {
                    // Check if the violation index 'i' is valid (0 <= i < n-1)
                    if (i >= 0 && i < n - 1) {
                        
                        int old_val = current_violations[i];
                        int new_val = (s[i] == s[i+1] ? 1 : 0); // Check new status
                        
                        if (old_val != new_val) {
                            // The difference (delta) is +1 if a violation was created, -1 if resolved.
                            int delta = new_val - old_val;
                            bit.update(i, delta);
                            current_violations[i] = new_val;
                        }
                    }
                }
            } 
            else if (type == 2) {
                // Type 2: Compute minimum deletions for substring s[l..r]
                int l = q[1];
                int r = q[2];
                
                // The answer is the sum of violations in the index range [l, r-1].
                int res = bit.query_range(l, r - 1);
                results.push_back(res);
            }
        }
                
        return results;
    }
};