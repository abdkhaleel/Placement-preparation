#include <bits/stdc++.h>
using namespace std;
class SegmentTree2D {
    int n, m;
    vector<vector<int>> tree;
public:
    SegmentTree2D(int n, int m) {
        this->n = n;
        this->m = m;
        tree.assign(4*n, vector<int>(4*m, 0));
    }

    void build_x(int posx, int lx, int rx, vector<vector<int>>& grid){
        if(lx == rx){
            build_y(grid, posx, lx, rx, 0, 0, m-1);
            return;
        }
        int mid = (lx + rx) / 2;
        build_x(2*posx+1, lx, mid, grid);
        build_x(2*posx+2, mid+1, rx, grid);
    }

    void build_y(vector<vector<int>>& grid, int posx, int lx, int rx, int posy, int ly, int ry) {
        if(ly == ry) {
            if(lx == rx) {
                tree[posx][posy] = grid[lx][ly];
            }
            else{
                tree[posx][posy] = tree[2*posx+1][posy] + tree[2*posx+2][posy];
            }
        }
        else{
            int mid = (ly + ry) / 2;
            build_y(grid, posx, lx, rx, 2*posy+1, ly, mid);
            build_y(grid, posx, lx, rx, 2*posy+2, mid+1, ry);
            tree[posx][posy] = tree[posx][2*posy+1] + tree[posx][2*posy+2];
        }
    }
    int query_x(int posx, int lx, int rx, int ix, int jx, int iy, int jy){
        if(ix > rx || jx < lx) return 0;
        if(ix <= lx && rx <= jx) return query_y(posx, lx, rx, 0, 0, m-1, ix, jx, iy, jy);
        int mid = (lx + rx) / 2;
        return query_x(2*posx+1, lx, mid, ix, jx, iy, jy) +
                query_x(2*posx+2, mid+1, rx, ix, jx, iy, jy);
    }
    int query_y(int posx, int lx, int rx, int posy, int ly, int ry, int ix, int jx, int iy, int jy){
        if(iy > ry || jy < ly) return 0;
        if(iy <= ly && jy >= ry) return tree[posx][posy];
        int mid = (ly + ry) / 2;
        return query_y(posx, lx, rx, 2*posy+1, ly, mid, ix, jx, iy, jy) +
                query_y(posx, lx, rx, 2*posy+2, mid+1, ry, ix, jx, iy, jy);
    }
    void update_x(int posx, int lx, int rx, int i, int j, int val){
        if(lx == rx){
            update_y(posx, lx, 0, 0, m-1, j, val);
            return;
        }
        int mid = (lx + rx) / 2;
        if(i <= mid){
            update_x(2*posx+1, lx, mid, i, j, val);
        }
        else{
            update_x(2*posx+2, mid+1, rx, i, j, val);
        }
        tree[posx][j] = tree[2*posx+1][j] + tree[2*posx+2][j];
    }
    void update_y(int posx, int lx, int posy, int ly, int ry, int j, int val){
        if(ly == ry){
            tree[posx][posy] = val;
            return;
        }
        int mid = (ly + ry) / 2;
        if(j <= mid){
            update_y(posx, lx, 2*posy+1, ly, mid, j, val);
        }
        else{
            update_y(posx, lx, 2*posy+2, mid+1, ry, j, val);
        }
        tree[posx][posy] = tree[posx][2*posy+1] + tree[posx][2*posy+2];
    }
};