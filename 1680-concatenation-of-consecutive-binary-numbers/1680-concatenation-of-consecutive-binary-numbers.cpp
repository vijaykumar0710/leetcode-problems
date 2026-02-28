class Solution {
public:
const int M=1e9+7;
vector<int>pow_vec;
void power(int n){
    n=n*18;
    pow_vec.resize(n+1);
    pow_vec[0]=1;
  for(int i=1;i<=n;i++) pow_vec[i]=(pow_vec[i-1]%M*2%M)%M;
}
    int concatenatedBinary(int n) {
        power(n);
        int res=0;
        int p=0;
        while(n>=1){
        string str=bitset<17>(n).to_string();
        n--;
        str.erase(0, str.find_first_not_of('0'));
        int j=str.size()-1;
        while(j>=0){
            if(str[j]=='1'){
                res=(res+pow_vec[p])%M;
            }
            p++;
            j--;
          }
        }
        return res;
    }
};