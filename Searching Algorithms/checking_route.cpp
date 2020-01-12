#include<stdio.h>
#include<array>
#include<vector>
#include <iostream>
#include <queue>
#include<set>

using namespace std;

typedef pair<int,int> pair_;

vector<vector<int>> createGraph(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight){
  vector<vector<int>> g (g_nodes, vector<int> (g_nodes,0));
  for(int i =0; i< g_from.size(); i++){
      g[g_from[i]-1][g_to[i]-1] = g_weight[i];
      g[g_to[i]-1][g_from[i]-1] = g_weight[i];
  }
  return g;
}

void createAdjList(vector<pair_> adjList[], int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight){

  for(int i =0; i < g_from.size(); i++){
    adjList[g_from[i]-1].push_back({g_to[i]-1,g_weight[i]});
    adjList[g_to[i]-1].push_back({g_from[i]-1,g_weight[i]});
  }

}

vector<string> classifyEdges(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight){

  vector<string> res;
  for(int i =0; i<g_from.size(); i++)
    res.push_back("NO");

  vector<vector<int>> graph = createGraph(g_nodes, g_from, g_to, g_weight);
  /*
  cout<<"graph"<<endl;
  for(int i =0; i<g_nodes; i++){
    for(int j =0; j <g_nodes; j++){
      cout<<graph[i][j] <<" ";
    }
    cout<<endl;
  }
  */

  vector<pair_> adjList[g_nodes];
  createAdjList(adjList, g_nodes, g_from, g_to, g_weight);
  /*
  cout<<"Adjaceny List"<<endl;
  for(int i =0; i< g_nodes; i++){
    cout<<i+1<<": ";
    for(auto x : adjList[i]){
      cout<<"{"<<x.first+1<<","<<x.second<<"} ";
    }
    cout<<endl;
  }
  */

  vector<int> dist (g_nodes, INT_MAX);
  dist[0] = 0;

  priority_queue< pair_, vector<pair_>, greater<pair_>> pq;
  pq.push({0,0});

  set<int> parent[g_nodes];
  //vector<bool> visited[g_nodes];
  vector<pair_> roads;


  while(!pq.empty()){

    int u = pq.top().second;
    pq.pop();

    for(auto x: adjList[u]){
      int v = x.first;
      int w = x.second;

      if(dist[v] >= dist[u]+w){

        dist[v] = dist[u]+w;
        pq.push({dist[v], v});

        if(dist[v] == dist[u]+w){
          parent[v].insert(u);
        }
        else{
          parent[v].erase(parent[v].begin(), parent[v].end());
          parent[v].insert(u);
        }
      }
    }
  }
  /*
  cout<<"Parents : "<<endl;
  for(int i =0; i< g_nodes; i++){
    cout<<i+1<<": ";
    for(auto x : parent[i]){
      cout<<x+1<< " ";
    }
    cout<<endl;
  }
  */

  queue<int> q;
  q.push(g_nodes-1);

  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(auto x: parent[u]){
      q.push(x);
      roads.push_back({u,x});
    }
  }

  /*
  cout<<"Roads: "<<" Size: "<<roads.size()<<endl;
  for(auto x: roads)
    cout<<"{"<<x.first+1<<" "<<x.second+1<<"} ";
  cout<<endl;

  cout<<"Vertex Distance from Source"<<endl;
  for (int i = 0; i < g_nodes; ++i)
      printf("%d \t\t %d\n", i+1, dist[i]);
  */


for(int i = 0; i < g_from.size(); i++){
  for(int j =0; j < roads.size(); j++){
  //cout<< "Roads: "<<roads[j].first<<","<< roads[j].second<<" "<<"Edges: "<<g_from[i]<<","<<g_to[i]<<endl;
  if(((roads[j].first==g_from[i]-1)&&(roads[j].second == g_to[i]-1))
    || ((roads[j].first==g_to[i]-1)&&(roads[j].second==g_from[i]-1))){
    res[i]= "YES";
  }
}
}
  return res;
}



int main(){
  /*
  int g_nodes = 5;
  vector<int> g_from {1,2,3,4,5,1,5};
  vector<int> g_to {2,3,4,5,1,3,3};
  vector<int> g_weight {1,1,1,1,3,2,1};
  */

  /*
  int g_nodes = 4;
  vector<int> g_from {1,2,1,3,1};
  vector<int> g_to {2,4,3,4,4};
  vector<int> g_weight {1,1,1,2,2};
  */

  /*
  int g_nodes = 5;
  vector<int> g_from {1,2,3,1,4,3,2};
  vector<int> g_to {2,3,5,4,5,4,4};
  vector<int> g_weight {1,1,1,1,2,2,4};
  */

  int g_nodes = 4;
  vector<int> g_from {1,1,1,2,2};
  vector<int> g_to {2,3,4,3,4};
  vector<int> g_weight {1,1,1,1,1};

  vector<string> res = classifyEdges(g_nodes, g_from, g_to, g_weight);

  for(auto i: res)
    cout<<i<<" ";

  cout<<endl;

  return 0;
}
