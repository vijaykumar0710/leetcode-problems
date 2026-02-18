class Solution {
public:
    bool hasAlternatingBits(int n) {
        string st=bitset<32>(n).to_string();
        st.erase(0,st.find_first_not_of('0'));
        bool toggle;
        if(st[0]=='0') toggle=false;
        else toggle=true;
        for(int i=1;i<st.size();i++){
            if((toggle && st[i]=='1') || (!toggle && st[i]=='0')) return false;
            toggle=!toggle;
        }
        return true;
    }
};