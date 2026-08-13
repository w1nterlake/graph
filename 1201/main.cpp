#include <bits/stdc++.h>
#include <fstream>




int main(){
    int N, M = 0;
    std::ifstream fin("INPUT.TXT");
    std::ofstream fout("OUTPUT.TXT");
    std::vector<std::vector<int>> graph_matrix (N, std::vector<int> (N, 0));
    std::vector<std::pair<int, int>> graph_edge;
    fin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            fin >> graph_matrix[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(graph_matrix[i][j] == 1){
                graph_edge.push_back(std::make_pair(i + 1, j + 1));
                M++;
            }
        }
    }
    fout << N << " " << M << "\n";
    for(int i = 0; i < M; i++){
        fout << graph_edge[i].first << " " << graph_edge[i].second << "\n";
    }



    fin.close();
    fout.close();
    return 0;
}