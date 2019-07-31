#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>


using namespace std;

typedef pair<int, pair<int,int>> node;
typedef vector<int> point;

void dijkstra(vector<vector<int>> &map, vector<int> &start, vector<int> &end){

  int m = map.size();
  int n = map[0].size();
  vector<pair<int,int>> result;
  //unordered_map<int, point> came_from;

  vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
  vector<vector<int>> visited(m, vector<int>(n, 100));
  priority_queue<node, vector<node>, greater<node>> q;

  q.push({0,{start[0],start[1]}});
  result.push_back({start[0],start[1]});
  visited[start[0]][start[1]] = 0;

  while(!q.empty()){
    node temp = q.top();
    q.pop();

    int x = temp.second.first;
    int y = temp.second.second;

    if(x == end[0] && y == end[1])
      break;

    if(visited[x][y] < temp.first)
      continue;

    for(auto& d: directions){
      int new_x = x + d[0];
      int new_y = y + d[1];

      if(new_x>=0 && new_y>=0 && new_x<m && new_y<n && map[new_x][new_y]!=1){
        if(visited[new_x][new_y] > visited[x][y]+1){
          visited[new_x][new_y] = visited[x][y]+1;
          int cost = visited[x][y]+1;
          q.push({cost,{new_x,new_y}});
        }
      }
    }
  }

  for(int i =0; i<m; i++){
    for(int j =0; j<n; j++){
      cout<<visited[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;

  //print result;
  //for(int i =0; i<result.size(); i++)
    //cout<<"("<<result[i].first<<","<<result[i].second<<")"<<" ";
  cout<<endl;
}

int main(){

  vector<vector<int>> map = {{0,0,1,0,0,0},
                             {0,0,1,0,1,0},
                             {0,0,0,0,1,0},
                             {0,0,0,0,1,0},
                             {0,0,1,1,1,0},
                             {0,0,0,0,0,0}};
  vector<int> start = {0,0};
  vector<int> end   = {5,5};

  dijkstra(map, start,end);

}
