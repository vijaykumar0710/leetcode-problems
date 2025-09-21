class Solution {
public:
vector<int>res;
void f(int &num,int n,int k){
    if((int)log10(num)+1==n){ res.push_back(num); return; }
    for(int j=0;j<=9;j++){
        int last_digit=num%10;
        if(abs(last_digit-j)!=k) continue;
        num=num*10+j;
        f(num,n,k);
        num=num/10;
    }
}
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<=9;i++) f(i,n,k);
        return res;
    }
};