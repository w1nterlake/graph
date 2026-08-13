#include <bits/stdc++.h>
#include <fstream>


int main(){
    int N;
    std::ifstream fin("INPUT.TXT");
    std::ofstream fout("OUTPUT.TXT");
    fin >> N;
    std::vector<std::vector<int>> graph (N, std::vector<int> (N, 0));
    std::vector<int> ans(N + 1, 0);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            fin >> graph[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(graph[i][j] == 1){
                ans[i + 1]++;
                ans[j + 1]++;
            }
        }
    }
    for(int i = 0; i < N; i++){
        fout << ans[i + 1] << " ";
    }


    fin.close();
    fout.close();
    return 0;
}