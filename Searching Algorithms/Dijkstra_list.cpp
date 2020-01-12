#include <iostream>
#include<vector>
#include<stdio.h>
#include<queue>

using namespace std;

#define MAX_ 1000000

typedef vector<pair<int,int>> node;
typedef pair<int, int> pair_;


void create_adj_list(node list[], int n, vector<int> from, vector<int> to, vector<int> weight){

  for(int i =0; i< from.size(); i++){
    list[from[i]].push_back({to[i],   weight[i]});
    list[to[i]]  .push_back({from[i], weight[i]});
  }
}

void dijk(int n, vector<int> from, vector<int> to, vector<int> weight){

  node list[n];
  vector<int> dist(n, MAX_);
  dist[0] = 0;
  priority_queue< pair_, node, greater<pair_>> pq; //min queue

  create_adj_list(list, n, from, to, weight);

  //print the adjaceny list
  for(int i =0; i< n; i++){
    cout<<i<<": ";
    for(auto x: list[i]){
      cout<<"{"<<x.first<<", "<<x.second<<"} ";
    }
    cout<<endl;
  }

  pq.push({0,0});

  while(!pq.empty()){

    pair_ temp = pq.top();
    pq.pop();

    int u = temp.second;

    for(auto x: list[u]){
      int v = x.first;
      int w = x.second;

      if(dist[v] > dist[u] + w){
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }

  }

  cout<<"Vertex Distance from source "<<endl;

  for(int i =0; i< n; i++)
    cout<<i <<"  "<<dist[i]<<endl;

}

int main() {

  int g_nodes = 9;
  vector<int> g_from   {0, 0, 1,  1, 2, 2, 2, 3,  3,  4,  5, 6, 6, 7};
  vector<int> g_to     {1, 7, 2,  7, 3, 8, 5, 4,  5,  5,  6, 7, 8, 8};
  vector<int> g_weight {4, 8, 8, 11, 7, 2, 4, 9, 14, 10,  2, 1, 6, 7};

  dijk(g_nodes, g_from, g_to, g_weight);

	return 0;
}
