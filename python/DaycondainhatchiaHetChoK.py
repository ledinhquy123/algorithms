if __name__ == '__main__':
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    s = 0
    mp = dict({})
    ans = -1
    for i in range(n):
        s += a[i]
        s = (s % k + k) % k
        if(s == 0):
           ans = max(ans, i + 1)
        if(s in mp):
            ans = max(ans, i - mp[s])
        if(s not in mp):
            mp[s] = i
    print(ans)  