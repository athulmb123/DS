#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100


struct Node {
    int dest;
    struct Node* next;
};

struct AdjList {
    struct Node* head;
};

struct Node* createNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

void addEdgeList(struct AdjList adj[], int s, int t) {
    struct Node* newNode = createNode(t);
    newNode->next = adj[s].head;
    adj[s].head = newNode;

    newNode = createNode(s);
    newNode->next = adj[t].head;
    adj[t].head = newNode;
}

void DFSRec(struct AdjList adj[], int visited[], int s) {
    visited[s] = 1;
    printf("%d ", s);

    struct Node* current = adj[s].head;
    while (current != NULL) {
        int dest = current->dest;
        if (!visited[dest]) {
            DFSRec(adj, visited, dest);
        }
        current = current->next;
    }
}

void DFS(struct AdjList adj[], int V, int start) {
    int visited[MAX] = {0}; 
    DFSRec(adj, visited, start);
}

void bfs(int adj[MAX][MAX], int V, int s) {
    int q[MAX], front = 0, rear = 0;
    bool visited[MAX] = { false };
    visited[s] = true;
    q[rear++] = s;

    while (front < rear) {
        int curr = q[front++];
        printf("%d ", curr);

        for (int i = 0; i < V; i++) {
            if (adj[curr][i] == 1 && !visited[i]) {
                visited[i] = true;
                q[rear++] = i;
            }
        }
    }
}


void addEdgeMatrix(int adj[MAX][MAX], int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void displayGraphList(struct AdjList adj[], int V) {
    for (int i = 0; i < V; i++) {
        printf("Vertex %d: ", i);
        struct Node* current = adj[i].head;
        while (current != NULL) {
            printf("%d -> ", current->dest);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void displayGraphMatrix(int adj[MAX][MAX], int V) {
    printf("Adjacency Matrix Representation:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int V = 6;
    int choice;

    printf("\t 1. DFS \n\t2. BFS \n Enter your choice : ");
    scanf("%d", &choice);

    int adj[MAX][MAX] = {0};

    struct AdjList adjList[V];
    for (int i = 0; i < V; i++) {
        adjList[i].head = NULL;
    }

    int edges[][2] = {{1, 2}, {2, 0}, {0, 3}, {4, 5}};
    int E = 4;

  
    for (int i = 0; i < E; i++) {
        addEdgeMatrix(adj, edges[i][0], edges[i][1]); // For BFS
        addEdgeList(adjList, edges[i][0], edges[i][1]); // For DFS
    }

    if (choice == 1) {
       
        printf("Graph (Adjacency List):\n");
        displayGraphList(adjList, V);

        int startDFS;
        printf("\nEnter the starting vertex for DFS: ");
        scanf("%d", &startDFS);

        printf("DFS traversal of the graph starting from vertex %d:\n", startDFS);
        DFS(adjList, V, startDFS);
    } else if (choice == 2) {

        printf("Graph (Adjacency Matrix):\n");
        displayGraphMatrix(adj, V);

        int startBFS;
        printf("\nEnter the starting vertex for BFS: ");
        scanf("%d", &startBFS);

        printf("BFS traversal starting from vertex %d:\n", startBFS);
        bfs(adj, V, startBFS);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}

