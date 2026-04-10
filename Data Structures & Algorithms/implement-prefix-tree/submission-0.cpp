class TrieNode {
public:
    std::map<char,TrieNode*> children;
    bool endWord = false;
};

class PrefixTree {
public:
    TrieNode root;
    
    void insert(string word) {
        TrieNode* curr = &root;

        for (char c: word) {
            if (!curr->children.contains(c)) {
                curr->children[c]= new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->endWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = &root;

        for (char c: word) {
            if (!curr->children[c])
                return false;
            curr = curr->children[c];
        }
        return curr->endWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = &root;

        for (char c: prefix) {
            if (!curr->children[c])
                return false;
            curr = curr->children[c];
        }
        return true;
        
    }
};
