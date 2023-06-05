
struct TrieNode {
    TrieNode *child[26];
    bool isWord;
};

struct TrieNode *createNode(void) {
    TrieNode *pNode = new TrieNode;

    pNode -> isWord = false;
    FOR (i, 0, 25)
        pNode -> child[i] = NULL;

    return pNode;
}

void trieInsert(TrieNode *root, char key[]){
    TrieNode *pCrawl = root;
    int len = strlen(key);

    FOR (i, 0, len - 1){
        int idx = key[i] - 'a';
        if (!pCrawl -> child[idx])
            pCrawl -> child[idx] = createNode();
        pCrawl = pCrawl -> child[idx];
    }

    pCrawl -> isWord = true;
}

bool trieFind(TrieNode *root, char key[]){
    int len = strlen(key);
    struct TrieNode *pCrawl = root;

    FOR (i, 0, len - 1){
        int idx = key[i] - 'a';
        if (!pCrawl -> child[idx])
            return false;
        pCrawl = pCrawl -> child[idx];
    }

    return (pCrawl -> isWord);
}