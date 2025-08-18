class Node{
    public:
    int key,value;
    Node* prev;
    Node* next;

    Node(int k,int val)
    {
        key=k;
        value=val;
        prev=NULL;
        next=NULL;
    }
};

class LRUCache {
public:
            Node* node;
            Node* head;
            Node* tail;
            unordered_map<int,Node*>mp;//for get
            int sz=0;


        LRUCache(int capacity) {
            sz=capacity;
             head=new Node(0,0);
             tail=new Node(0,0);
            head->next=tail;
            tail->prev=head;
        }

        void insert(Node* node)
        {
            Node* a= tail->prev;

            a->next=node;
            tail->prev=node;
            node->prev=a;
            node->next=tail;
        }
        void remove(Node* node)
        {
            Node* left=node->prev;
            Node* right=node->next;

            left->next=right;
            right->prev=left;

            node->prev=NULL;
            node->next=NULL;

          

        }

        int get(int key) {

            if(mp.count(key))
            {
                Node* node=mp[key];
                remove(node);
                insert(node);

                return node->value;
            }
            else
            return -1;
        }
    
        void put(int key, int value) 
        {
            if(mp.count(key))
            {
                remove(mp[key]);
                mp.erase(key);

                Node* node=new Node(key ,value);
                insert(node);
                mp[key]=node;

            }
            else
            {
                if(mp.size()==sz)
                {
                    Node *lru=head->next;
                    remove(lru);
                    mp.erase(lru->key);

                }
                Node *node=new Node(key,value);
                insert(node);
                mp[key]=node;
            }
                    
        }

    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */