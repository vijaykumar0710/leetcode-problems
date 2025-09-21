class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>res;
        queue<int>q;
        for(int i=1;i<=9;i++) q.push(i);
        while(!q.empty()){
            int num=q.front();q.pop();
            if((int)log10(num)+1==n){
                res.push_back(num);
                continue;
            }
            for(int i=0;i<=9;i++){
                if(abs((num%10)-i)!=k) continue;
                q.push(num*10+i);
            }
        }
        return res;
    }
};