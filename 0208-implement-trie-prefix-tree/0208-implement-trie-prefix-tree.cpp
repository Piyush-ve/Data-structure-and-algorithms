class Node{
    public:

    unordered_map<char,Node*>children;
    bool endOfWord;

    Node()
    {
        endOfWord =false;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root=new Node();
    }
    
    void insert(string key) {
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
    
    bool search(string key) {

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
    
    bool startsWith(string key) {
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

            return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */