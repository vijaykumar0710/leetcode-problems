class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            int a=asteroids[i];
            if(a>0) st.push(a);
            else{
                while(!st.empty() && st.top()>0 && st.top()<abs(a))
                   st.pop();
                if(!st.empty() && st.top()==abs(a))
                   st.pop();
                else if(st.empty() || st.top()<0)
                  st.push(a);
            }
        }
        vector<int>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};