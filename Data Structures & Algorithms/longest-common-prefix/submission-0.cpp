class TrieNode
{

    public:
        vector<TrieNode*>next;
        int overlap_counter = 0;
        TrieNode()
        {
            this->next.resize(26,nullptr);
            this->overlap_counter = 0;
        }
};

class Trie{
    public:
    TrieNode* root;
    Trie()
    {
        root = new TrieNode();
    }

    void add_string(const string &s)
    {
        TrieNode* node = root;
        for(const auto& ch:s)
        {
            if(!node->next[ch-'a'])
            {
                node->next[ch-'a'] = new TrieNode();
            }
            node = node->next[ch-'a'];
            node->overlap_counter++;
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
     string res;
     Trie t;
     for(const auto &s:strs)
     {
         t.add_string(s);
     }
     int n = strs.size();
     TrieNode* r = t.root;
     int i;
     while(r)
     {

         for(i=0;i<26;i++)
         {
             if(r->next[i] && r->next[i]->overlap_counter==n)
             {

                 res.push_back(i+'a');
                 r = r->next[i];
                 break;
             }
         }
         if(i==26)break;
     }
     return res;

    }
};