#include <bits/stdc++.h>
#include <fstream>


std::vector<std::vector<int>> DFS(std::vector<std::vector<int>> &graph, std::vector<int> &countries, int K){
    int N = graph.size() - 1;
    std::vector<std::vector<int>> ans(N + 1, std::vector<int>(0));
    std::vector<int> used(N + 1, 0);
    for(int i = 1; i < N + 1; i++){
        if(countries[i] == 0){
            continue;
        }
        std::stack<int> st;
        st.push(i);
        used[i] = 1;
        ans[i].push_back(i);
        while(!st.empty()){
            int v = st.top();
            st.pop();
            for(int to: graph[v]){
                if(used[to] == 0 && countries[to] == 0){
                    st.push(to);
                    used[to] = 1;
                    ans[i].push_back(to);
                }
            }
        }
    }
    return ans;
}


int main(){
    int N, M;
    std::ifstream fin("INPUT.TXT");
    std::ofstream fout("OUTPUT.TXT");
    fin >> N >> M;
    std::vector<std::vector<int>> graph (N + 1);
    int a, b;
    for(int i = 0; i < M; i++){
        fin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int K;
    fin >> K;
    std::vector<int> countries (N + 1, 0);
    int z;
    for(int i = 0; i < K; i++){
        fin >> z;
        countries[z] = 1;
    }


    std::vector<std::vector<int>> ans = DFS(graph, countries, K);


    for(int i = 1; i < N + 1; i++){
        if(ans[i].size() == 0){
            continue;
        }
        std::sort(ans[i].begin(), ans[i].end());
        fout << ans[i].size() << "\n";
        for(int j = 0; j < ans[i].size(); j++){
            fout << ans[i][j] << " ";
        }
        fout << "\n";
    }


    fin.close();
    fout.close();
    return 0;
}
