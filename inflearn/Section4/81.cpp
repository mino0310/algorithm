#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// 음의 사이클이 없는 한 일차원 배열로 선언해도 답을 도출해내는 것엔 지장이 없다.
int dist[101];
// 간선의 정보를 담아둘 구조체
struct Edge {
    int s;
    int e;
    int val;
    // 간선의 정보를 저장할 생성자
    Edge(int a, int b, int c) {
        s = a;
        e = b;
        val = c;
    }
};

int main(void)
{
    int i, n, m, a, b, c, j, s, e;
    vector<Edge> Ed;
    cin >> n >> m;
    // 입력되는 그래프의 정보를 구조체 벡터를 사용해서 저장한다.
    for (i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        Ed.push_back(Edge(a, b, c)); // 굳이 정렬할 필요도 없고, 인접리스트로 받아야할 이유도 없다.그냥 간선의 정보를 하나씩 적용해버리면 된다.
    }
    // 출력할 배열을 일단 가장 큰 값으로 초기화를 해놓는다. 무한대라고 보면 된다.
    for (i = 1; i <= n; i++) {
        dist[i] = 2147483647;
    }
    // 출발 정점과 도착 정점을 입력 받는다.
    cin >> s >> e;
    // 출발 정점의 경우 0으로 초기화를 해둔다.
    dist[s] = 0;
    // n - 1번까지 간선을 선택하면서 해당 지점에서의 값을 기존 값과 비교하며 최소값을 저장.
    for (i = 1; i < n; i++) // i가 1일때 부터 시작해서 n-1번까지 반복하게 됨. 간선을 1개만 고르고, 2개 고르고, 3개고르고 ,, n-1개까지 고르는 과정이라고 생각하면 된다.
    {
        // 모든 간선을 돌며 해당 정점까지의 최소 비용을 구한다.
        for (j = 0; j < Ed.size(); j++)
        {
            int u = Ed[j].s; // 해당 간선의 시작점을 저장한다.
            int v = Ed[j].e; // 해당 간선의 종료점을 저장한다.
            int w = Ed[j].val; // 해당 간선의 가중치를 저장한다.
            // 시작점까지 최소값이 무한대값이 아니고 
            // 시작점까지의 최소값에 현재 선택한 간선의 가중치값을 더한 것이 현재 선택한 간선의 
            // 종료점까지의 최소비용보다 작은 경우에만 아래의 논리를 적용한다.
            // why? 시작지점까지의 최소비용이 무한대란 말은 그 지점까지 가닿을 수 없단 말이니까 더이상 할 필요 없음
            // 시작 지점까지의 최소비용에 가중치를 더한 건 무슨 말이냐 ? 현재 간선을 선택하기 바로 직전까지의 최소비용이란 말이다
            // 그러니 지금까지의 최소비용에 현재 선택한 간선의 가중치를 더한 것이 간선의 종료지점까지의 최소비용을 비교해야 한다.
            // 간선의 시작점까지 최소비용에 현재 선택한 간선의 가중치를 더한 게 간선의 종료지점까지 이미 구해진 최소비용 값보다 크다는 건 최소비용이 될 수 없다는 것을 말한다.
            // 요약하면 기존에 e(종료지점)로 가는 최소비용이 있었는데 u를 통해서 현재 간선의 값을 더해 v로 가는 값을 비교하라는 것.
            if (dist[u] != 2147483647 && dist[u]+ w < dist[e]){
                dist[v] = dist[u] + w; // 간선의 종료지점까지의 최소비용을 지금까지의 최소비용 + 현재 선택한 간선의 가중치를 더한 값으로 바꿔준다.
            }
        }
    }
    // 지금까지 n - 1 번 반복을 했고 다음에 이어지는 반복문은 n 번째의 반복이다.
    // 즉 n-1까지 해야하는 데 간선의 개수가 N개로 된  것이 있는지 체크하는 것이다.
    // 음의 사이클 체크하는 것.
    for (j = 0; j < Ed.size(); j++)
    {
        int u = Ed[j].s;
        int v = Ed[j].e;
        int w = Ed[j].val;
        if (dist[u] != 2147483647 && dist[u] + w < dist[v]){
            cout << "-1\n";
            exit(0);
        }
    }
    // 종료 지점까지의 최소 간선 비용을 출력한다. 
    cout << dist[e] << endl;
    return 0;
}