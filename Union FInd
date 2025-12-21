#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent, rank;
    
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if(pa == pb) return;
        if(rank[pa] < rank[pb]) parent[pa] = pb;
        else if(rank[pa] > rank[pb]) parent[pb] = pa;
        else {
            parent[pb] = pa;
            rank[pa]++;
        }
    }
};

int count_closed_islands(const vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int total = rows * cols;
    int dummy = total; // dummy node за граници
    
    UnionFind uf(total + 1);
    
    auto getId = [&](int i, int j){ return i * cols + j; };
    
    // правци: горе, долу, лево, десно
    int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] == 1) continue;
            int id = getId(i,j);
            
            // спојување со граница
            if(i == 0 || i == rows-1 || j == 0 || j == cols-1)
                uf.unite(id, dummy);
            
            // спојување со сите 4 соседи
            for(auto &d : dirs) {
                int ni = i + d[0], nj = j + d[1];
                if(ni >= 0 && ni < rows && nj >= 0 && nj < cols && grid[ni][nj] == 0)
                    uf.unite(id, getId(ni,nj));
            }
        }
    }
    
    // броиме затворени острови
    int edgeRoot = uf.find(dummy);
    unordered_set<int> closed;
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] == 0) {
                int root = uf.find(getId(i,j));
                if(root != edgeRoot)
                    closed.insert(root);
            }
        }
    }
    
    return closed.size();
}

int main() {
    vector<vector<int>> grid = {
        {1,1,1,1,0,1,1,1,1,1},
        {1,0,0,1,0,1,0,0,0,1},
        {1,0,1,1,0,1,1,1,0,1},
        {1,0,0,1,0,0,0,1,0,1},
        {1,1,1,1,1,1,1,1,1,1}
    };
    
    cout << count_closed_islands(grid) << endl;
}
