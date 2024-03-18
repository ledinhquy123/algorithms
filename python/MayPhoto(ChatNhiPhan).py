def check(n, x, y, time):
    temp = time // x + time // y
    return temp >= (n - 1)

if __name__ == '__main__':
    n, x, y = map(int, input().split())
    left, right = 1, min(x, y) * n
    ans = 0
    while(left <= right):
        m = (left + right) // 2
        if(check(n, x, y, m)):
            ans = m + min(x, y) # photo ra 1 ban truoc sau do tu ban goc va ban nay moi photo ra n ban
            right = m - 1
        else: left = m + 1
    print(ans)
