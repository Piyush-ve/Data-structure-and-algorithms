class Node{
    public:

    unordered_map<char,Node*>children;
    bool endOfWord;

    Node()
    {
        endOfWord = false;
    }
};

class Trie
{
    Node* root;
    public:
        Trie()
        {
            root= new Node();
        }

        void insert(string key) //O(L)
        {
            Node* temp = root;
            for(int i=0; i<key.size(); i++)
            {
                if(temp->children.count(key[i]) == 0)
                {
                    temp->children[key[i]] = new Node(); //insert
                }
                temp=temp->children[key[i]];
            }
            temp->endOfWord =true;
        }

        bool search(string key)
        {
            Node* temp=root;
            for(int i=0;i<key.size();i++)
            {
                if(temp->children.count(key[i]))
                {
                    temp=temp->children[key[i]];
                }
                else{
                    return false;
                }
            }

            return temp->endOfWord;
          
        }
};
class Solution {
public:
     unordered_map<string,bool> memo; // cache for substrings
    bool helper(Trie &trie, string key)
    {
        if(key.size()==0)
        {
            return true;
        }

         // \U0001f539 check cache
        if (memo.count(key)) return memo[key];

        for(int i=0;i<key.size();i++)
            {
                string first=key.substr(0,i+1);
                string second=key.substr(i+1);

                if(trie.search(first) && helper(trie,second))
                {
                 return memo[key] = true;
            }
        }

        return memo[key] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for(int i=0;i<wordDict.size();i++)
        {
            trie.insert(wordDict[i]);
        }

        return helper(trie,s);


    }
};