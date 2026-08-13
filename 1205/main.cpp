#include <bits/stdc++.h>
#include <fstream>



int main(){
    int N;
    std::ifstream fin("INPUT.TXT");
    std::ofstream fout("OUTPUT.TXT");
    fin >> N;
    std::vector<std::vector<int>> graph (N, std::vector<int>(N, 0));
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            fin >> graph[i][j];
        }
    }
    std::vector<int> ans(N + 1, 0);

    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(graph[i][j] == 1){
                ans[i + 1]++;
                ans[j + 1]++;
            }
        }
    }
    bool fl = false;
    for(int i = 2; i < N + 1; i++){
        if(ans[i] != ans[i - 1]){
            fout << "NO";
            fl = true;
            break;
        }
    }
    if(!fl){
        fout << "YES";
    }
    




    fin.close();
    fout.close();
    return 0;
}



