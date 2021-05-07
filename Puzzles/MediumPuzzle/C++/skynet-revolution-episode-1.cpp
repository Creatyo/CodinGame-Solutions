#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


struct Node // data structure node
{
    int A;
    bool GateWay = false;     // gate way virus is trying to get to
    bool pathvisited = false;      //paths we have visited
    vector<Node*> connections;     // links between the nodes
};

vector<Node> nodes;     // vector for nodes
vector<Node*> getGatewayLinks(Node* node) // node pointer for get gateway
{
    vector<Node*> nodes; // vector for nodes
    for (auto& connection : node->connections) // for-loop using variable connection scope resolution to look for total connections in the node
    {
        if (connection->GateWay)   // if connection scope points to gateway / exit
            nodes.push_back(connection); //add connection to the end of vector nodes
    }

    return nodes;     // return the vector nodes
}

pair<int, int> findRoute(Node* first)
{
     for (auto& node : nodes)  // finds movement of the virus
     node.pathvisited = false;     // return false when virus is not found because it moved away. 
     bool Location = false;   // location of virus
     pair<int, int> PlanB;    // if fails activate planB

    queue<Node*> pathway;     // Queue pathway
    pathway.push(first);      // add to pathway 
    while (!pathway.empty())  // if pathway is not empty 
    {
        Node* node = pathway.front();   // node = last element of the queue
        pathway.pop();   // pop/ remove the last element of the queue
        node->pathvisited = true;  //   

        vector<Node*> gatewayLinks = getGatewayLinks(node);
        if (gatewayLinks.size() > 1)
        {
            return {node->A, gatewayLinks[0]->A};
        }
        else if (gatewayLinks.size() == 1)
        {
            if (!Location)
            {
                Location = true;
                PlanB = {node->A, gatewayLinks[0]->A};
            }

            for (auto& neighbor : node->connections)
            {
                if (!neighbor->pathvisited)
                    pathway.push(neighbor);
            }
        }
        else 
        {
            if (!Location)
            {
                for (auto& neighbor : node->connections)
                {
                    if (!neighbor->pathvisited)
                    pathway.push(neighbor);
                }
            }
        }
    }
    if (Location)
        return PlanB;
}

int main()
{
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    cin >> N >> L >> E; cin.ignore();

    nodes.resize(N);

    for (int i = 0; i < N; ++i)
        nodes[i].A = i;

    for (int i = 0; i < L; i++)
     {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
        nodes[N1].connections.push_back(&nodes[N2]);
        nodes[N2].connections.push_back(&nodes[N1]);
     }

    for (int i = 0; i < E; i++)
     {
        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();
        nodes[EI].GateWay = true;
    }

    // game loop
    while (1)
     {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();
        pair<int, int> connection = findRoute(&nodes[SI]);
        cout << connection.first << " " << connection.second << endl;
    }
}