#include <bits/stdc++.h>
#include <fstream>




int main(){
    int N, M;
    std::ofstream fout("OUTPUT.TXT");
    std::ifstream fin("INPUT.TXT");
    fin >> N >> M;
    int v1, v2;
    std::vector<int> vertex (N + 1, 0);
    for(int i = 0; i < M; i++){
        fin >> v1 >> v2;
        vertex[v1]++;
        vertex[v2]++;
    }
    for(int i = 0; i < N; i++){
        fout << vertex[i + 1] << " ";
    }

    fout.close();
    fin.close();
    return 0;
}

