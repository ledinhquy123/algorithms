class Matrix:
    def __init__ (seft, n, m):
        seft.__n = n
        seft.__m = m
        seft.arr = [[0 for _ in range(seft.__m)] for _ in range(seft.__n)]
    def mul(seft, another):
        c = Matrix(seft.__n, another.__m)
        c.arr = [[0 for _ in range(another.__m)] for _ in range(seft.__n)]
        for i in range(seft.__n):
            for j in range(another.__m):
                c.arr[i][j] = 0
                for k in range(seft.__m):
                    c.arr[i][j] += seft.arr[i][k] * another.arr[k][j]
        return c
    def __str__ (seft):
        ans = ""
        for i in range(seft.__n):
            for j in range(seft.__m):
                ans += str(seft.arr[i][j]) + " "
            ans += '\n'
        return ans

if __name__ == '__main__':
    n, m, p = map(int, input().split())
    mt1 = Matrix(n, m)
    mt2 = Matrix(m, p)
    for i in range(n):
        mt1.arr[i] = list(map(int, input().split()))
    for i in range(m):
        mt2.arr[i] = list(map(int, input().split()))
    print(mt1.mul(mt2))