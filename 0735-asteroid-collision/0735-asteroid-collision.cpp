class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n=ast.size();
        vector<int>res;
        stack<int>st;
        for(int i=0;i<n;i++){
            bool destroyed=false;
            if(ast[i]<0){
                while(!st.empty() && st.top()>0 && st.top()<abs(ast[i])) st.pop();
                if(!st.empty() && st.top()>0){
                   if(st.top()==abs(ast[i])) st.pop();
                    destroyed=true;
                } 
            }
            if(!destroyed) st.push(ast[i]);
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};