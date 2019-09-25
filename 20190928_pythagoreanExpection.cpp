#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream in;
    in.open("input.txt");
    int t;
    in >> t;
    while(t--){
        int n, m;
        in >> n >> m; //n은 팀 개수, m은 전체 경기 수
        int arr[n];
        for(int i = 0; i < m; i++){
            int team1, team2;
            in >> team1 >> team2;
            
        }

    }

}