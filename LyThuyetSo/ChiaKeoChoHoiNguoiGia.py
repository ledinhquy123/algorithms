# Chia keo cho hoi ngoi gia
N = (int)(1e6 + 1)
mod = (int)(1e9 + 7)
arr = [0] * N
def CachSapXep():
    arr[0] = 1
    arr[1] = 0
    for i in range(2, N):
        arr[i] = (i - 1) * (arr[i - 1] + arr[i - 2])
        arr[i] %= mod

if __name__ == '__main__':
    n = int(input())
    CachSapXep()
    print(arr[n])