#include <bits/stdc++.h>
#include <fstream>



std::vector<std::vector<int>> floyd(std::vector<std::vector<int>> &graph){
    int N = graph.size();
    std::vector<std::vector<int>> dist(N, std::vector<int> (N, INT_MAX));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j){
                dist[i][j] = 0;
            }
            else if(graph[i][j]){
                dist[i][j] = 1;
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
    std::vector<std::vector<int>> graph (N, std::vector<int> (N, 0));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            fin >> graph[i][j];
        }
    }

    std::vector<std::vector<int>> dist = floyd(graph);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(dist[i][j] == INT_MAX){
                fout << 0 << " ";
            }
            else{
                fout << 1 << " ";
            }
        }
        fout << "\n";
    }



    fin.close();
    fout.close();
    return 0;
}