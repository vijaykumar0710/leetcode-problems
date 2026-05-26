class Solution {
public:
    int numberOfSpecialChars(string word) {
      unordered_set<char>st;
      sort(word.begin(),word.end());
      int cnt=0;
      for(int i=0;i<word.size();i++){
         char ch=word[i];
         if(i-1>=0 && ch==word[i-1]) continue;
         if('A'<=ch && ch<='Z') st.insert(ch);
         else if(st.count(toupper(ch))) cnt++;
      }
    return cnt;
    }
};