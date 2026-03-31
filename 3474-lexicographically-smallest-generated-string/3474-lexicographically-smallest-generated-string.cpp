class Solution {
public:
    string generateString(string str1, string str2) {
        int m = str2.size();
        string s(m-1,'1');
        for(int i = 0; i < str1.size(); i++) {
            s += '1';
            if(str1[i] == 'T') {
                int j = 0;
                while(j < str2.size()) {
                    if(s[i+j] =='1') s[i+j] = str2[j];
                    else{
                        if(s[i+j] != str2[j]) return ""; 
                    }
                    j++;
                }
            }
        }
        for(int i = 0; i < s.size(); i++) if(s[i] == '1') s[i] = 'a';
        int k = s.size();
        string r(k,'?');
        for(int i = 0; i < str1.size(); i++) {
            if(str1[i] == 'T') {
                int j = 0;
                while(j < m) {
                    r[i+j]='#';
                    j++;
                }
            }
        }
        for(int i = 0; i < str1.size(); i++) {
            if(str1[i] != 'T') {
                string sub = s.substr(i, m);
                if(sub == str2) {
                    int j = m-1;
                    bool change = false;
                    int count = 0;
                    while(j >= 0) {
                        if(r[i+j]=='?') {
                            if(s[i+j]=='a' && count < 1) {
                                count++;
                                s[i+j] = 'b';
                            }
                            else s[i+j]='a';
                            change = true;
                        }
                        j--;
                    }
                    if(!change) return "";
                }
            }
        }
        return s;
    }
};