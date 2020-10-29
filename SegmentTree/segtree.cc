#include <iostream>
#include <vector>
#define ll long long


using namespace std;


class segtree{
    public:
    vector <ll> tree;
    int size;

    segtree(int n){
        for (size = 1; size < n; size *= 2);
        tree.resize(2*size);
    }

    void update(int pos, ll x){
        int index = size + pos - 1;
        int u = x - tree[index];

        while (index){
            tree[index] += u;
            index /= 2;
        }
    }

    ll getsum(int pos, int left, int right, int start, int end){
        if (right < start || left > end){
            return 0;
        }

        if (start >= left && end <= right){
            return tree[pos];
        }

        int mid = (start + end) / 2;
        return getsum(pos * 2, left, right, start, mid) + getsum(pos * 2 + 1, left, right, mid+1, end);
    }

};