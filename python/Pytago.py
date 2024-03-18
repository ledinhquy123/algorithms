if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))
    for i in range(n):
        a[i] = a[i] ** 2
    a.sort()
    for i in range(n - 1, 1, -1):
        c = a[i]
        l, r = 0, i - 1
        while(l < r):
            sum = a[l] + a[r]
            if(sum < c): l += 1
            elif(sum > c): r -= 1
            else: 
                print('YES')
                exit(0)
    print('NO')
        