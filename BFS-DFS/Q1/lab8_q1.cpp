#include <iostream>
using namespace std;
int q1[100];
int f1 = -1;
int r1 = -1;
void enque1(int n) 
{
    if (f1 == -1 && r1 == -1) 
    {
        f1 = 0;
        r1 = 0;
        q1[r1] = n;
    } 
    else 
    {
        r1++;
        q1[r1] = n;
    }
}
int deque1() 
{
    int n = q1[f1];
    if (f1 == r1) 
    {
        f1 = -1;
        r1 = -1;
    } 
    else
    f1++;
    return n;
}
class node 
{
public:
    int vertex;
    int color;
    int distance;
    int parent;
    int ditime;
    int fintime;
    node* next;

    node(int val) 
    {
        vertex = val;
        color = 0;
        distance = -1;
        parent = -1;
        ditime = 0;
        fintime = 0;
        next = NULL;
    }
};
class graph 
{
public:
    int v;
    int e;
    node** adj;

    graph(int V, int E) 
    {
        v = V;
        e = E;
        adj = new node*[v];
        for (int i = 0; i < v; i++)
        adj[i] = NULL;
    }
};
void insert(node** s, int val) 
{
    node* temp = new node(val);
    if (*s == NULL)
    *s = temp;
    else 
    {
        node* t = *s;
        while (t->next != NULL)
        t = t->next;
        t->next = temp;
    }
}
void view(node** s) 
{
    node* t = *s;
    while (t != NULL) 
    {
        cout<<t->vertex<<" ";
        t = t->next;
    }
}
void adjlist(graph* g) 
{
    int u, v;
    cout<<"Enter edges:"<<endl;
    for (int i = 0; i < g->e; i++) 
    {
        cin>>u>>v;
        insert(&(g->adj[u]), v);
        insert(&(g->adj[v]), u);
    }
    cout<<"Adjacency list:"<<endl;
    for (int i = 0; i < g->v; i++) 
    {
        cout<<i<<"->";
        view(&(g->adj[i]));
        cout<<endl;
    }
}

void BFS(graph* g, int s) 
{
    for (int u = 0; u < g->v; u++) 
    {
        g->adj[u]->color = 0;
        g->adj[u]->distance = -1;
        g->adj[u]->parent = -1;
    }

    g->adj[s]->color = 1;
    g->adj[s]->distance = 0;
    g->adj[s]->parent = -1;

    enque1(s);

    while (f1 != -1 && r1 != -1) 
    {
        int u = deque1();
        cout<<u<<" ";

        node* temp = g->adj[u];
        while (temp != NULL) 
        {
            int v = temp->vertex;
            if (g->adj[v]->color == 0) 
            {
                g->adj[v]->parent = u;
                g->adj[v]->distance = g->adj[u]->distance + 1;
                g->adj[v]->color = 1;
                enque1(v);
            }
            temp = temp->next;
        }
        g->adj[u]->color = 2;
    }
}

void dfs_visit(graph* g, int u, int &time) 
{
    time++;
    g->adj[u]->ditime = time;
    g->adj[u]->color = 1;

    node* temp = g->adj[u];
    while (temp != NULL) 
    {
        int v = temp->vertex;
        if (g->adj[v]->color == 0) 
        {
            g->adj[v]->parent = u;
            dfs_visit(g, v, time);
        }
        temp = temp->next;
    }

    time++;
    g->adj[u]->fintime = time;
    g->adj[u]->color = 2;
    cout << u << " ";
}


void dfs(graph* g) 
{
    int time = 0;

    for (int u = 0; u < g->v; u++) 
    {
        g->adj[u]->color = 0;
        g->adj[u]->parent = -1;
    }

    for (int u = 0; u < g->v; u++) 
    {
        if (g->adj[u]->color == 0)
        dfs_visit(g, u, time);
    }
}

int main() 
{   
    int a;
    int V, E;
    cout<<"Enter the total number of vertices: ";
    cin>>V;
    cout<<"Enter the total number of edges: ";
    cin>>E;
    graph* g = new graph(V, E);
    do
    {
        cout << "Press 1: Create Graph and Adjacnecy list" << endl;
        cout << "Press 2: BFS" << endl;
        cout << "Press 3: DFS" << endl;
        cout << "Press 4: Exit" << endl;
        cout << "Enter key: ";
        cin >> a;
        switch (a)
        {
        case 1:
            adjlist(g);
            break;
        case 2:
            int root;
            cout<<"Enter the vertex you want to start:";
            cin>>root;
            BFS(g, root);
            break;
        case 3:
            dfs(g);
            cout<<"dfs Information:"<<endl;
            for (int i = 0; i < g->v; i++) 
            {
                cout<<"Vertex "<<i<<": ";
                cout<<"Parent: "<<g->adj[i]->parent<<" ";
                cout<<"Discovery Time: "<<g->adj[i]->ditime<<" ";
                cout<<"Finish Time: "<<g->adj[i]->fintime<<endl;
            }
            break;
        case 4:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (a != 4);
    return 0;
}
