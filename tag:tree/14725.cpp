#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

struct Node{
    map<string, Node*> tree;
    
    void insert(vector<string> v, int idx){
        if(idx == v.size())
            return;
        map<string, Node*>::iterator it;
        if((it=tree.find(v[idx])) == tree.end()){
            Node* next = new Node;
            tree.insert({v[idx], next});
            next->insert(v, idx+1);
        }
        else{
            (it->second)->insert(v, idx+1);
        }
    }
    
    void find(int level){
        if(tree.size() == 0)
            return;
        for(auto &x:tree){
            for(int i=0;i<level;i++)
                cout << "--";
            cout << x.first << '\n';
            x.second->find(level+1);
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    Node* root = new Node;
    int n, k;
    
    cin >> n;
    while(n--){
        cin >> k;
        vector<string> str;
        while(k--){
            string s;
            cin >> s;
            str.push_back(s);
        }
        root->insert(str, 0);
    }
    root->find(0);
    return 0;
}
