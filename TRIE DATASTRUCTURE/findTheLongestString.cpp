//Question link is provided in the description
class Solution {
  public:
    struct TrieNode{
        bool isEOW;
        TrieNode* children[26];
        TrieNode(){
            isEOW = false;
            for(int i =0 ;i<26; i++){
                children[i] = NULL;
            }
        }
    };
    TrieNode* root = new TrieNode();
    void insert(string &word){
        TrieNode* temp = root;
        for(int i = 0; i<word.length(); i++){
            int idx = word[i] - 'a';
            if(temp->children[idx] == NULL){
                temp->children[idx] = new TrieNode();
            }
            temp = temp -> children[idx];
        }
        temp -> isEOW = true;
    }
    bool search(string &word){
        TrieNode* temp = root;
        for(int i = 0; i<word.length(); i++){
            int idx = word[i] - 'a';
            temp = temp -> children[idx];
            if(temp == NULL || temp -> isEOW == false){
                return false;
            }
            
        }
        return true;
    }
    string longestString(vector<string> &arr) {
        // code here
        for(string &word: arr){
            insert(word);
            
        }
        string res = "";
        for(string &word: arr){
            if(search(word)){
                if(word.length() > res.length() || (word.length() == res.length() && word<res)){
                    res = word;
                }
            }
        }
        return res;
    }
};
