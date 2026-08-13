#include <bits/stdc++.h>
#include <fstream>


int main(){
    int N;
    std::ifstream fin("INPUT.TXT");
    std::ofstream fout("OUTPUT.TXT");
    fin >> N;
    std::vector<std::vector<int>> graph (N, std::vector<int> (N, 0));

    for(int i =  0; i < N; i++){
        for(int j = 0; j < N; j++){
            fin >> graph[i][j];
        }
    }
    bool fl = false;
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            if(graph[i][j] != graph[j][i]){
                fl = true;
            }
        }
        if(graph[i][i] == 1){
            fl = false;
            break;
        }
    }

    if(fl){
        fout << "YES";
    }
    else{
        fout << "NO";
    }

    fin.close();
    fout.close();
    return 0;
}