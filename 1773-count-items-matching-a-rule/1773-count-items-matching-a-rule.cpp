class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int cnt=0;
        for(auto str:items){
            string type=str[0],color=str[1],name=str[2];
            if(ruleKey =="type" && ruleValue == type || ruleKey == "color" && ruleValue == color || ruleKey == "name" && ruleValue == name) cnt++;
        }
        return cnt;
    }
};