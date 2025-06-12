class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        unordered_map<int,int>initial_pos;
        for(int i=0;i<n;i++){
            initial_pos[positions[i]]=i;
        }
        vector<int>temp(n);
        for(int i=0;i<n;i++){
            char dir=directions[i];
            if(dir=='R') temp[i]=healths[i];
            else temp[i]=-1*healths[i];
        }
        vector<pair<int,int>>pairs;
        for(int i=0;i<n;i++){
            pairs.push_back({positions[i],temp[i]});
        }
        sort(pairs.begin(),pairs.end());
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){
            auto p=pairs[i];
            int a=p.second;
            if(a>0) st.push(p);
            else{
                while(!st.empty() && st.top().second>0 && st.top().second<abs(a)){ 
                      st.pop();
                      a++;
                }
                if(!st.empty() && st.top().second==abs(a))
                     st.pop();
                else if(!st.empty() && st.top().second>abs(a)){ 
                    auto p=st.top();
                    int y=p.second;
                    int x=p.first;
                     st.pop();
                     y--;
                     st.push({x,y});
                }
                else if(st.empty() || st.top().second<0)
                    st.push({p.first,a});
            }
        }
        vector<int>res;
        vector<int>tamp(n);
        while(!st.empty()){
            auto p=st.top();
            st.pop();
            int pos=p.first;
            int health=abs(p.second);
            if(initial_pos.find(pos)!=initial_pos.end()){
               tamp[initial_pos[pos]]=health;
            }
        }
        for(auto &x:tamp){
            if(x!=0)
            res.push_back(abs(x));
        }
        return res;
    } 
};