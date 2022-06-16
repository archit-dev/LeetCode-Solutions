class LFUCache {
public:
    struct Node{
        int key_,val_,freq_;
        Node *next , *prev;
        
        Node(int key,int val){
            key_ = key;
            val_ = val;
            freq_ = 1;
        }
    };
    
    class List{
        public:
        Node* head,*tail;
        int size;
        
        List(){
            head = new Node(-1,-1);    
            tail = new Node(-1,-1);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }
        void addFront(Node * newNode){
            Node * temp = head->next;
            newNode->next = temp;
            newNode->prev = head;
            head->next = newNode;
            temp->prev = newNode;
            size++;
        }
        
        void deleteNode(Node * delNode){
            Node * prevNode = delNode->prev;
            Node * nextNode = delNode->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            size--;
        }
    };
    
    unordered_map<int,List*> frequencyMap;
    unordered_map<int,Node*> addressMap;
    int currSize , capa , minFreq;
    
    LFUCache(int capacity) {
        capa = capacity;
        currSize = 0;
        minFreq = 0;
    }
    
    void updateFreqList(Node * node){
        addressMap.erase(node->key_);
        //now erase the node from the current freq list
        frequencyMap[node->freq_]->deleteNode(node);
        
        //once you have deleted that node, move it to the next frequency
        
        //if it is the last member of the min freq, increase the min freq
        if(node->freq_ == minFreq && frequencyMap[minFreq]->size==0){
            minFreq++;
        }
        
        //find the list of next frequency
        List * newList = new List();
        if(frequencyMap.find(node->freq_+1)!=frequencyMap.end()){
            newList = frequencyMap[node->freq_+1];
        }
        
        //now add it to the front of this list
        node->freq_ +=1;
        newList->addFront(node);
        //once you have added it to the front of the list, store it in address map
        addressMap[node->key_] = node;
        frequencyMap[node->freq_] = newList;
    }
    
    int get(int key) {
        //not found
        if(addressMap.find(key)==addressMap.end()) return -1;
        
        //if found
        Node * resultNode = addressMap[key];
        int value = resultNode->val_;
        updateFreqList(resultNode);
        return value;
        
    }
    
    void put(int key, int value) {
        if(capa==0) return;
        
        //if key exists
        if(addressMap.find(key)!=addressMap.end()){
            //if already exists
            Node * resultNode = addressMap[key];
            resultNode->val_ = value;
            updateFreqList(resultNode);
            return;
        }
        //if key does not exist
        if(currSize==capa){
            //if full, remove the lru of minFreq
            List * reqList = frequencyMap[minFreq];
            addressMap.erase(reqList->tail->prev->key_);
            reqList->deleteNode(reqList->tail->prev);
            currSize--;
        }
        //now time to add the element
        currSize++;
        minFreq = 1;
        List * newList = new List();
        if(frequencyMap.find(minFreq)!=frequencyMap.end()){
            //if freq[1] is not empty
            newList = frequencyMap[minFreq];
        }
        Node * newNode = new Node(key,value);
        newList->addFront(newNode);
        addressMap[newNode->key_] = newNode;
        frequencyMap[minFreq] = newList;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */