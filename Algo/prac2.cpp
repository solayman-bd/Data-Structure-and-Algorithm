#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

void print(int x) {
    cout << x << endl;
}

long sizeOfvalue(long a) {
    long c = 0;
    while (a > 0) {
        a /= 10;
        c++;
    }
    return c;
}

vector<long> numbers(long x) {
    vector<long> result;
    while (x > 0) {
        result.push_back(x % 10);
        x /= 10;
    }
    return result;
}

void bfs(long x, long length) {
    queue<long> q;
    q.push(x);
    unordered_set<long> visited;
    int operation = 0;
    visited.insert(x);

    while (!q.empty()) {
        int size = q.size();
        while (size-- > 0) {
            long value = q.front();
            q.pop();
            vector<long> li = numbers(value);

            if (sizeOfvalue(value) == length) {
                print(operation);
                return;
            }

            for (long mul : li) {
                if (!visited.count(value * mul) && sizeOfvalue(value * mul) <= length) {
                    visited.insert(value * mul);
                    q.push(mul * value);
                }
            }
        }
        operation++;
    }

    print(-1);
}

int main() {
    long n, x;
    cin >> n >> x;
    bfs(x, n);
    return 0;
}
