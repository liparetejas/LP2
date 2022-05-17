/*
* Name: Tejas Lipare
* Roll No.: 31149
* Date: 13/01/22
* Problem Statement: 
		Implement Depth First Search and Breadth First Search algorithm. Use an undirected graph
		and develop a recursive algorithm for searching all vertices of graph data structure.
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph {
private:
	int n;
	vector<vector<int>> adj_list;
	vector<bool> visited;

public:
	Graph(int n);

	void resetVisited();

	void InsertEdge(int, int);

	void DFS(int);

	void BFS(int);
};

Graph::Graph(int n)
{
	this->n = n;
	for (int i = 0; i < n; i++)
		adj_list.push_back(vector<int>());
	visited = vector<bool>(n, false);
}

void Graph::resetVisited()
{
	visited = vector<bool>(n, false);
}

void Graph::InsertEdge(int u, int v)
{
	adj_list[u].push_back(v);
	adj_list[v].push_back(u);
}

void Graph::DFS(int currentNode)
{
	visited[currentNode] = true;
	for (int adjNode : adj_list[currentNode])
	{
		if (visited[adjNode])
			continue;
		cout << adjNode << " ";
		DFS(adjNode);
	}
}

void Graph::BFS(int source)
{
	vector<int> dist(n, INT_MAX);
	dist[source] = 0;
	queue<int> q;
	q.push(source);
	while (!q.empty())
	{
		int currentNode = q.front();
		q.pop();
		cout << currentNode << " ";
		for (int adjNode : adj_list[currentNode])
		{
			if (dist[adjNode] == INT_MAX)
			{
				dist[adjNode] = dist[currentNode] + 1;
				q.push(adjNode);
			}
		}
	}
}

int main()
{
	int numOfNodes = -1;
	Graph* G = NULL;
	while (true)
	{
		cout << "********************** Graph Traversals ***********************" << endl;
		cout << "1. To enter number of nodes in graph." << endl;
		cout << "2. To enter edges between nodes of the graph." << endl;
		cout << "3. To traverse graph using DFS(Depth First Search) Algorithm." << endl;
		cout << "4. To traverse graph using BFS(Breadth First Search) Algorithm." << endl;
		cout << "5. To clear the graph." << endl;
		cout << "6. To terminate the program." << endl;
		cout << "***************************************************************" << endl;
		cout << "Current number of nodes: " << numOfNodes << endl;
		int opt = 0;
		cout << "Enter option: ";
		cin >> opt;
		switch (opt)
		{
			case 1:
			{
				cout << "Enter number of nodes: ";
				cin >> numOfNodes;
				G = new Graph(numOfNodes);
				break;
			}

			case 2:
			{
				cout << "Enter two nodes which have edge in between them (Valid range = [0, " << numOfNodes - 1 << "]): " << endl;
				cout << "Enter -1 -1 when done." << endl;
				while (true)
				{
					int u, v;
					cin >> u >> v;
					if (u == -1 && v == -1)
						break;
					if (u < 0 || u >= numOfNodes || v < 0 || v >= numOfNodes)
					{
						cout << "Invalid range! (Valid range = [0, " << numOfNodes - 1 << "]): " << endl;
						continue;
					}
					G->InsertEdge(u, v);
				}
				break;
			}

			case 3:
			{
				int start;
				cout << "Enter starting node of traversal using DFS algorithm: ";
				cin >> start;
				cout << start << " ";
				G->DFS(start);
				cout << endl;
				G->resetVisited();
				break;
			}

			case 4:
			{
				int start;
				cout << "Enter starting node of traversal using BFS algorithm: ";
				cin >> start;
				G->BFS(start);
				cout << endl;
				break;
			}

			case 5:
			{
				numOfNodes = -1;
				G == NULL;
				break;
			}

			case 6:
			{
				if(G)
					delete G;
				cout << "Program Terminated!" << endl;
				exit(0);
			}

			default:
			{
				cout << "Invalid Option" << endl;
			}
		}
		cout << endl;
	}
	return 0;
}

/*
* Input:
Nodes: 9
Edges:
0 7
7 8
7 2
2 8
1 2
1 4
1 3
0 5
3 5
3 6
-1 -1

* Output:
********************** Graph Traversals ***********************
1. To enter number of nodes in graph.
2. To enter edges between nodes of the graph.
3. To traverse graph using DFS(Depth First Search) Algorithm.
4. To traverse graph using BFS(Breadth First Search) Algorithm.
5. To clear the graph.
6. To terminate the program.
***************************************************************
Current number of nodes: -1
Enter option: 1
Enter number of nodes: 9

********************** Graph Traversals ***********************
1. To enter number of nodes in graph.
2. To enter edges between nodes of the graph.
3. To traverse graph using DFS(Depth First Search) Algorithm.
4. To traverse graph using BFS(Breadth First Search) Algorithm.
5. To clear the graph.
6. To terminate the program.
***************************************************************
Current number of nodes: 9
Enter option: 2
Enter two nodes which have edge in between them (Valid range = [0, 8]):
Enter -1 -1 when done.
0 7
7 8
7 2
2 8
1 2
1 4
1 3
0 5
3 5
3 6
-1 -1

********************** Graph Traversals ***********************
1. To enter number of nodes in graph.
2. To enter edges between nodes of the graph.
3. To traverse graph using DFS(Depth First Search) Algorithm.
4. To traverse graph using BFS(Breadth First Search) Algorithm.
5. To clear the graph.
6. To terminate the program.
***************************************************************
Current number of nodes: 9
Enter option: 3
Enter starting node of traversal using DFS algorithm: 0
0 7 8 2 1 4 3 5 6

********************** Graph Traversals ***********************
1. To enter number of nodes in graph.
2. To enter edges between nodes of the graph.
3. To traverse graph using DFS(Depth First Search) Algorithm.
4. To traverse graph using BFS(Breadth First Search) Algorithm.
5. To clear the graph.
6. To terminate the program.
***************************************************************
Current number of nodes: 9
Enter option: 4
Enter starting node of traversal using BFS algorithm: 0
0 7 5 8 2 3 1 6 4

********************** Graph Traversals ***********************
1. To enter number of nodes in graph.
2. To enter edges between nodes of the graph.
3. To traverse graph using DFS(Depth First Search) Algorithm.
4. To traverse graph using BFS(Breadth First Search) Algorithm.
5. To clear the graph.
6. To terminate the program.
***************************************************************
Current number of nodes: 9
Enter option: 3
Enter starting node of traversal using DFS algorithm: 6
6 3 1 2 7 0 5 8 4

********************** Graph Traversals ***********************
1. To enter number of nodes in graph.
2. To enter edges between nodes of the graph.
3. To traverse graph using DFS(Depth First Search) Algorithm.
4. To traverse graph using BFS(Breadth First Search) Algorithm.
5. To clear the graph.
6. To terminate the program.
***************************************************************
Current number of nodes: 9
Enter option: 4
Enter starting node of traversal using BFS algorithm: 8
8 7 2 0 1 5 4 3 6

********************** Graph Traversals ***********************
1. To enter number of nodes in graph.
2. To enter edges between nodes of the graph.
3. To traverse graph using DFS(Depth First Search) Algorithm.
4. To traverse graph using BFS(Breadth First Search) Algorithm.
5. To clear the graph.
6. To terminate the program.
***************************************************************
Current number of nodes: 9
Enter option: 5

********************** Graph Traversals ***********************
1. To enter number of nodes in graph.
2. To enter edges between nodes of the graph.
3. To traverse graph using DFS(Depth First Search) Algorithm.
4. To traverse graph using BFS(Breadth First Search) Algorithm.
5. To clear the graph.
6. To terminate the program.
***************************************************************
Current number of nodes: -1
Enter option: 1
Enter number of nodes: 5

********************** Graph Traversals ***********************
1. To enter number of nodes in graph.
2. To enter edges between nodes of the graph.
3. To traverse graph using DFS(Depth First Search) Algorithm.
4. To traverse graph using BFS(Breadth First Search) Algorithm.
5. To clear the graph.
6. To terminate the program.
***************************************************************
Current number of nodes: 5
Enter option: 2
Enter two nodes which have edge in between them (Valid range = [0, 4]):
Enter -1 -1 when done.
0 1
1 2
2 3
3 4
4 5
Invalid range! (Valid range = [0, 4]):
4 0
-1 -1

********************** Graph Traversals ***********************
1. To enter number of nodes in graph.
2. To enter edges between nodes of the graph.
3. To traverse graph using DFS(Depth First Search) Algorithm.
4. To traverse graph using BFS(Breadth First Search) Algorithm.
5. To clear the graph.
6. To terminate the program.
***************************************************************
Current number of nodes: 5
Enter option: 3
Enter starting node of traversal using DFS algorithm: 0
0 1 2 3 4

********************** Graph Traversals ***********************
1. To enter number of nodes in graph.
2. To enter edges between nodes of the graph.
3. To traverse graph using DFS(Depth First Search) Algorithm.
4. To traverse graph using BFS(Breadth First Search) Algorithm.
5. To clear the graph.
6. To terminate the program.
***************************************************************
Current number of nodes: 5
Enter option: 4
Enter starting node of traversal using BFS algorithm: 0
0 1 4 2 3

********************** Graph Traversals ***********************
1. To enter number of nodes in graph.
2. To enter edges between nodes of the graph.
3. To traverse graph using DFS(Depth First Search) Algorithm.
4. To traverse graph using BFS(Breadth First Search) Algorithm.
5. To clear the graph.
6. To terminate the program.
***************************************************************
Current number of nodes: 5
Enter option: 5

********************** Graph Traversals ***********************
1. To enter number of nodes in graph.
2. To enter edges between nodes of the graph.
3. To traverse graph using DFS(Depth First Search) Algorithm.
4. To traverse graph using BFS(Breadth First Search) Algorithm.
5. To clear the graph.
6. To terminate the program.
***************************************************************
Current number of nodes: -1
Enter option: 6
Program Terminated!
*/