class Solution {
public:
vector<int>SPF;
int N=1e5+1;
void computeSPF(){
SPF.resize(N+1);
for(int i=1;i<=N;i++) SPF[i]=i;
for(int i=2;i*i<=N;i++){
    if(SPF[i]==i){
        for(int j=i*i;j<=N;j+=i) SPF[j]=i;
      }
   }
}

    int sumFourDivisors(vector<int>& nums) {
        computeSPF();
        int res=0;
        for(auto num:nums){
            int x=num;
            map<int,int>mp;
            while(x!=1){
             mp[SPF[x]]++;
             x/=SPF[x];
              }
            if(mp.size()==1){
                auto &[val,freq]=*mp.begin();
                if(freq==3) res=res+1+val+val*val+num;
            }
            else if(mp.size()==2){
                int temp=1+num;
                bool flag=true;
                for(auto &[val,freq]:mp){
                    if(freq>1) flag=false;
                     temp+=val;
                }
                if(flag) res=res+temp;
            }
        }
        return res;
    }
};