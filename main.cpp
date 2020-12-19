//
// Created by Jlhsmall on 2020/12/19.
//
#include<bits/stdc++.h>

using namespace std;
#define N 1000
#define offset 500

class p2d {
    int x, y;
    static const int stx[8], sty[8];
    static int U, D, L, R, range_x, range_y;
    static bool grid[N][N];

    int go_x(int k) {
        int ret = x + stx[k];
        if (ret > R) ret = L;
        if (ret < L) ret = R;
        return ret;
    }

    int go_y(int k) {
        int ret = y + sty[k];
        if (ret > U)ret = D;
        if (ret < D)ret = U;
        return ret;
    }

    bool check_adjacent() {
        for (int k = 0; k < 8; ++k)
            if (grid[go_x(k)][go_y(k)]) return true;
        return false;
    }

public:
    static void init() {
        grid[offset][offset] = 1;
    }

    static void set_range(int rx, int ry) {
        range_x = rx, range_y = ry;
        L = offset - range_x / 2, R = offset + (range_x - 1) / 2;
        D = offset - range_y / 2, U = offset + (range_y - 1) / 2;
    }

    void walk() {
        int k = rand() % 8;
        x = go_x(k), y = go_y(k);
    }

    void gen() {
        do {
            x = rand() % range_x + L;
            y = rand() % range_x + D;
        } while (grid[x][y]);
        while (!check_adjacent()) {
            walk();
        }
        grid[x][y] = 1;
    }

    friend ostream &operator<<(ostream &os, const p2d obj) {
        os << obj.x  << ' ' << obj.y  << endl;
        return os;
    }
};

const int p2d::stx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int p2d::sty[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int p2d::U, p2d::D, p2d::L, p2d::R, p2d::range_x, p2d::range_y;
bool p2d::grid[N][N];

int main() {
    freopen("output.txt", "w", stdout);
    srand(time(0));
    p2d::init();
    p2d tmp;
    cerr<<"stage1"<<endl;
    p2d::set_range(200, 200);
    for (int i = 1; i <= 1000; ++i) {
        tmp.gen();
        cout << tmp;
    }
    cerr<<"stage2"<<endl;
    p2d::set_range(400, 400);
    for (int i = 1; i <= 1000; ++i) {
        tmp.gen();
        cout << tmp;
    }
    cerr<<"stage3"<<endl;
    p2d::set_range(600, 600);
    for (int i = 1; i <= 1000; ++i) {
        tmp.gen();
        cout << tmp;
    }
    cerr<<"stage4"<<endl;
    p2d::set_range(700, 700);
    for (int i = 1; i <= 1000; ++i) {
        tmp.gen();
        cout << tmp;
    }
    cerr<<"stage5"<<endl;
    p2d::set_range(900, 900);
    for (int i = 1; i <= 1000; ++i) {
        tmp.gen();
        cout << tmp;
    }

    return 0;
}