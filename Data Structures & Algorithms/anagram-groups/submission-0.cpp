class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;

        for(const auto &s: strs)
        {
            int F[26] = {0};
            for(const auto &ch: s)
            {
                F[ch-'a']++;
            }
            string temp;
            for(int i=0;i<26;i++)
            {
                temp+=to_string(F[i])+"#";
            }
            mp[temp].push_back(s);
        }

        vector<vector<string>>ans;

        for(const auto &x:mp)
        {
            vector<string>temp;
            for(const auto &y:x.second)
            {
               temp.push_back(y);
            }
            ans.push_back(temp);
        }

        return ans;


    }
};
