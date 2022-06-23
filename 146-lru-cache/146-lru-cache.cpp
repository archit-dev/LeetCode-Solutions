class LRUCache {
public:
    struct Node{
        int keyy,val;
        Node*next,*prev;
        
        Node(int key_,int val_){
            keyy = key_;
            val = val_;
            next=NULL;
            prev=NULL;
        }
    };
    
    Node * head = new Node(-1,-1);
    Node * tail = new Node(-1,-1);
    int capa;
    unordered_map<int,Node*> nodeMap;
    
    LRUCache(int capacity) {
        capa = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void deleteNode(Node * req){
        Node * prevNode = req->prev;
        Node * nextNode = req->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    void insertAtHead(Node * newNode){
        Node * nextNode = head->next;
        newNode->next = nextNode;
        newNode->prev = head;
        nextNode->prev = newNode;
        head->next = newNode;
    }
    
    int get(int key) {
        if(nodeMap.find(key)==nodeMap.end())return -1;
        
        Node * reqNode = nodeMap[key];
        int reqValue = reqNode->val;
        deleteNode(reqNode);
        insertAtHead(new Node(key,reqValue));
        nodeMap[key] = head->next;
        return reqValue;
    }
    
    void put(int key, int value) {
        if(nodeMap.find(key)!=nodeMap.end()){
            //this node exists before
            Node * reqNode = nodeMap[key];
            deleteNode(reqNode);
            insertAtHead(new Node(key,value));
            nodeMap[key] = head->next;
            return;
        }
        
        if(nodeMap.size() == capa){
            //first remove the last node
            nodeMap.erase(tail->prev->keyy);
            deleteNode(tail->prev);
        }
        
        insertAtHead(new Node(key,value));
        nodeMap[key] = head->next;
        return;
    }
};
