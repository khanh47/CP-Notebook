
struct Fenwick {
    int bit[MAX];
    void update(int idx, int val){
        for (; idx <= MAX; idx += idx & (-idx))
            bit[idx] += val;
    }

    int get(int idx){
        int res = 0;
        for (; idx; idx -= idx & (-idx))
            res += bit[idx];
        return res;
    }
};