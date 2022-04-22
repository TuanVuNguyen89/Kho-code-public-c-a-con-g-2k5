def solve():
    x, l, n = map(int, input().split())

    min_erased = -1
    max_erased = x
    while max_erased - min_erased > 1:
        erased = (min_erased + max_erased) // 2

        cur_x = x - erased
        good = True
        for it in range(n):
            if cur_x > l:
                good = False
                break
            cur_x *= 2

        if good:
            max_erased = erased
        else:
            min_erased = erased

    print(max_erased)


def main():
    t = int(input())
    for i in range(t):
        solve()


main()
