#include <iostream>
#include <vector>
using namespace std;

class DisjointSet{
    public:
    vector<int> Rank;
    vector<int> Parent;
    vector<int> Size;
    int ComponentCount;

    DisjointSet(int n){
        Rank.resize(n+1,0);
        this->ComponentCount = n;
        Parent.resize(n+1);
        Size.resize(n+1,1);
        for(int i=0;i<n+1;i++){
            Parent[i]=i;
        }
    }

    int FindUltimateParent(int Node){
        if(Node == Parent[Node]){
            return Node;
        }
        Parent[Node]=FindUltimateParent(Parent[Node]);
        return Parent[Node];
    }
    
    void UnionByRank(int U,int V){
        int ULP_U=FindUltimateParent(U);
        int ULP_V=FindUltimateParent(V);
        if(ULP_U == ULP_V){
            return;
        }
        if(Rank[ULP_U] < Rank[ULP_V]){
            Parent[ULP_U]=ULP_V;
        }
        else if(Rank[ULP_U] > Rank[ULP_V]){
            Parent[ULP_V]=ULP_U;
        }
        else{
            Parent[ULP_V]=ULP_U;
            Rank[ULP_U]++;
        }
        ComponentCount = ComponentCount - 1;
    }

    void UnionBySize(int U,int V){
        int ULP_U=FindUltimateParent(U);
        int ULP_V=FindUltimateParent(V);
        if(ULP_U == ULP_V){
            return;
        }
        if(Size[ULP_U] < Size[ULP_V]){
            Parent[ULP_U]=ULP_V;
            Size[ULP_V] += Size[ULP_U];
        }
        else{
            Parent[ULP_V]=ULP_U;
            Size[ULP_U] += Size[ULP_V];
        }
        ComponentCount = ComponentCount - 1;
    }
    int GetComponentCount(){
        return this->ComponentCount;
    }
};
int main() {
    DisjointSet ds(7);
    ds.UnionBySize(1,2);
    ds.UnionBySize(2,3);
    ds.UnionBySize(4,5);
    ds.UnionBySize(6,7);
    ds.UnionBySize(5,6);
    // At this stage check whether 3 and 7 belong to the same component or not ?
    if(ds.FindUltimateParent(3) == ds.FindUltimateParent(7)){
        cout<<"Both Belongs to Same Component"<<endl;
    }
    else{
        cout<<"Both Belongs to Different Component"<<endl;
    }
    // do a union of 3 and 7 
    ds.UnionBySize(3,7);
    //again check the same thing ?
    if(ds.FindUltimateParent(3) == ds.FindUltimateParent(7)){
        cout<<"Both Belongs to Same Component"<<endl;
    }
    else{
        cout<<"Both Belongs to Different Component"<<endl;
    }

    return 0;
}
