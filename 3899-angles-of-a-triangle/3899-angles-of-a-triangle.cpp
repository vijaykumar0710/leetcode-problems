class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        vector<double>res;
        int a=sides[0],b=sides[1],c=sides[2];
        if(a+b<=c || a+c<=b || b+c<=a) return {};
        double pi = acos(-1.0);
        double A=acos((b*b+c*c-a*a)/(2.0*b*c))*(180.0/pi);
        double B=acos((a*a+c*c-b*b)/(2.0*a*c))*(180.0/pi);
        double C=acos((a*a+b*b-c*c)/(2.0*a*b))*(180.0/pi);
        res.push_back(A);
        res.push_back(B);
        res.push_back(C);
        sort(res.begin(),res.end());
        return res;
    }
};