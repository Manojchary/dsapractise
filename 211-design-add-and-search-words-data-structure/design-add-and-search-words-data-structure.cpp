class TrieNode {
public:
    vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);
    bool isend;

    TrieNode() {
        isend = false;
    }
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* curr = root;

        for (char &ch : word) {
            int idx = ch - 'a';

            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }

            curr = curr->children[idx];
        }

        curr->isend = true;
    }

    bool dfs(TrieNode* curr, string& word, int pos) {
        if (pos == word.size()) {
            return curr->isend;
        }

        char ch = word[pos];

        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (curr->children[i] != nullptr &&
                    dfs(curr->children[i], word, pos + 1)) {
                    return true;
                }
            }

            return false;
        }

        int idx = ch - 'a';

        if (curr->children[idx] == nullptr) {
            return false;
        }

        return dfs(curr->children[idx], word, pos + 1);
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */