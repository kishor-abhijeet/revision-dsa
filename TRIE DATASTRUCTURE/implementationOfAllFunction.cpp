struct Node{
    Node *children[26];
    bool flag = false;
    bool containskey(char ch){
        return (children[ch - 'a'] != NULL);
    }
};
class Trie {
    private: Node*root;
  public:

    Trie() {
        // implement Trie
        root = new Node();
        
    }

    void insert(string &word) {
        // insert word into Trie
        Node* curr = root;
        for(int i=0; i<word.length(); i++)
        {
            if(!curr->containskey(word[i])){
                Node *newNode = new Node();
                curr->children[word[i]-'a'] = newNode;
                
            }
            curr = curr->children[word[i]-'a'];
        }
        curr->flag = true;
        
    }

    bool search(string &word) {
        // search word in the Trie
        Node* curr = root;
        for(int i =0; i<word.length(); i++){
            if(!curr->containskey(word[i])) return false;
            curr = curr->children[word[i]-'a'];
        }
        return curr->flag;
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
        Node* curr = root;
        for(int i =0; i<word.length(); i++){
            if(!curr->containskey(word[i])) return false;
            curr = curr->children[word[i]-'a'];
        }
        return true;
    }
};
