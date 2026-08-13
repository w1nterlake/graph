#include <bits/stdc++.h>
#include <fstream>



std::vector<std::vector<int>> floyd(std::vector<std::vector<int>> &graph){
    int N = graph.size();
    std::vector<std::vector<int>> dist(N, std::vector<int> (N, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(graph[i][j] == -1){
                dist[i][j] = INT_MAX;
            }
            else{
                dist[i][j] = graph[i][j];
            }
        }
    }  

    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX){
                    continue;
                }

                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }

            }
        }
    }
    return dist;
}



int main(){
    int N;
    std::ifstream fin("INPUT.TXT");
    std::ofstream fout("OUTPUT.TXT");
    fin >> N;
    std::vector<std::vector<int>> graph(N, std::vector<int> (N, 0));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            fin >> graph[i][j];
        }
    }

    std::vector<std::vector<int>> res = floyd(graph);

    int max = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(res[i][j] != INT_MAX && max < res[i][j]){
                max = res[i][j];
            }
        }
    }

    fout << max;

    fin.close();
    fout.close();
    return 0;
}


