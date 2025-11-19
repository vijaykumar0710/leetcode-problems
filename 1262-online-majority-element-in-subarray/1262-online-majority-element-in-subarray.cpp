class MajorityChecker {
public:
int n;
unordered_map<int,vector<int>>pos;
    MajorityChecker(vector<int>& arr) {
      n=arr.size(); 
      for(int i=0;i<n;i++) pos[arr[i]].push_back(i); 
    }
    
    int query(int left, int right, int threshold) {
        for(auto &[num,vec]:pos){
            int freq=(upper_bound(vec.begin(),vec.end(),right)-vec.begin())-(lower_bound(vec.begin(),vec.end(),left)-vec.begin());
            if(freq>=threshold) return num;
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */