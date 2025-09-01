class Solution {
public:
typedef pair<double,int> p; 
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        priority_queue<p>pq;
        for(int i=0;i<n;i++){
            double current_pr=(double)classes[i][0]/classes[i][1];
            double new_pr=(double)(classes[i][0]+1)/(classes[i][1]+1);
            double delta=new_pr-current_pr;
            pq.push({delta,i});
        }
        while(extraStudents--){
            auto curr=pq.top();
            pq.pop();
            double delta=curr.first;
            int idx=curr.second;
            classes[idx][0]++;
            classes[idx][1]++;
            double current_pr=(double)classes[idx][0]/classes[idx][1];
            double new_pr=(double)(classes[idx][0]+1)/(classes[idx][1]+1);
            delta=new_pr-current_pr;
            pq.push({delta,idx});
        }
        double res=0.0;
        for(int i=0;i<n;i++){
            res+=(double)classes[i][0]/classes[i][1];
        }
        return res/n;
    }
};