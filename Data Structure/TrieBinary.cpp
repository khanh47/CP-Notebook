struct Trie {
    struct Node {
        Node *child[2];
        int cnt;

        Node() {
            FOR (i, 0, 1)
                child[i] = NULL;
            cnt = 0;
        }
    };

    Node *root = new Node();

    void add(int val){
        Node *it = root;
        FOD (i, LG, 0){
            bool x = BIT(val, i);
            if (!it -> child[x])
                it -> child[x] = new Node();
            it = it -> child[x];
            it -> cnt++;
        }
    }

    int get(int val){
        Node *it = root;
        int res = 0;
        FOD (i, LG, 0){
            bool x = BIT(val, i);
            if (it -> child[x])
                it = it -> child[x];
            else
                res |= MASK(i),
                it = it -> child[x ^ 1];
        }
        return res;
    }

    bool Del(Node *it, int val, int i){
        if (i >= 0){
            bool x = BIT(val, i);
            if (Del(it -> child[x], val, i - 1))
                it -> child[x] = NULL;
        }
        if (it != root){
            it -> cnt--;
            if (it -> cnt == 0){
                delete(it);
                return 1;
            }
        }
        return 0;
    }

    bool Find(int val){
        Node *it = root;
        FOD (i, LG, 0){
            bool x = BIT(val, i);
            if (!it -> child[x])
                return 0;
            it = it -> child[x];
        }
        return 1;
    }

    void del(int val){
        if (!Find(val))
            return;
        Del(root, val, LG);
    }
} trie;