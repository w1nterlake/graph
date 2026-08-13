#include <bits/stdc++.h>
#include <fstream>



bool DFS(std::vector<std::vector<int>> &graph, int s){
    std::stack<int> st;
    int start = s;
    int size = graph.size() - 1;
    std::vector<int> used (size + 1, 0);
    st.push(start);
    used[start] = 1;
    bool tree = true;
    int edge = 0;
    while(!st.empty()){
        int vertex = st.top();
        st.pop();
        for(int i = 0; i < graph[vertex].size(); i++){
            if(used[graph[vertex][i]] == 0){
                used[graph[vertex][i]] = 1;
                st.push(graph[vertex][i]);
                
            }
            else{
                tree = false;
            }
        }


    }


    return tree;


}



int main(){
    int N;
    std::ifstream fin("INPUT.TXT");
    std::ofstream fout("OUTPUT.TXT");
    fin >> N;
    std::vector<std::vector<int>> graph(N, std::vector<int>(N, 0));
    
    for(int i =  0; i < N; i++){
        for(int j = 0; j < N; j++){
            fin >> graph[i][j];
        }
    }
    std::vector<std::vector<int>> graph_s (N + 1);

    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(graph[i][j] == 1){
                graph_s[i + 1].push_back(j + 1);
            }
        }
    }

    if(DFS(graph_s, 1)){
        fout << "YES";
    }
    else{
        fout << "NO";
    }



    fin.close();
    fout.close();
    return 0;
}