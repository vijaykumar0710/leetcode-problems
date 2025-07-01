class Solution {
public:
    int possibleStringCount(string s) {
        vector<int> group;
        int cnt = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1])
                cnt++;
            else {
                group.push_back(cnt);
                cnt = 1;
            }
        }
        group.push_back(cnt);
        sort(group.begin(), group.end());
        int ress = 0;
        for (int i = group.size() - 1; i >= 0; i--) {
            if (i != group.size() - 1 && (group[i] - 1) <= 0)
                break;
            if (i == group.size() - 1)
                ress += group[i];
            else
                ress += (group[i] - 1);
        }
        return ress;
    }
};