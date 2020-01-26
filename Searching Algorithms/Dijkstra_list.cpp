#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

#define MAX_ 100000

using namespace std;

void create_list(vector<vector<pair<int,int>>> &list,vector<int> &from, vector<int> &to, vector<int> &weight){
  for(int i = 0; i < from.size(); i++){
    list[from[i]].push_back({to[i], weight[i]});
    list[to[i]].push_back({from[i], weight[i]});
  }
}


void dijkstra(int n, vector<int> &from, vector<int> &to, vector<int> &weight){

  vector<vector<pair<int,int>>> list (n);
  create_list(list,from, to, weight);
  int i = 0;

  for(auto row: list){
    cout<<i<<"  ->  ";
    for (auto val : row){
      cout<<"{"<<val.first<<","<<val.second<<"}   ";
    }
    i++;
    cout<<endl;
  }

  vector<int> distance (n, MAX_);
  distance[0] = 0;

  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;

  q.push({0,0});

  //parent
  unordered_map<int,int> parent;
  parent[0] = 0;

  while(!q.empty()){

    pair<int,int> cur = q.top();
    q.pop();

    int cur_weight = cur.first;
    int cur_node = cur.second;

    for(auto next_node: list[cur_node]){

      int new_to = next_node.first;
      int new_weight = next_node.second;

      if(distance[new_to] > (new_weight+distance[cur_node])){
        distance[new_to] = new_weight + distance[cur_node];
        q.push({distance[new_to], new_to});
        parent[new_to] = cur_node;
      }
    }
  }
  cout<<"Vertex Distance from source "<<endl;
  for(int i =0; i< n; i++)
    cout<<i <<"  "<<distance[i]<<" Parent: "<<parent[i]<<endl;

  cout<<"Root from 0 to 4: ";
  vector<int> route;
  int end = 4;
  int start = 0;
  route.push_back(end);
  while(true){
    int p = parent[end];
    if(p == start)
      break;
    route.push_back(p);
    end = p;

  }
  //reverse(route.begin(), route.end());
  for(auto path: route)
    cout<< path <<" ";

}


int main() {

  int g_nodes = 9;
  vector<int> g_from   {0, 0, 1,  1, 2, 2, 2, 3,  3,  4,  5, 6, 6, 7};
  vector<int> g_to     {1, 7, 2,  7, 3, 8, 5, 4,  5,  5,  6, 7, 8, 8};
  vector<int> g_weight {4, 8, 8, 11, 7, 2, 4, 9, 14, 10,  2, 1, 6, 7};

  dijkstra(g_nodes, g_from, g_to, g_weight);

	return 0;
}
