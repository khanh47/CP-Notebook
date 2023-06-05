ll Hash[MAX], pw[MAX];
void buildHash(string key){
    int len = key.size();
    key = " " + key;
    FOR (i, 1, len){
        Hash[i] = muti(Hash[i - 1], BASE);
        add(Hash[i], key[i]);
        pw[i] = muti(pw[i - 1], BASE);
    }
}