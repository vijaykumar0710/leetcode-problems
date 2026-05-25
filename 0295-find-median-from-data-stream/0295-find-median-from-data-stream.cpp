class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> pq1;
    priority_queue<int> pq2;
    MedianFinder() {}

    void addNum(int num) {
       if(pq2.empty() || num<pq2.top()) pq2.push(num);
       else pq1.push(num);
       if(pq2.size()>pq1.size()+1){
        pq1.push(pq2.top());
        pq2.pop();
       }
       if(pq1.size()>pq2.size()+1){
        pq2.push(pq1.top());
        pq1.pop();
       }
    }

    double findMedian() {
        int m = pq1.size();
        int n = pq2.size();
        if ((m + n) % 2) {
            if (pq1.size() > pq2.size())
                return pq1.top();
            return pq2.top();
        } else {
            return double(pq1.top() + pq2.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */