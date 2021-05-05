#include <bits/stdc++.h>
using namespace std;

int AdjMatrix[105][105], visited[105], n;
int Dominator[105][105];

void dfs(int node, int st) {
    if(node == st){    
        return;
    }
    
    int i;
    visited[node] = 1;
    
    for(i = 0; i < n; i++) {
        if(AdjMatrix[node][i] && !visited[i]) {
            dfs(i, st);
        }
    }
}

int main() {
    int t, i, j, k;
    int cases = 0;
    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);

        // Storing in Adjecency Matrix
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                scanf("%d", &AdjMatrix[i][j]);
            }
        }

        int New_visited[105] = {0};
        for(i = 0; i < n; i++){
            visited[i] = 0;
        }

        dfs(0, -1);
        
        for(i = 0; i < n; i++){
            New_visited[i] = visited[i];
        }

        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++){
                visited[j] = 0;
            }

            dfs(0, i);

            for(j = 0; j < n; j++){
                if(New_visited[j] && !visited[j])
                    Dominator[i][j] = 1;
                else
                    Dominator[i][j] = 0;
            }

            Dominator[i][i] = New_visited[i];
        }

        printf("Case %d:\n", ++cases);
        
        putchar('+');
        for(i = -n+1; i < n; i++){
            putchar('-');
        }
        puts("+");

        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                putchar('|');
                putchar(Dominator[i][j] ? 'Y' : 'N');
            }
            puts("|");
            putchar('+');
            for(j = -n+1; j < n; j++){
                putchar('-');
            }
            puts("+");
        }
    }
    return 0;
}