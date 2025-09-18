class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int>pq;
        if(amount[0]!=0) pq.push(amount[0]);
        if(amount[1]!=0) pq.push(amount[1]);
        if(amount[2]!=0) pq.push(amount[2]);
        if(pq.size()==0) return 0;
        if(pq.size()<=2) return pq.top();
        int res=0;
        while(true){
           if(pq.size()<=2) return res+pq.top();
           int x=pq.top();
           pq.pop();
           int y=pq.top();
           pq.pop();
           x--,y--;
           res++;
           if(x!=0) pq.push(x);
           if(y!=0) pq.push(y);
        }
        return res;
    }
};