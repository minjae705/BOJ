#include <iostream>
using namespace std;

void print(int size, int i, int j) {
    if(i / size % 3 == 1 && j / size % 3 == 1)
        cout << " ";
    else if(size / 3 == 0)
        cout << "*";
    else
        print(size / 3, i, j);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            print(n, i, j);
        cout << '\n';
    }
    
    return 0;
}
