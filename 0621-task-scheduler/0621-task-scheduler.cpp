class Solution {
public:
void formed_freq(vector<char>&tasks,priority_queue<int>&pq){
    vector<int>freq(26,0);
    for(auto &ch:tasks) freq[ch-'A']++;
    for(auto &f:freq){
       if(f>0) pq.push(f);
    }
}

  int calculate_ans(priority_queue<int>&pq,int n){
    int ans=0;
    while(!pq.empty()){
      vector<int>temp;
      for(int i=1;i<=n+1;i++){
        if(!pq.empty()){
          int val=pq.top();
          val--;
          temp.push_back(val);
          pq.pop();
        }
      }
      for(auto &x:temp)
        if(x>0) pq.push(x);

     if(pq.empty()) ans+=temp.size();
     else ans+=(n+1);
    }
    return ans;
  }

    int leastInterval(vector<char>& tasks, int n) {
    priority_queue<int>pq;
    formed_freq(tasks,pq);

    return calculate_ans(pq,n);
    }
};