class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>pre(n,0);
        for(int i=0;i<bookings.size();i++){
          int st=bookings[i][0];
          int end=bookings[i][1];
          int seats=bookings[i][2];
          st--,end--;
          pre[st]+=seats;
         if(end+1<n) pre[end+1]-=seats;
        }
        for(int i=1;i<n;i++)
        pre[i]=pre[i]+pre[i-1];    
        return pre;
    }
};