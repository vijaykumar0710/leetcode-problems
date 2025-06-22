class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        int n=coords.size();
        if(n<3) return -1LL;
        int minX=INT_MAX,minY=INT_MAX,maxX=-1,maxY=-1;
        unordered_map<int,pair<int,int>>mp_x_to_y; // x->{min_y,max_y}on this x
        unordered_map<int,pair<int,int>>mp_y_to_x; //y->{min_x,max_x} on this y
        for(auto &cor:coords){
            int x=cor[0];
            int y=cor[1];
            minX=min(minX,x);
            minY=min(minY,y);
            maxX=max(maxX,x);
            maxY=max(maxY,y);
            if(mp_x_to_y.find(x)==mp_x_to_y.end()){
              mp_x_to_y[x]={y,y};
            }else{
              mp_x_to_y[x].first=min(mp_x_to_y[x].first,y);
              mp_x_to_y[x].second=max(mp_x_to_y[x].second,y);
            }
             if(mp_y_to_x.find(y)==mp_y_to_x.end()){
              mp_y_to_x[y]={x,x};
            }else{
              mp_y_to_x[y].first=min(mp_y_to_x[y].first,x);
              mp_y_to_x[y].second=max(mp_y_to_x[y].second,x);
            }
        }
       long long maxArea=-1LL;
       // processing vertical base
       for(auto &entry:mp_x_to_y){
        int key=entry.first;
        int y_min=entry.second.first;
        int y_max=entry.second.second;
        long long base=y_max-y_min;
        if(base==0) continue;
        long long h1=abs(minX-key);
        long long h2=abs(maxX-key);
        long long maxH=max(h1,h2);
       if(maxH==0) continue;
       maxArea=max(maxArea,base*maxH);
       }
      //processing horizontal base
      for(auto &entry:mp_y_to_x){
        int key=entry.first;
        int x_min=entry.second.first;
        int x_max=entry.second.second;
        long long base=x_max-x_min;
        if(base==0) continue;
        long long h1=abs(minY-key);
        long long h2=abs(maxY-key);
       long long maxH=max(h1,h2);
       if(maxH==0) continue;
       maxArea=max(maxArea,base*maxH);
       }
       return maxArea;
    }
};