#include<iostream>
#include<vector>
using namespace std;
class Disjoint_Set{
    public:
    vector<int> parent, rank, size;
    Disjoint_Set(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findParent(int num){
        if(parent[num]==num){
            return num;
        }
        return parent[num] = findParent(parent[num]);
    }

    void UnionByRank(int u, int v){
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_u] = ulp_v;
            rank[v]++;
        }
    }

    void UnionBySize(int u, int v){
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
int main()
{
    Disjoint_Set ds(7);
    ds.UnionByRank(1,2);
    ds.UnionByRank(2,3);
    ds.UnionByRank(4,5);
    ds.UnionByRank(6,7);

    if(ds.findParent(2) == ds.findParent(3)){
        cout<<"Same Component"<<endl;
    }else{
        cout<<"Not Same Component"<<endl;
    }

    ds.UnionByRank(5,6);

    if(ds.findParent(2) == ds.findParent(6)){
        cout<<"Same Component"<<endl;
    }else{
        cout<<"Not Same Component"<<endl;
    }

    return 0;
}