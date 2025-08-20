class Solution {
public:
int MAH(vector<int>& h) {
        int n=h.size();
        vector<int>left_idx(n),right_idx(n);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && h[st.top()]>=h[i]) st.pop();
            left_idx[i]=st.empty()?-1:st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && h[st.top()]>=h[i]) st.pop();
            right_idx[i]=st.empty()?n:st.top();
            st.push(i);
        }

        int res=0;
        for(int i=0;i<n;i++){
            int left=left_idx[i];
            int right=right_idx[i];
            res=max(res,h[i]*(right-left-1));
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int res=0;
        vector<int>temp(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0') temp[j]=0;
                else temp[j]+=1;
            }
            res=max(res,MAH(temp));
        }
        return res;
    }
};