class Solution {
public:
int n1;
map<pair<int,int>,int>t;
int f(int i,int prev,vector<int>& arr1,vector<int>& arr2){
    if(i>=n1) return 0;
    if(t.count({i,prev})) return t[{i,prev}];
    int op1=1e9+1,op2=1e9+1;
    if(prev<arr1[i]) op1=f(i+1,arr1[i],arr1,arr2); 
    auto it=upper_bound(begin(arr2),end(arr2),prev);
    if(it!=end(arr2)){
    op2=1+f(i+1,*it,arr1,arr2);
    } 
    return t[{i,prev}]=min(op1,op2);
}
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        n1=arr1.size();
        sort(arr2.begin(),arr2.end());
        int res=f(0,-1,arr1,arr2);
        return res==1e9+1?-1:res;
    }
};