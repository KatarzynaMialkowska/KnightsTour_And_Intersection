#include<iostream>
#include<vector>
#include<list>
#include <stack>
#include <queue>


std::vector<int> BFS(std::vector<std::list<int>>v, int start, int end, std::vector<bool>free) {
    
    std::vector<int>road;
    if(start == end)return {start};

    std::vector<bool>visited(v.size(),false);

    std::queue<int> q;
    visited[start] = true;
    q.push(start);
    int temp = 0; 

    while(!q.empty())
    {
        start = q.front();
        if(temp!=0 && free[start] == false) 
            return {};
        road.push_back(start);
        q.pop();
 
        for (auto i: v[start]) {
            if(i == end){
                road.push_back(i);
                return road;
            } 
            if (!visited[i] && free[i]==true){
                visited[i] = true;
                q.push(i);
            }
        }
       temp++;
    }
  return {};
}

void intersection(std::vector<std::list<int>>v){

    std::vector<int> result;
    std::vector<bool> free(v.size(),true);
    std::vector<std::vector<int>>allRoad;

    for(size_t i = 0; i < v.size(); i++)
        for(size_t j = 0; j < v.size(); j++){
            result = BFS(v, i, j, free);
            if(result.size()>1){
                allRoad.push_back(result);
                for(size_t i = 1; i< result.size()-1;i++){
                    free[result[i]]=false;
                }
            }
         
        }

    for(size_t i=0;i<allRoad.size();i++){
        std::cout<<"\n";
        for(auto j : allRoad[i])
            std::cout<<j<<" ";
    }
       
}


int main(){

    std::vector<std::list<int>>Graph;
    Graph.push_back({1});
    Graph.push_back({0,2,3,4});
    Graph.push_back({1,3,4});
    Graph.push_back({1,2});
    Graph.push_back({1,2});
    for(size_t i = 0; i<Graph.size(); i++){
        std::cout<<i<<": ";
        for(auto j : Graph[i])
            std::cout<<j<<" "; 
        std::cout<<"-degree-"<<Graph[i].size(); 
        std::cout<<'\n';   
    }
    intersection(Graph);

    return 0;
}