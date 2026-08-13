#include <bits/stdc++.h>
#include <fstream>



int main(){
    int N, M;
    std::ifstream fin("INPUT.TXT");
    std::ofstream fout("OUTPUT.TXT");
    fin >> N >> M;
    std::vector<std::pair<int, int>> graph1 (M);
    for(int i = 0; i < M; i++){
        fin >> graph1[i].first >> graph1[i].second; 
    }
    std::vector<std::vector<int>> graph2(N, std::vector<int>(N, 0));
    for(int i = 0; i < M; i++){
        graph2[graph1[i].first - 1][graph1[i].second - 1] = 1;
        graph2[graph1[i].second - 1][graph1[i].first - 1] = 1;
    }
    int count = 0;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(graph2[i][j]){
                count++;
            }
        }
    }
    if(count == N * (N - 1) / 2){
        fout << "YES";
    }
    else{
        fout << "NO";
    }

    fin.close();
    fout.close();
    return 0;
}