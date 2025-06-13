class Solution {
public:
    int minMaxDifference(int num) {
        vector<int>temp;
        int d=num;
        while(d){
            temp.push_back(d%10);
            d/=10;
        }
        int n=temp.size();
        reverse(temp.begin(),temp.end());
        vector<int>v1,v2;
        for(auto &x:temp){
            v1.push_back(x);
            v2.push_back(x);
        }
        int lar,sm;
        long long larger=0,smaller=0;
        for(int i=0;i<n;i++){
            if(v1[i]!=9){ 
                lar=v1[i];
             break;
            }
        }
        for(int i=0;i<n;i++){
            if(v2[i]!=0){
                sm=v2[i];
            break;
            }
        }
        for(int i=0;i<n;i++){
            if(v1[i]==lar) v1[i]=9;
            if(v2[i]==sm) v2[i]=0;
        }
        cout<<v1[n-1]<<endl;
         for(int i=0;i<n;i++){
            larger=larger*10+v1[i];
            smaller=smaller*10+v2[i];
        }
        cout<<larger<<endl;
        cout<<smaller;
        return larger-smaller;
    }
};