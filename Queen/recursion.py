def queens_minimal(n):
    def f(r, p):
        if r == n: return 1
        t = 0
        for c in range(n):
            if all(p[i] != c and abs(p[i] - c) != r - i for i in range(r)):
                p[r] = c
                t += f(r + 1, p)
        return t
    return f(0, [0]*n)
n=int(input())
print(queens_minimal(n))
