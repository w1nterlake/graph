#include <bits/stdc++.h>
#include <fstream>


bool DFS(std::vector<std::vector<int>> &graph){
    int size = graph.size() - 1;
    std::vector<int> used (size + 1, 0);
    std::stack<int> st;
    int ans = true;
    for(int start = 1; start <= size; start++){

    if(used[start] != 0){
        continue;
    }

    st.push(start);
    used[start] = 1;
    
    while(!st.empty()){
        int vertex = st.top();
        st.pop();
        for(int child: graph[vertex]){
            if(used[child] == 0){
                if(used[vertex] == 1){
                    used[child] = 2;
                }
                else if(used[vertex] == 2){
                    used[child] = 1;
                }
                st.push(child);
            }
            else if(used[child] == used[vertex]){
                ans = false;
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
    std::vector<std::vector<int>> graph(N + 1);
    int a, b;
    for(int i = 0; i < M; i++){
        fin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    if(DFS(graph)){
        fout << "YES";
    }
    else{
        fout << "NO";
    }





    fin.close();
    fout.close();
    return 0;
}