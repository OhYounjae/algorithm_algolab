#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

vector<int> truck; 
queue<int> car;

int main(){
    ifstream in;
    in.open("input.txt");
    
    int t;
    in >> t;
    while(t--){
        int n, w, L;
        in >> n >> w >> L;
        //n: 트럭의 수, w: 다리의 길이, L: 최대하중
        
        int weight = 0;
        while (n--){ //큐에 각 트럭의 무게 입력
            int temp;
            in >> temp;
            truck.push_back(temp);
        }
        
        for(int i = 0; i < truck.size(); i++){
            int temp;
            if(weight = 0){
                temp = truck[i];
                car.push(temp);
                weight += temp;
            }
        }
    }
}