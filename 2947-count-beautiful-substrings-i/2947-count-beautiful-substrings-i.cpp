class Solution {
public:
bool isVowels(char ch){
    return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
}
    int beautifulSubstrings(string s, int k) {
        int n=s.size(),res=0;
        for(int i=0;i<n;i++){
            int vowels=0,cont=0;
            for(int j=i;j<n;j++){
                if(isVowels(s[j])) vowels++;
                else cont++;
                if(vowels==cont && (vowels*cont)%k==0) res++;
            }
        }
        return res;
    }
};