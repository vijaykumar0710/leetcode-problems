class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string str=to_string(n);
        sort(str.begin(),str.end());
        do{
            if(str[0]=='0') continue;
          int num=stoi(str);
          if(((num)&(num-1))==0) return true;
        }while(next_permutation(str.begin(),str.end()));
        return false;
    }
};