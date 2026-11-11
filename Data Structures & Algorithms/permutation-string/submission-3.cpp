class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length()) return false;
        int mp_s1[26] = {0};

        int n = s1.length(), m = s2.length();
        int k = 0;
        for(int i=0;i<n;i++) 
        {
            mp_s1[s1[i]-'a']++;
            if(mp_s1[s1[i]-'a']==1)k++;
        }

        int matches = 0;
        int mp_s2[26] = {0};
        
        for(int i=0;i<n;i++)
        {
            mp_s2[s2[i]-'a']++;
            if(mp_s2[s2[i]-'a'] == mp_s1[s2[i]-'a']) matches++;
            else if(mp_s2[s2[i]-'a']  && mp_s2[s2[i]-'a'] == (mp_s1[s2[i]-'a'] + 1))matches--;
        }
        if(matches == k) return true;
        


        for(int i=n;i<m;i++)
        {
            mp_s2[s2[i-n]-'a']--;
            if(mp_s2[s2[i-n]-'a'] == (mp_s1[s2[i-n]-'a']))matches++;
            else if(mp_s2[s2[i-n]-'a'] == (mp_s1[s2[i-n]-'a'] -1 )) matches--;
            mp_s2[s2[i]-'a']++;
            if(mp_s2[s2[i]-'a'] == mp_s1[s2[i]-'a']) matches++;
            else if(mp_s2[s2[i]-'a'] == (mp_s1[s2[i]-'a'] + 1))matches--;
            if(matches == k) return true;

        }

        return false;
    }
};
