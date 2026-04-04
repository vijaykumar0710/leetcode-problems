class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if(encodedText.empty())return "";
        string ans="";
        int len=encodedText.length();
        int cols=len/rows;
        bool flag=false;
        int i=0;
        int cnt=0;
        for(;i<len;i++){   
            int temp=i;
            while(temp<len){
                ans+=encodedText[temp];
                temp+=cols+1;
                cnt++;
            }
            if(cnt==len)break;
        }
        i=len-1;
        while(ans[i--]==' ')ans.pop_back();
        return ans;
    }
};