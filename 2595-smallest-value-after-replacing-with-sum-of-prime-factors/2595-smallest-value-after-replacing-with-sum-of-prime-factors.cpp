class Solution {
public:
const static int N=1e5+1;
int spf[N];
    int smallestValue(int n) {
         for (int i = 1; i < N; i++){
        spf[i] = i;
    }
    for (int i = 2; i * i <= N; i++) {
    if (spf[i] == i) { // i is prime
        for (int j = 2; i * j < N; j++) {
            if (spf[i * j] == i * j) {
                spf[i * j] = i;
            }
        }
    }
}

        while(n!=spf[n]){ 
         int sum=0;
         int x=n;
         while (x!=1){
         sum+=spf[x];
         x /= spf[x];
          }
          if (sum == n) break;
          n=sum;
        }
        return n;
    }
};