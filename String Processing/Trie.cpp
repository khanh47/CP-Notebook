const int AL = 26;

struct Trie {
    struct Node {
        Node *child[AL];
        // num child and num word end at this node
        int cnt, word;
        
        Node() {
            cnt = word = 0;
            FOR (i, 0, AL - 1)
                child[i] = NULL;
        }
    };

    Node *root = new Node();

    void add(string s){
        Node *it = root;
        for (char c : s){
            int idx = c - 'a';
            if (!it -> child[idx])
                it -> child[idx] = new Node();
            it = it -> child[idx];
            it -> cnt++;
        }
        it -> word++;
    }

    bool Find(string s){
        Node *it = root;
        for (char c : s){
            int idx = c - 'a';
            if (!it -> child[idx])
                return 0;
            it = it -> child[idx];
        }
        return it -> word;
    }

    bool reDrop(Node *u, string s, int i){
        if (i != s.size()){
            int idx = s[i] - 'a';
            if (reDrop(u -> child[idx], s, i + 1))
                u -> child[idx] = NULL;
        }else
            u -> word--;
        if (u != root){
            u -> cnt--;
            if (u -> cnt == 0){
                delete(u);
                return 1;
            }
        }
        return 0;
    }

    void drop(string s){
        if (!Find(s))
            return;
        reDrop(root, s, 0);
    }
} trie;