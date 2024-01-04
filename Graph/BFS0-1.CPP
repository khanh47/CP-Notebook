void bfs01(int src){
    //Gán giá trị ban đầu cho đường đi lớn nhỏ nhất đến các đỉnh
    memset(dis, 0x3f, sizeof(dis)); 
    deque<int> dq; 
    //Thêm đỉnh s được cho vào hàng đầu hàng đợi
    dq.push_front(src); 
    dis[src] = 0;
    
    while (!dq.empty()){
        //Lấy ra phần tử đứng đầu của hàng đợi
        int u = dq.front();
        dq.pop_front();
        for (auto [v, cost] : edge[u]){
            //Xét điều kiện để đỉnh tới được tối ưu
            if (minimize(dis[v], dis[u] + cost)){
                if (cost)
                    dq.push_back(v);
                else
                    dq.push_front(v);
            }
        }
    }
}