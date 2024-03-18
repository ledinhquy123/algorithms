if __name__ == '__main__':
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    cnt = 0
    i, j = 0, n - 1
    while(i < j):
        if(a[i] + a[j] <= x):
            cnt += 1
            i += 1
            j -= 1
        else:
            j -= 1
            cnt += 1
    if(i == j): cnt += 1
    print(cnt)