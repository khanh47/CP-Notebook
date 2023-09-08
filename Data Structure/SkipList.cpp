// Tested: 
// https://oj.vnoi.info/problem/cppset 
// Wanna get another code? go to this link
// https://ideone.com/53t3Eh

const int LG = 20;

struct Cell;

struct Column {
    int val;
    vector<Cell> cells;
};

struct Cell {
    Column *preCol, *nextCol;
};

struct SkipList {

    Column *head, *tail;

    SkipList(){
        head = new Column;
        tail = new Column;
        head -> val = tail -> val = 0;
        FOR (i, 0, LG - 1)
            head -> cells.pb({NULL, tail}),
            tail -> cells.pb({head, NULL});
    }

    bool nothing(){
        return head -> cells[0].nextCol == tail;
    }

    Column *lower(int val){
        Column *it = head;
        FOD (i, LG - 1, 0)
            while (it -> cells[i].nextCol != tail && it -> cells[i].nextCol -> val < val)
                it = it -> cells[i].nextCol;
        return it -> cells[0].nextCol;
    }

    Column *upper(int val){
        Column *it = head;
        FOD (i, LG - 1, 0)
            while (it -> cells[i].nextCol != tail && it -> cells[i].nextCol -> val <= val)
                it = it -> cells[i].nextCol;
        return it -> cells[0].nextCol;
    }

    void add(int val){
//        if skip list has unique values uncomment those lines
//        Column *tmp = lower(val);
//        if (tmp != tail && tmp -> val == val)
//            return;

        Column *newCol = new Column;
        newCol -> val = val;
        newCol -> cells.pb({NULL, NULL});
        while (newCol -> cells.size() < LG && rand() & 1)
            newCol -> cells.pb({NULL, NULL});
        Column *it = head;
        FOD (i, LG - 1, 0){
            while (it -> cells[i].nextCol != tail && it -> cells[i].nextCol -> val < val)
                it = it -> cells[i].nextCol;
            if (i < newCol -> cells.size()){
                Column *nextIt = it -> cells[i].nextCol;
                it -> cells[i].nextCol = newCol;
                nextIt -> cells[i].preCol = newCol;
                newCol -> cells[i].nextCol = nextIt;
                newCol -> cells[i].preCol = it;
            }
        }
    }

    void drop(int val){
        Column *dropCol = lower(val);
        if (dropCol == tail || dropCol -> val != val)
            return;

        Column *it = head;
        FOD (i, LG - 1, 0){
            while (it -> cells[i].nextCol != tail && it -> cells[i].nextCol -> val <= val)
                it = it -> cells[i].nextCol;
            if (it == dropCol){
                Column *preIt = it -> cells[i].preCol, *nextIt = it -> cells[i].nextCol;
                preIt -> cells[i].nextCol = nextIt;
                nextIt -> cells[i].preCol = preIt;
				// if just delete one value then break
            }
        }
        delete dropCol;
    }

    int minimum(){
        return head -> cells[0].nextCol -> val;
    }

    int maximum(){
        return tail -> cells[0].preCol -> val;
    }
} sl;
