class Solution {
public:
    bool isAnagram(string s, string t) {
        int mp_t[26] = {0};
        int mp_s[26] = {0};

        for(int i=0;i<s.size();i++)mp_s[s[i]-'a']++;
        for(int i=0;i<t.size();i++)mp_t[t[i]-'a']++;

        for(int i=0;i<26;i++)
        {
            if(mp_t[i]!=mp_s[i])return false;
        }
        return true;

    }
};
