class Solution {
public:
    string answerString(string word, int numFriends) {
        int n=word.size();
        int k=numFriends;
        if(k==1) return word;
        int maxi=n-(k-1);
        string res="";
        for(int i=0;i<n;i++){
            // left half
           int l1=i+1;
           if(l1>maxi){
            string tmp=word.substr(i-l1+1,maxi);
            if(tmp>res){
                res=tmp;
            }
           }else{
            string tmp=word.substr(0,i+1);
            if(tmp>res){
                res=tmp;
             }
           }
         // right half
         int l3=n-i-1;
          if(l3>maxi){
            string tmp=word.substr(i+1,maxi);
            if(tmp>res){
                res=tmp;
            }
           }else{
            string tmp=word.substr(i+1);
            if(tmp>res){
                res=tmp;
             }
           }
        }
   return res;
    }
};