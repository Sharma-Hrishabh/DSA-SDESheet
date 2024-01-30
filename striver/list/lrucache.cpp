class node{
    public:
    int key;
    int val;
    node* next;
    node* prev;
    node(int _key,int _val){
        key = _key;
        val = _val;
    }
};

class LRUCache {
public:
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    int cap;
    unordered_map<int,node*>m;

    LRUCache(int capacity) {
        cap = capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addNode(node* newnode){
        node* temp = head->next;
        //for new node
        newnode->next=temp;
        newnode->prev=head;

        head->next=newnode;
        temp->prev=newnode;
    }

    void deleteNode(node* delnode){
        node* delPrev = delnode->prev;
        node* delNext = delnode->next;

        delPrev->next = delNext;
        delNext->prev = delPrev;

    }


    int get(int key) {
        if(m.find(key)!=m.end()){
            node* cache = m[key];
            int ans = cache->val;
            deleteNode(cache);
            addNode( new node(key,ans));
            m[key]=head->next;
            return ans;

        }
        return -1;
    }
    
    void put(int key, int value) {
        //check if node is already rpesent - remove it
        if(m.find(key)!=m.end()){
            node* cache = m[key];
            m.erase(key);
            deleteNode(cache);
        }

        //remove LRU if requried
        if(cap == m.size()){
            //remove LRU
            node* lru = tail->prev;
            m.erase(lru->key);
            deleteNode(lru);
        }

        //put new node
        addNode(new node(key,value));
        m[key]=head->next;


    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */