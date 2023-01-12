#include <bits/stdc++.h>
using namespace std;
vector<int> edgesSize;
vector<int> edgesOffset;
vector<int> find(int node){
    vector<int> tmp;
    for(int i = 0;i < edgesSize.size()-1;i++){
        if(edgesSize[i] == edgesSize[i+1]) continue;
        for(int j = edgesSize[i];j < edgesSize[i+1];j++){
            int k = j;
            if(k < edgesOffset.size() && k > 0){
                if(edgesOffset[k] == node) tmp.push_back(i);
            }
        }
    }
    return tmp;
}
void TakeInput(int *V, int *E) {
    ifstream file("./a.txt");
    file >> *V;
    file >> *E;
    int n_vertices = *V, n_edges = *E;
    int from, to;
    int idx = 0; 
    vector<vector<int>> adjacencyList(n_vertices);
	while (idx < n_edges) {
        file >> from;
        file >> to;
		adjacencyList.at(from).push_back(to);
        idx++;
	}
    edgesSize.push_back(0);
    int j = 1;
    for (int i = 0; i < n_vertices; ++i) {
        for(auto k : adjacencyList[i]){
            edgesOffset.push_back(k);
        }
		edgesSize.push_back(adjacencyList[i].size());
        edgesSize[j] += edgesSize[j-1];
        j++;
	}
}
int main(){
    int noOfVertices, noOfEdges;
    TakeInput(&noOfVertices, &noOfEdges);
    // for(int i = 0;i < edgesOffset.size();i++){
    //     cout << edgesOffset[i] << " ";
    // }
    // cout << "\n";
    // for(int i = 0;i < edgesSize.size();i++){
    //     cout << edgesSize[i] << " ";
    // }
    vector<int> out = find(4);
    // cout << out.size();
    for(int i = 0;i < out.size();i++) cout << out[i] << " ";
    return 0;
}

