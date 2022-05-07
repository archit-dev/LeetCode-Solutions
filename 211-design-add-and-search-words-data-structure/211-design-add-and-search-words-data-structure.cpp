struct Node{
    Node * links[26];
    bool flag = false;
    
    bool containsKey(char x){
        return links[x-'a']!=NULL ? true : false;
    }
    
    void putKey(char x){
        links[x-'a'] = new Node();
    }
    
    Node* getNext(char x){
        return links[x-'a'];
    }
    
    bool isEnd(){
        return flag;
    }
    
    void markEnd(){
        flag = true;
    }
};

class WordDictionary {
private:
    Node * root;
    
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node * node = root;
        for(char currentChar : word){
            //check if the current node has the character
            //if not, then we add the character and create a reference node for it
            if(!node->containsKey(currentChar)){
                //creating a new node for it
                node->putKey(currentChar);
            }
            node = node->getNext(currentChar);
        }
        node->markEnd();
    }
    
    bool search(string word) {
        Node * node = root;
        for(int i=0; i<word.size();i++){
            //check if the current node has the character
            char currentChar = word[i];
            if(currentChar=='.'){
                for(int j=0;j<26;j++){
                    if(node->links[j]!=NULL && search(word.substr(i+1),node->getNext(j+'a'))){
                        return true;
                    }
                }
                return false;
            }
            if(!node->containsKey(currentChar)){
                return false;
            }
            node = node->getNext(currentChar);
        }
        return node->isEnd();
    }
    bool search(string word,Node* root) {
        Node * node = root;
        for(int i=0; i<word.size();i++){
            //check if the current node has the character
            char currentChar = word[i];
            if(currentChar=='.'){
                for(int j=0;j<26;j++){
                    if(node->links[j]!=NULL && search(word.substr(i+1),node->getNext(j+'a'))){
                        return true;
                    }
                }
                return false;
            }
            if(!node->containsKey(currentChar)){
                return false;
            }
            node = node->getNext(currentChar);
        }
        return node->isEnd();
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */