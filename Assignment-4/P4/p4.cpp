#include <iostream> 
#include <list> 
using namespace std; 
  
class Graph{
    public:
    int V; 
    list <int> *a;
    Graph(int V);
    bool vloop(int v);  
    void edge(int v1, int v2); 
};
Graph::Graph(int V){ 
    this->V = V; 
    a=new list <int> [V]; 
} 
void Graph::edge(int v1, int v2){ 
    a[v1].push_back(v2); 
} 
bool Graph::vloop(int v){ 
    int start=v;
    bool *visited=new bool[V]; 
    for (int i=0; i<V; i++) 
        visited[i]=false; 
    list<int> path; 
    visited[v]=true; 
    path.push_back(v); 
    list<int>::iterator i; 
    while(!path.empty()){ 
        v=path.front(); 
        path.pop_front(); 
        for (i=a[v].begin(); i!=a[v].end(); ++i){ 
            if (*i==start) 
                return true; 
            if (!visited[*i]){
                visited[*i] = true; 
                path.push_back(*i); 
            } 
        } 
    } 
    return false; 
} 

int main(){ 
	int V, E, x;
	int v1, v2;
	cin >> V >> E;
    Graph g(V);
    for (int i=0; i<E; i++){
    	cin >> v1 >> v2;
    	g.edge(v1, v2);
    }
    cin >> x;
    cout << g.vloop(x);
} 