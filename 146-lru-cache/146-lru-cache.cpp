class LRUCache { 
public:
    class LRUNode{
        public:
            int key,value;
            LRUNode* next, *prev;
        
            LRUNode(int key_,int val_){
                key = key_;
                value = val_;
                next = nullptr;
                prev = nullptr;
            }
    };
    
    unordered_map<int,LRUNode*> mp;
    LRUNode * head = new LRUNode(-1,-1);
    LRUNode * tail = new LRUNode(-1,-1);
    int capa;
    
    LRUCache(int capacity) {
        capa = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(LRUNode* newNode){
        LRUNode* temp = head->next;
        head->next = newNode;
        newNode->next = temp;
        newNode->prev = head;
        temp->prev = newNode; 
    }
    
    void deleteNode(LRUNode* reqNode){
        LRUNode * prevNode = reqNode->prev;
        LRUNode * nextNode = reqNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        // delete reqNode; 
    }

    int get(int key_) {
        //if not found
        if(mp.find(key_)==mp.end()) return -1;
        
        //if found
        LRUNode * reqNode = mp[key_];
        int val = reqNode->value;
        deleteNode(reqNode);
        mp.erase(key_);
        addNode(reqNode);
        mp[key_] = head->next;
        return val;
    }

    void put(int key_, int value) {
        if(mp.find(key_)!=mp.end()){
            //this node already exists
            //remove this node
            LRUNode * reqNode = mp[key_];
            mp.erase(key_);
            deleteNode(reqNode);
        }
        if(mp.size()==capa){
            //first delete the last node and then insert
            int temp = tail->prev->key;
            deleteNode(tail->prev);
            mp.erase(temp);
        }
        //add the node
        LRUNode* newNode = new LRUNode(key_,value);
        addNode(newNode);
        mp[key_] = head->next;
    }
};
