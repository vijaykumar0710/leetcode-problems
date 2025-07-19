class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        unordered_set<string>st;
        vector<string>res;
        for(auto &subfolder:folder){
            string str="";
            bool flag=false;
            for(int i=0;i<subfolder.size();i++){
                while(i<subfolder.size() && subfolder[i]!='/'){
                    i++;
                }
                str=subfolder.substr(0,i);
                if(st.find(str)!=st.end()){
                    flag=true;
                }
            }
            if(flag==false){
                    st.insert(subfolder);
                    res.push_back(subfolder);
                }
        }
        return res;
    }
};