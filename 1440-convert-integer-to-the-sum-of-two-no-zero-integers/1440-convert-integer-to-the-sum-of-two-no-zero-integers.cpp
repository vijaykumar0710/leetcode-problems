class Solution {
public:
bool isValid(int x){
    while(x){
     if(x%10==0) return false;
     x/=10;
    }
    return true;
}
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n;i++){
            if(isValid(i)&&isValid(n-i)){
                return {i,n-i};
            }
        }
        return {-1,-1};
    }
};