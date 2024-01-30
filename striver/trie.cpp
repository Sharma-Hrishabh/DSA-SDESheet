struct Node {
        Node* links[26];
        bool flag;

        bool containsKey(char key){
            if(links[key-'a']==NULL) return false;
            return true;
        }

        void put(char key){
            links[key-'a']= new Node();
        }

        Node* get(char key){
            return links[key-'a'];
        }

        void markEnd(){
            flag=true;
        }

        bool isEnd(){
            return flag;
        }

};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i]);
            }
            //move to next
            node = node->get(word[i]);
        }

        node->markEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
               return false;
            }
            //move to next
            node = node->get(word[i]);
        }
        return node->isEnd();

    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0;i<prefix.length();i++){
            if(!node->containsKey(prefix[i])){
               return false;
            }
            //move to next
            node = node->get(prefix[i]);
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