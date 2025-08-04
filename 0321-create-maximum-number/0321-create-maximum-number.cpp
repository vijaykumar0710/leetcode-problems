class Solution {
public:
    vector<int> max_subs(vector<int>& vec, int t) {
        int n=vec.size();
        stack<int> st;
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && n - i-1 + st.size() >= t && st.top() < vec[i]) st.pop();
            st.push(vec[i]);
        }
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        temp.resize(t);
        return temp;
    }
    bool greater(vector<int>&vec1,int i,vector<int>&vec2,int j){
        int n1=vec1.size(),n2=vec2.size();  
        while(i<n1 && j<n2){
            if(vec1[i]>vec2[j]) return true;
            if(vec1[i]<vec2[j]) return false;
            i++;
            j++;
        }
        return i!=n1;
    }
    vector<int>merge(vector<int>&vec1,vector<int>&vec2){
        vector<int>res;
        int n1=vec1.size(),n2=vec2.size();  
        int i = 0, j = 0;
        while(i<n1 || j<n2){
        if(greater(vec1,i,vec2,j)){
             res.push_back(vec1[i]);
             i++;
           }else{
            res.push_back(vec2[j]);
            j++;
           }
        }
        return res;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int>res;
        for(int i=0;i<=k;i++){
            if(i<=n1 && k-i<=n2){ 
            auto part1=max_subs(nums1,i);
            auto part2=max_subs(nums2,k-i);
            auto ans=merge(part1,part2);
            res=max(res,ans);
            }
        }
        return res;
    }
};