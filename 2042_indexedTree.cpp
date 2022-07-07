#include <cstdio>
#include <cstdlib>
long long N, M, K, S, a, b, c;
long long nums[1000001], tree[2000001];

long long makeTree(long long node, long long left, long long right) {
    if (left == right) {
        // leaf node에  도달했을 때 해당 index가
        if (left <= N) {
            return tree[node] = nums[left-1];
        } else {
            return tree[node] = 0;
        }
    }
    // 아직 leaf 아니라면 tree[node] += children 값
    long long mid = (left+right) / 2;
    tree[node] = makeTree(node*2, left, mid);
    tree[node] += makeTree(node*2+1, mid+1, right);
    return tree[node];
}
long long query(long long node, long long left, long long right, long long qleft, long long qright) {
    // 1. 쿼리 밖, 상관없는 값을 return
    if (qright < left || right < qleft) return 0;
    // 2. 쿼리에 속함
    else if (qleft <= left && right <= qright)
        return tree[node];
    // 3. 쿼리에 걸침: children에 쿼리 넘김
    else {
        long long mid = (left+right)/2;
        return query(node*2, left, mid, qleft, qright)
                + query(node*2+1, mid+1, right, qleft, qright);
    }
}
void update(long long index, long long value) {
    // 해당 노드가 변화한 노드를 포함하면 tree[node] update
    index += S-1;
    tree[index] = value;    // leaf node update한 뒤
    // 부모의 값을 계속해서 갱신
    index /= 2;
    while (index >= 1) {
        tree[index] = tree[index*2]+tree[index*2+1];
        index /= 2;
    }
}
int main() {
    scanf("%lld %lld %lld", &N, &M, &K);
    for (int i=0; i < N; i++) scanf("%lld", &nums[i]);

    S = 1;    // indexed tree의 중간 index: S부터가 leaf, 기존 array 시작
    while(S < N) S *= 2;
    makeTree(1, 1, S);
    
    for (int i=0; i<M+K; i++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a == 1) update(b, c);
        if (a == 2) printf("%lld\n", query(1, 1, S, b, c));
    }
    return 0;
}