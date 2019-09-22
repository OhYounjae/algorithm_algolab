#include <iostream>
#include <fstream>

using namespace std;


int main(){
    ifstream in;
    in.open("input.txt");
    
    int tri_li[51]; //삼각수 저장
    
    
    for(int i = 1; i <= 50; i++){
        tri_li[i] = i * (i+1) / 2;
    }

    int tri[1000]; //세개의 삼각수의 합 저장
    int sum;
    for(int i = 1; i<= 50; i++){
            for(int j = 1; j<=50; j++){
                for(int w = 1; w<=50; w++){
                    sum = tri_li[i] + tri_li[j] + tri_li[w];
                    if(sum <= 1000){
                        tri[sum] = 1;
                    }
                }
            }
        }

    int t;
    in >> t;

    while(t--){
        int temp;
        in >> temp;

        if(tri[temp] == 1){
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
      
    }

     in.close();
}