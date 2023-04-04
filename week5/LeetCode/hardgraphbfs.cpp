#include <iostream>
#include <queue>
#include <set>
using namespace std;



struct adjNode {
    int val, cost;
    adjNode* next;
};


struct graphEdge {
    int start_ver, end_ver, weight;
};
class DiaGraph{

    adjNode* getAdjListNode(int value, int weight, adjNode* head)   {
        adjNode* newNode = new adjNode;
        newNode->val = value;
        newNode->cost = weight;
         
        newNode->next = head;   
        return newNode;
    }
    int N;  
public:
    adjNode **head;                //adjacency list as array of pointers
    // Constructor
    DiaGraph(graphEdge edges[], int n, int N)  {
       
        head = new adjNode*[N]();
        this->N = N;

        for (int i = 0; i < N; ++i)
            head[i] = nullptr;

        for (unsigned i = 0; i < n; i++)  {
            int start_ver = edges[i].start_ver;
            int end_ver = edges[i].end_ver;
            int weight = edges[i].weight;
            // insert in the beginning
            adjNode* newNode = getAdjListNode(end_ver, weight, head[start_ver]);
             
                        // point head pointer to new node
            head[start_ver] = newNode;
             }
    }

     ~DiaGraph() {
    for (int i = 0; i < N; i++)
        delete[] head[i];
        delete[] head;
     }
};
void display_AdjList(adjNode* ptr, int i)
{
    while (ptr != nullptr) {
        cout << "(" << i << ", " << ptr->val
            << ", " << ptr->cost << ") ";
        ptr = ptr->next;
    }
    cout << endl;
}
vector<int> ch(adjNode* ptr, int i)
{
    vector<int> result;
    while (ptr != nullptr) {
        result.push_back(ptr->val);
        
        ptr = ptr->next;
    }
    return result;
}

int main()
{
    graphEdge edges[] = {
        {0,1,2},{0,2,4},{0,3,2},{1,4,3},{2,3,2},{3,1,4},{4,3,3}
    };
    int N = 6;      
    // calculate number of edges
    int n = sizeof(edges)/sizeof(edges[0]);

    DiaGraph diagraph(edges, n, N);
    
    for (int i = 0; i < N; i++)
    {
        // display adjacent vertices of vertex i
        display_AdjList(diagraph.head[i], i);
    }

    vector<int> result = ch(diagraph.head[0], 0);
    queue<int> q;
    for(int i= 0; i< result.size();i++){
        q.push(result[i]);
    }
    set<int> was;

    while(!q.empty()){
        int y = q.front();
        cout<< y<< endl;
        q.pop();
        if(!was.count(y)){
            if(y == 4){
                cout << "find" << y;
                break;
            }else{
                was.insert(y);
                vector<int> rr = ch(diagraph.head[y], 0);
                for(int i= 0; i< rr.size();i++){
                    q.push(rr[i]);
                    cout<<"this is from new node"<< rr[i]<< " ";
                }
            }
        }
    }


    return 0;
}