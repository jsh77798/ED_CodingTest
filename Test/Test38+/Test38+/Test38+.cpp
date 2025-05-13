
#include <algorithm>
#include <vector>
using namespace std;

vector<int> adj[1000002];
vector<int> adjVertex[1000002];
vector<int> answer;
int vis[1000002];

int vertex = 0;
int edge = 0;
//DFS
void dfs(int cur)
{
    vis[cur] = 1;
    vertex++;

    for (int nxt : adj[cur])
    {
        edge++;
        if (vis[nxt])
            continue;
        dfs(nxt);
    }
}

vector<int> solution(vector<vector<int>> edges)
{
    for (int i = 0; i < edges.size(); ++i)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    int maxVertex = 0;

    for (int i = 0; i < edges.size(); ++i)
    {
        //가장 큰 vertex 찾기
        if (maxVertex < edges[i][0])
            maxVertex = edges[i][0];
        if (maxVertex < edges[i][1])
            maxVertex = edges[i][1];

        adjVertex[edges[i][0]].push_back(edges[i][1]);
    }

    vector<pair<int, int>> cnt(maxVertex + 1);

    for (int i = 0; i < edges.size(); ++i)
    {
        cnt[edges[i][0]].first++;
        cnt[edges[i][1]].second++;
    }
    int centerVertex = 0;
    int maxedge = 0;
    for (int i = 1; i <= maxVertex; ++i)
    {
        if (cnt[i].first != 0 && cnt[i].second == 0) //나가기만 한것
        {
            if (maxedge < cnt[i].first)
            {
                maxedge = cnt[i].first;
                centerVertex = i;
            }
        }
    }

    int adjVertexSize = adjVertex[centerVertex].size();
    int dounut = 0;
    int mak = 0;
    int eight = 0;

    for (int i = 0; i < adjVertexSize; ++i)
    {
        int adjVertex = adj[centerVertex][i];

        //fill(vis, vis + 1000002, 0);
        fill(vis, vis + maxVertex + 1, 0);
        vertex = 0; //정점
        edge = 0; //엣지
        dfs(adjVertex);

        if (edge == vertex + 1)
            eight++;
        else if (edge == vertex - 1)
            mak++;
        else if (edge == vertex)
            dounut++;
    }
    answer.push_back(centerVertex);
    answer.push_back(dounut);
    answer.push_back(mak);
    answer.push_back(eight);
    return answer;
}

int main()
{
    //[[1, 1], [2, 1], [2, 3], [3, 4], [5, 3]]
    //    기댓값 〉[2, 1, 1, 0]
    //vector<vector<int>> _edges = { { 2, 3 }, { 4, 3 }, { 1, 1 }, { 2, 1 } };
    vector<vector<int>> _edges = { {4, 11} ,{1, 12},{8, 3},{12, 7},{4, 2},{7, 11},{4, 8},{9, 6},{10, 11},{6, 10},{3, 5},{11, 1},{5, 3},{11, 9},{3, 8} };
    solution(_edges);

}

