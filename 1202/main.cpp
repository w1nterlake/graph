#include <bits/stdc++.h>
#include <fstream>





int main(){
    std::ifstream fin("INPUT.TXT");
    std::ofstream fout("OUTPUT.TXT");
    int N, M;
    fin >> N >> M;
    std::vector<std::pair<int, int>> graph1 (M);
    std::vector<std::vector<int>> graph2 (N + 1);
    for(int i = 0; i < M; i++){
        int v1, v2;
        fin >> v1 >> v2;
        graph1[i].first = v1;
        graph1[i].second = v2;
    }

    for(int i = 0; i < M; i++){
        graph2[graph1[i].first].push_back(graph1[i].second);
    }
    fout << N << "\n";
    for(int i = 1; i < N + 1; i++){
        
        if(graph2[i].size() == 0){
            fout << 0 << "\n";
        }
        else{
            std::sort(graph2[i].begin(), graph2[i].end());
            fout << graph2[i].size() << " ";
            for(int j = 0; j < graph2[i].size(); j++){
                fout << graph2[i][j] << " ";
            }
            fout << "\n";
        }
    }



    fin.close();
    fout.close();
    return 0;
}
