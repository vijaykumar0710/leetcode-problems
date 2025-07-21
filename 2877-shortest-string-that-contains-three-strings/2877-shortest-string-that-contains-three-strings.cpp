class Solution {
public:
    int get_overlap(string &a, string &b){
        int min_len=min(a.size(),b.size());
        int max_overlap=0;
        for(int i=1;i<=min_len;i++){
            if(a.substr(a.size()-i)==b.substr(0,i))
                 max_overlap=i;
        }
        return max_overlap;
    }
    string merge(string &a,string &b){
        if (a.find(b) != string::npos) return a;
        int overlap=get_overlap(a,b);
        return a+b.substr(overlap);
    }
    string minimumString(string a, string b, string c) {
        vector<string>vec={a,b,c};
        sort(vec.begin(),vec.end());
       string res=a+b+c;
       do{
         string first_merge=merge(vec[0],vec[1]);
         string final_merge=merge(first_merge,vec[2]);
         if(final_merge.size()<res.size() || (final_merge.size()==res.size() && final_merge<res)){ 
            res=final_merge;
         }
       }while(next_permutation(vec.begin(),vec.end()));

       return res;
    }
};