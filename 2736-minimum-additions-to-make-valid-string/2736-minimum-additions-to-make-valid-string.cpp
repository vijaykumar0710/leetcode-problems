class Solution {
public:
    int addMinimum(string s) {
        int n=s.size();
        int cnt=0;
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                if(!st.empty() && st.top()=='a'){ st.push('b');st.push('c');cnt+=2;}
                else if( !st.empty() && st.top()=='b'){ st.push('c');cnt++;}
                st.push(s[i]);
            }else if(s[i]=='b'){
                if(st.empty()){ st.push('a');cnt++; }
                else if(st.top()=='b'){ st.push('c');st.push('a');cnt+=2; }
                else if(st.top()=='c') { st.push('a');cnt++;}
                st.push(s[i]);
            }else{
                if(st.empty()){ st.push('a');st.push('b');cnt+=2;}
                else if(st.top()=='a'){ st.push('b'); cnt++;}
                else if(st.top()=='c'){ st.push('a');st.push('b');cnt+=2;}
                st.push(s[i]);
            }
        }
        if(st.top()=='a') cnt+=2;
        else if(st.top()=='b') cnt++;
        return cnt;
    }
};