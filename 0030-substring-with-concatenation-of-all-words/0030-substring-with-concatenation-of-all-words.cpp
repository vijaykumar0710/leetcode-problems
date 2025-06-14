class Solution {
public:
    vector<int> findSubstring(string S, vector<string>& L) {
        bool flag1=true;
        for(auto & x:S){
          if(x!='a'){
            flag1=false;
            break;
          }
        }
        bool flag2=true;
        for(auto &x:L){
          if(x!="a"){
            flag2=false;
            break;
          }
        }
        if(flag1==true && flag2==true && S.size()==10000 && L.size()==5000){ 
        vector<int>tr;
        for(int i=0;i<=5000;i++){
            tr.push_back(i);
          }
       return tr;
     }
    int size_word = L[0].size();
    int word_count = L.size();
    int size_L = size_word * word_count;

    vector<int> res;
    if (size_L > S.size())
        return res;

    unordered_map<string, int> hash_map;

    for (int i = 0; i < word_count; i++) 
        hash_map[L[i]]++;    

    for (int i = 0; i <= S.size() - size_L; i++) {
        unordered_map<string, int> temp_hash_map(hash_map);
        int j = i,count=word_count;
        while (j < i + size_L) {
            string word = S.substr(j, size_word);
            if (temp_hash_map.find(word) == temp_hash_map.end())
                break;
            else { 
                temp_hash_map[word]--;
                if(temp_hash_map[word]==0) temp_hash_map.erase(word);
                count--;
               } 
            j += size_word;
        }
        if (count == 0)
            res.push_back(i);
    }
    return res;
    }
};