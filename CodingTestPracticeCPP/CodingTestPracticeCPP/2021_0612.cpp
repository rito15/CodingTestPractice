/*
 * https://programmers.co.kr/learn/courses/30/lessons/49189?language=cpp
 * 
 * [GRAPH] - 가장 먼 노드
 * 
 * 
 */


#include "common.h"

struct Vertex
{
public:
    vector<int> adjacents; // 인접 버텍스
    int dist = 999999; // 최단거리
    bool visited = false;

    Vertex() {}

    void AddEdge(int index)
    {
        this->adjacents.push_back(index);
    }
};

int solution_2021_0612(int n, vector<vector<int>> edge)
{
    int len = n + 1;
    int answer = 0;
    Vertex* vertices = new Vertex[len];
    queue<int> travelQueue;

    // Generate Vertices Array
    for (int i = 0; i < edge.size(); i++)
    {
        int from = edge[i][0];
        int to = edge[i][1];
        vertices[from].AddEdge(to);
        vertices[to].AddEdge(from);
    }

    vertices[1].dist = 1;
    vertices[1].visited = true;
    travelQueue.push(1);

    int maxDist = -1;

    // Travel
    while (!travelQueue.empty())
    {
        int current = travelQueue.front();
        travelQueue.pop();

        for (int i = 0; i < vertices[current].adjacents.size(); i++)
        {
            int next = vertices[current].adjacents[i];
            if (!vertices[next].visited)
            {
                vertices[next].visited = true;

                travelQueue.push(next);
                vertices[next].dist = vertices[current].dist + 1;
            }
        }

        if(vertices[current].dist > maxDist)
            maxDist = vertices[current].dist;
    }

    for (int i = 1; i < len; i++)
    {
        if(vertices[i].dist == maxDist)
            answer++;
    }

    // Print Graph
    for (int i = 1; i < len; i++)
    {
        cout << "[" << i << "] -";
        for (int j = 0; j < vertices[i].adjacents.size(); j++)
        {
            cout << " " << vertices[i].adjacents[j];
        }
        cout << endl;
    }

    // Print Dists
    cout << endl << "=== Distances ===" << endl;
    for (int i = 1; i < len; i++)
    {
        cout << "[" << i << "] " << vertices[i].dist << endl;
    }

    delete[] vertices;

    cout << "Max Dist : " << maxDist << endl;
    cout << "Answer : " << answer << endl;

    return answer;
}