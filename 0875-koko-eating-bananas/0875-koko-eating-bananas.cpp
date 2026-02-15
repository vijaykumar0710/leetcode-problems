class Solution {
public:
int solve(vector<int>& piles,int mid,int h){
    long long hour=0;
    for(auto &pile:piles){
        hour+=(pile/mid);
        if(pile%mid!=0) hour++;
    }
    return hour<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1; // per hour min 1 kela kha skti hain
        // per hour max kha skti hain
        int r=*max_element(piles.begin(),piles.end());
        int res=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2; // itne kele per hour khila kar dekhta hu kitna samay legi
            if(solve(piles,mid,h)){
                res=mid; 
                r=mid-1;
            }else{
               l=mid+1;
            }
        }
        return res;
    }
};