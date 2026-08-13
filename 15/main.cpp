#include <bits/stdc++.h>
#include <fstream>


int main(){
    int n;
    std::ifstream fin("INPUT.TXT");
    std::ofstream fout("OUTPUT.TXT");
    fin >> n;
    std::vector<std::vector<int>> graph (n, std::vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fin >> graph[i][j];
        }
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(graph[i][j] == 1){
                count++;
            }
        }
    }
    fout << count;


    fin.close();
    fout.close();
}