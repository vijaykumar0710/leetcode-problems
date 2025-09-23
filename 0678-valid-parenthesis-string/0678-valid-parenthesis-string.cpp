class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        stack<int>openSt,asterSt;
        for(int i=0;i<n;i++){
            if(s[i]=='(') openSt.push(i);
            else if(s[i]=='*') asterSt.push(i);
            else{
                if(!openSt.empty()) openSt.pop();
                else if(!asterSt.empty()) asterSt.pop();
                else return false;
            }
        }
        while(!openSt.empty() && !asterSt.empty()){
            if(openSt.top()>asterSt.top()) return false;
            openSt.pop();
            asterSt.pop();
        }
        return openSt.empty();
    }
};