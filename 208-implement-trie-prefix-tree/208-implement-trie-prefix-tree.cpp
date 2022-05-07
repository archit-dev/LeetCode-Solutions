struct Node{
    Node * links [26];
    bool flag = false;
    
    bool containsKey(char x){
        return links[x-'a']!=NULL ? true : false;
    }
    
    void putKey(char x){
        links[x-'a'] = new Node();
    }
    
    Node * getNext(char x){
        return links[x-'a'];
    }
    
    void markEnd(){
        flag = true;
    }
    
    bool isEnd(){
        return flag;
    }
};

class Trie {
private:
    Node * root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node * node = root;
        for(char currentChar : word){
            if(!node->containsKey(currentChar)){
                //if the trie doesnot contain the current char
                //mark it and create a reference node related to it
                node->putKey(currentChar);
            }
            //move to the next reference node
            node = node->getNext(currentChar);
        }
        node->markEnd();
    }
    
    bool search(string word) {
        Node * node = root;
        for(char currentChar : word){
            if(!node->containsKey(currentChar)){
                return false;
            }
            node = node->getNext(currentChar);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node * node = root;
        for(char currentChar : prefix){
            if(!node->containsKey(currentChar)){
                return false;
            }
            node = node->getNext(currentChar);
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