class Solution {
public:
    bool valid(int num) {
        bool flag2=false;
        while (num) {
            int x = num % 10;
            if(x==3 || x==4 || x==7) return false;
            if (x==2 || x==5 || x==6 || x==9) flag2=true;
            num/=10;
        }
        if(!flag2) return false;
        return true;
    }
    int rotatedDigits(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (valid(i))
                res++;
        }
        return res;
    }
};