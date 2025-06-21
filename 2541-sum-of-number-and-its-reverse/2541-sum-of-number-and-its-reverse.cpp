class Solution {
public:
int reverse_function(int num){
    int rev_num=0;
    int n=num;
    while(n){
        rev_num=rev_num*10+(n%10);
        n/=10;
    }
    return rev_num;
}
    bool sumOfNumberAndReverse(int num) {
        for(int i=0;i<=num;i++){
            int rev_num=reverse_function(i);
            if(i+rev_num==num) return true;
        }
        return false;
    }
};