class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        stack<int>time;
        stack<char>color;
        color.push(colors[0]);
        time.push(neededTime[0]);
        int cnt=0;
        for(int i=1;i<n;i++){
          if(colors[i]==color.top()){
            if(time.top()<neededTime[i]){
                cnt+=time.top();
                time.pop();
             }else{
                cnt+=neededTime[i];
                continue;
             }
           }
           time.push(neededTime[i]);
           color.push(colors[i]);
        }
        return cnt;
    }
};