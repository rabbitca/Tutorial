#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int T;
    cin >> T;
    int nodes, edges;
    int sNode;
    while (T-- > 0){
        cin >> nodes >> edges;
        int start[edges+1], end[edges+1];
        int distance[nodes+1];
        for ( int i = 0; i < edges; i++){
            cin >> start[i+1] >> end[i+1];
        }
        cin >> sNode;
        for (int i = 0; i < nodes; i++){
            distance [i+1] = -1;
        }
        list<int> queue;
        queue.push_back(sNode);
        distance[sNode]=0;
        
        while (!queue.empty()){
            int sFront = queue.front();
            queue.pop_front();
            for ( int i = 0; i < edges; i++){
                if (sFront == start[i+1] && distance[end[i+1]] == -1){
                    distance[end[i+1]] = distance[sFront] + 6;
                    queue.push_back(end[i+1]);
                }
                if (sFront == end[i+1] && distance[start[i+1]] == -1){
                    distance[start[i+1]] = distance[sFront] + 6;
                    queue.push_back(start[i+1]);
                }                
            }
            
        }
        for (int i = 0; i < nodes; i++){
            if ( i+1 != sNode )
            cout << distance [i+1] << " ";
        }
        cout << endl;
    }
    return 0;
}
