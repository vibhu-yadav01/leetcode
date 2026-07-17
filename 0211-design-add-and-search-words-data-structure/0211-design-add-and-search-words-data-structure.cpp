class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
    }
};

class WordDictionary {
    TrieNode* root;

    bool dfs(string &word, int idx, TrieNode* node) {
        if (!node) return false;

        if (idx == word.size())
            return node->isEnd;

        char ch = word[idx];

        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (dfs(word, idx + 1, node->child[i]))
                    return true;
            }
            return false;
        }

        return dfs(word, idx + 1, node->child[ch - 'a']);
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* curr = root;

        for (char ch : word) {
            int idx = ch - 'a';
            if (!curr->child[idx])
                curr->child[idx] = new TrieNode();
            curr = curr->child[idx];
        }

        curr->isEnd = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};