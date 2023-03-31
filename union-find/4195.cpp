#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>
using namespace std;

int T, F, idx, _first, _second;
string first, second;
map<string, int> names;                                     // map 선언문
vector<int> p, cnt;
int getKey(string n) {
    if (names.find(n) == names.end()) {                     // map에 존재하는 key인지 확인하는 방법: find 결과가 end와 같으면 없는 것
        names.insert(pair<string, int>(n, idx));            // map insert(pair<string, int>(n, idx))
        p.push_back(idx);
        cnt.push_back(1);
        return idx++;
    } else return names[n];
}
int findF(int a) {
    if (p[a] == a) return a;
    p[a] = findF(p[a]);
    return p[a];
}
void unionF(int a, int b) {
    int s = a < b? a : b;
    int l = b < a? a : b;
    s = findF(s);
    l = findF(l);
    if (p[s] != l) {
        p[s] = l;
        cnt[l] += cnt[s];
    }
}
int main() {
    char *temp1 = (char*)malloc(sizeof(char)*21);
    char *temp2 = (char*)malloc(sizeof(char)*21);
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d", &F);
        p.clear();
        cnt.clear();
        names.clear();
        idx = 0;
        for (int f = 0; f < F; f++) {
            scanf("%s %s", temp1, temp2);
            first = temp1;
            second = temp2;
            _first = getKey(first);
            _second = getKey(second);
            unionF(_first, _second);
            printf("%d\n", cnt[findF(_second < _first? _first:_second)]);
        }
    }
    return 0;
}