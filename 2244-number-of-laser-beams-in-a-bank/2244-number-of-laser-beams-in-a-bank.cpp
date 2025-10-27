class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size(),res=0;
        vector<int>beam;
        for(auto &x:bank){
           int ones=count(x.begin(),x.end(),'1');
           if(ones!=0) beam.push_back(ones);
        }
      if(beam.empty()) return 0;
      for(int i=0;i<beam.size()-1;i++){
        res+=(beam[i]*beam[i+1]);
      }
      return res;
    }
};