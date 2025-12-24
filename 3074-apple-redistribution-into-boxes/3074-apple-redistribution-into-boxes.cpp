class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total=accumulate(apple.begin(),apple.end(),0);
        sort(capacity.rbegin(),capacity.rend());
        int sum=0;
        for(int i=0;i<capacity.size();i++){
         sum+=capacity[i];
         if(sum>=total) return i+1;
        }
        return -1;
    }
};