#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
int maxy, maxx, anssize;
int main() {
    int n;
    cin >> n;
    int a, b, i, j;
    for(i=0; i<n; i++){
        cin >> a >> b;
        v.push_back({a, b});
        if(b >= maxy){
            maxx = a;
            maxy = b;
        }
    }
    sort(v.begin(), v.end());

    i = 0;
    int beforey = 0;
    int startx = 0;
    while(v[i].first <= maxx){
        if(v[i].second == maxy && v[i].first < startx)
            startx = v[i].first;
        else if(v[i].second > beforey){
            anssize += (v[i].first - startx) * beforey;
            beforey = v[i].second;
            startx = v[i].first;
        }
        i++;
    }
    
    j = v.size() - 1;
    int aftery = 0;
    int endx = v[v.size()-1].first + 1;
    while(v[j].first >= maxx){
        if(v[j].second == maxy && v[j].first > endx)
            endx = v[i].first;
        else if(v[j].second > aftery){
            anssize += (endx - v[j].first) * aftery;
            aftery = v[j].second;
            endx = v[j].first;
        }
        j--;
    }
    
    anssize += max(endx - startx + 1, 1) * maxy;
    cout << anssize;
}
