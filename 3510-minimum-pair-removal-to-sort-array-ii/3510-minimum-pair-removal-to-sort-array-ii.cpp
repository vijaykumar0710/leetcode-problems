#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    long long val;
    long long pos; // position for order (taken as the left node's original position)
    int prev, next;
    bool valid;
};
 
struct Pair {
    long long sum;
    long long pos; // equal to left node's pos, used for tie-breaking (smaller pos = leftmost)
    int left;
    int right;
};
 
struct PairComparator {
    bool operator()(const Pair &a, const Pair &b) const {
        if(a.sum == b.sum) return a.pos > b.pos;
        return a.sum > b.sum;
    }
};
 
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;
        
        vector<Node> nodes;
        nodes.reserve(2 * n);
        // Initialize nodes for the original array.
        for (int i = 0; i < n; i++) {
            Node nd;
            nd.val = nums[i];
            nd.pos = i; // initial order position
            nd.prev = i - 1;
            nd.next = i + 1;
            nd.valid = true;
            nodes.push_back(nd);
        }
        nodes[n-1].next = -1;
 
        // Compute the initial count of adjacent violations (where left > right)
        long long badCount = 0;
        int head = 0;
        auto isViolation = [&](int i, int j) -> bool {
            return nodes[i].val > nodes[j].val;
        };
        for (int i = 0; i < n; i++) {
            int nxt = nodes[i].next;
            if(nxt != -1 && nodes[i].valid && nodes[nxt].valid) {
                if(isViolation(i, nxt)) badCount++;
            }
        }
 
        // Priority queue for adjacent pairs; each pair is (left, right)
        priority_queue<Pair, vector<Pair>, PairComparator> pq;
        for (int i = 0; i < n; i++) {
            int nxt = nodes[i].next;
            if(nxt != -1) {
                Pair p;
                p.sum = nodes[i].val + nodes[nxt].val;
                p.pos = nodes[i].pos;
                p.left = i;
                p.right = nxt;
                pq.push(p);
            }
        }
 
        int ops = 0;
        // Simulate the merges until the list becomes non-decreasing (badCount == 0)
        while(badCount > 0 && head != -1 && nodes[head].next != -1){
            Pair best;
            bool found = false;
            while(!pq.empty()){
                best = pq.top();
                pq.pop();
                // Validate the pair: both nodes must be valid and adjacent
                if(!nodes[best.left].valid || !nodes[best.right].valid) continue;
                if(nodes[best.left].next != best.right) continue;
                found = true;
                break;
            }
            if(!found) break; // Should not happen if list is unsorted and length >=2
 
            int L = best.left, R = best.right;
            long long newVal = nodes[L].val + nodes[R].val;
            long long newPos = nodes[L].pos; // new node takes the left node's pos
 
            Node newNode;
            newNode.val = newVal;
            newNode.pos = newPos;
            newNode.prev = nodes[L].prev;
            newNode.next = nodes[R].next;
            newNode.valid = true;
 
            int newIndex = nodes.size();
            nodes.push_back(newNode);
 
            int A = nodes[newIndex].prev; // left neighbor
            int B = nodes[newIndex].next; // right neighbor
 
            // Remove contributions of the pairs that will be lost.
            if(A != -1) {
                if(nodes[A].valid && nodes[L].valid && isViolation(A, L))
                    badCount--;
            }
            if(nodes[L].valid && nodes[R].valid && isViolation(L, R))
                badCount--;
            if(B != -1) {
                if(nodes[R].valid && nodes[B].valid && isViolation(R, B))
                    badCount--;
            }
 
            // Invalidate the merged nodes.
            nodes[L].valid = false;
            nodes[R].valid = false;
 
            // Reclink the neighbors.
            if(A != -1) {
                nodes[A].next = newIndex;
            } else {
                head = newIndex;
            }
            if(B != -1) {
                nodes[B].prev = newIndex;
            }
 
            // Create new adjacent pairs with the new node.
            if(A != -1) {
                Pair p;
                p.sum = nodes[A].val + nodes[newIndex].val;
                p.pos = nodes[A].pos;
                p.left = A;
                p.right = newIndex;
                pq.push(p);
                if(isViolation(A, newIndex))
                    badCount++;
            }
            if(B != -1) {
                Pair p;
                p.sum = nodes[newIndex].val + nodes[B].val;
                p.pos = nodes[newIndex].pos;
                p.left = newIndex;
                p.right = B;
                pq.push(p);
                if(isViolation(newIndex, B))
                    badCount++;
            }
 
            ops++;
        }
 
        return ops;
    }
};