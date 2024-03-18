if __name__ == '__main__' : 
    n = int(input())
    cnt = 0
    for i in range(1, n + 1) : 
        for j in range(1, n + 1) : 
            cnt += 1
            print(cnt, end = ' ')
        print(end = '\n')
    print(end = '\n')

    cnt = -1
    for i in range(1, n + 1) : 
        cnt += 1
        for j in range(1, n + 1) : 
            print(j + cnt, end = ' ')
        print(end = '\n')
    print(end = '\n')

    for i in range(1, n + 1) : 
        for j in range(1, n + 1) : 
            if j >= n - i + 1 : print(i, end = '')
            else : print('~', end = '')
        print(end = '\n')
    print(end = '\n')

    cnt = 0
    for i in range(1, n + 1) : 
        cnt = i
        dem = n - 1
        for j in range(1, n + 1) : 
            if j == 1 : print(cnt , end = ' ')
            elif j <= i : 
                print(cnt + dem, end = ' ')
                cnt += dem
                dem -= 1
            else : print(' ', end = ' ')
        print(end = '\n')
    