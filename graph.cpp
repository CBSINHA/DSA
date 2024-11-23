#include<iostream>
#include<unordered_map>
#include<list>
#include<set>
#include<queue>
using namespace std;
class Graph{
    public:
    unordered_map<int,set<int>> adj;
    void addEdge(int u,int v){
        adj[u].insert(v);
        adj[v].insert(u);
    }
    void display(){
        for(auto i: adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    void bfs(int start){
        unordered_map<int,bool>visited;
        queue<int>q;
        q.push(start);
        visited[start]=1;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            cout<<front<<" ";
            for(auto i: adj[front]){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
    }
    void dfsHelper(int start,unordered_map<int,bool>&visited){
        visited[start]=1;
        cout<<start<<" ";
        for(auto i:adj[start]){
            if(!visited[i]){
                dfsHelper(i,visited);
            }
        }
    }
    void dfs(int start){
        unordered_map<int,bool>visited;
        dfsHelper(start,visited);
        for(auto i:adj){
            if(!visited[i.first])
                dfsHelper(i.first,visited);
        }
    }
};
int main(){
    Graph g;
    int n,m;
    // cout<<"enter number of vertices:"<<endl;
    // cin>>n;
    // cout<<"Enter number of edges: "<<endl;
    // cin>>m;
    // for(int i=0;i<m;i++){
    //     int e,v;
    //     cout<<"Enter edge and vertex: ";
    //     cin>>e>>v;
    //     g.addEdge(e,v);
    // }
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    cout<<"The adj list:"<<endl;
    g.display();
    cout<<"BFS:"<<endl;
    g.bfs(1);
    cout<<"\nDFS:"<<endl;
    g.dfs(1);
}