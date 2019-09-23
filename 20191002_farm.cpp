#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ifstream in;
    in.open("input.txt");
    int t;
    in >> t;
    vector<pair<int, int> > temp;

    while(t--){
        int a,b,n,w;
        in >> a >> b >> n >> w;
        // cout << a << ' '<< b << ' '<< n << ' ' << w << endl;
        for(int i = 1;i < n;i++){
            if(a * i + (n-i) * b == w){
                temp.push_back(make_pair(i, n-i));
            }
        }

        if(temp.size() == 1){
            cout << temp[0].first << temp[0].second << endl;
        }else{
            cout << -1 << endl;
        }
        temp.clear();
        
    }

    in.close();
}