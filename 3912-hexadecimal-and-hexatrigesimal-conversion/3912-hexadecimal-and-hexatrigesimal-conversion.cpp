class Solution {
public:
unordered_map<int,char>mp;
void hexadec(int num,string &hexa){
    int n=num;
    while(n){
       int rem=n%16;
       if(rem>9) hexa+=mp[rem];
       else hexa+=to_string(rem);
       n/=16;
    }
    reverse(hexa.begin(),hexa.end());
}

void hexatr(int num,string &hexat){
    int n=num;
    while(n){
       int rem=n%36;
       if(rem>9) hexat+=mp[rem];
       else hexat+=to_string(rem);
       n/=36;
    }
    reverse(hexat.begin(),hexat.end());
}

    string concatHex36(int n) {
        int num=10;
        for(char i='A';i<='Z';i++){
            mp[num]=i;
            num++;
        }
        string hexa="";
        hexadec(n*n,hexa);
        string hexat="";
        hexatr(n*n*n,hexat); 
        return hexa+hexat;
    }
};