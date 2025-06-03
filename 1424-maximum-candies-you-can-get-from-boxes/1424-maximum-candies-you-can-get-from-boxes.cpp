class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int ans=0;
        queue<int>q;
        unordered_set<int>boxes,key;
        for(auto &x:initialBoxes){
            if(status[x]==1) q.push(x);
            else{
                boxes.insert(x);
            }
        }
        while(!q.empty()){
            int z=q.front();
            q.pop();
            ans+=candies[z];
            for(auto &y:keys[z]){
                if(boxes.find(y)!=boxes.end()){
                    q.push(y);
                    boxes.erase(y);
                }
                key.insert(y);
            }
            for(auto &x:containedBoxes[z]){
            if(status[x]==1) q.push(x);
            else if(key.find(x)!=key.end()){
                q.push(x);
                key.erase(x);
            }else{
                boxes.insert(x);
              }
            }
        }
        return ans;
    }
};