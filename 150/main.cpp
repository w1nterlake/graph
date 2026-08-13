#include <bits/stdc++.h>
#include <fstream>


int DFS(std::vector<std::vector<int>> &graph, int S){
    int size = graph.size() - 1;
    std::vector<int> used (size + 1, 0); 
    std::stack<int> st;
    int start = S;
    st.push(start);
    int count = 0;
    used[start] = 1;
    while(!st.empty()){
        int vertex = st.top();
        st.pop();
        for(int i = 0; i < graph[vertex].size(); i++){
            if(used[graph[vertex][i]] == 0){
                st.push(graph[vertex][i]);
                count++;
                used[graph[vertex][i]] = 1;
            }
        }
    }

    return count;
}





int main(){
    int N, S;
    std::ifstream fin("INPUT.TXT");
    std::ofstream fout("OUTPUT.TXT");
    fin >> N >> S;
    std::vector<std::vector<int>> graph_mat (N, std::vector<int>(N, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            fin >> graph_mat[i][j];
        }
    }
    std::vector<std::vector<int>> graph (N + 1);
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(graph_mat[i][j]){
                graph[i + 1].push_back(j + 1);
                graph[j + 1].push_back(i + 1);
            }
        }
    }
    int res = DFS(graph, S);
    fout << res;






    fin.close();
    fout.close();
    return 0;
}