bool found[MAX_N];

pi BFS(int start) { //return {endpoint, longest path from start}
    queue<pi> q; //{node, dist}
    q.push({start, 0});
    pi ret; //answer
    found[start] = true;
    while (!q.empty()) {
        int u = q.front().ff, d = q.front().ss;
        if (d > ret.ss) ret = q.front();
        q.pop();
        for (pi edge: adjList[u]) {
            int v = edge.ff, w = edge.ss;
            if (!found[v]) {
                found[v] = true;
                q.push({v, d + w});
            }
        }
    }
    return ret;
}

pair<int, pi> diameter() { //returns {diameter, {endpoint, endpoint}}
    memset(found, 0, sizeof found);
    int end1 = BFS(1).ff;
    memset(found, 0, sizeof found);
    pi res = BFS(end1);
    return {res.ss, {end1, res.ff}};
}
