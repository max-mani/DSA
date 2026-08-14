class LRUCache {
public:
    struct Node {
        int key, val;
        Node* prev;
        Node* next;
        Node (int key, int val) {
            this->key = key;
            this->val = val;
        }
    };

    Node* lru = new Node(-1, -1);
    Node* mru = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*>mp;

    LRUCache(int capacity) {
        cap = capacity;
        lru->next = mru;
        mru->prev = lru;
    }
    
    void insert(Node* t) {
        Node* pre = mru->prev;
        
        pre->next = t;
        t->next = mru;
        
        mru->prev = t;
        t->prev = pre;
    }

    void remove(Node* t) {
        Node* pre = t->prev;
        Node* nex = t->next;
        
        pre->next = nex;
        nex->prev = pre;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* t = mp[key];
            int ans = t->val;
            
            mp.erase(key);
            remove(t);
            insert(t);
            
            mp[key] = mru->prev;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* t = mp[key];
            mp.erase(key);
            remove(t);
        }
        if (mp.size() == cap) {
            Node* t = lru->next;
            mp.erase(t->key);
            remove(t);
        }
        Node* t = new Node(key, value);
        insert(t);
        mp[key] = mru->prev;
    }
};