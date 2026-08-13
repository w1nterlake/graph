#include <bits/stdc++.h>
#include <fstream>


bool DFS(std::vector<std::vector<int>> &graph){
    int N = graph.size() - 1;
    std::vector<int> used (N + 1, 0);
    std::stack<int> st;
    for(int start = 1; start <= N; start++){
        st.push(start);
        if(used[start]){
            continue;
        }
        while(!st.empty()){
            int v = st.top();
            st.pop();
            used[v] = 1;
            std::cout << v << " ";
            for(int k: graph[v]){
                if(used[k] == 0){
                    st.push(k);
                }
            }
        }
    }
    return true;
}


bool DFS2(std::vector<std::vector<int>> &graph, bool direct){
    int N = graph.size() - 1;
    std::vector<int> color (N + 1, 0);
    std::stack<int> st;
    std::vector<int> parent (N + 1, -1);
    for(int start = 1; start <= N; start++){
        if(color[start] != 0){
            continue;
        }
        st.push(start);
        color[start] = 1;
        while(!st.empty()){
            int v = st.top();
            bool went = false;



            for(int k: graph[v]){

                if(!direct && k == parent[v]){
                    continue;
                }

                if(color[k] == 1){
                    return true;
                }

                if(color[k] == 0){
                    parent[k] = v;
                    color[k] = 1;
                    st.push(k);
                    went = true;
                    break;
                }
            }
            if (!went) {
                color[v] = 2;
                st.pop();
            }
        }
    }
    return false;
}



int main(){
    int N;
    std::ifstream fin("INPUT.TXT");
    std::ofstream fout("OUTPUT.TXT");
    int a;
    fin >> N;
    std::vector<std::vector<int>> graph(N + 1);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            fin >> a;
            if(a){
                graph[i + 1].push_back(j + 1);
            }
        }
    }

    if(DFS2(graph, true)){
        fout << "Yes";
    }
    else{
        fout << "No";
    }



    fin.close();
    fout.close();
    return 0;
}