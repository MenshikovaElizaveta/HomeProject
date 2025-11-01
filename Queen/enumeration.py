from itertools import permutations
def correctness(board):
    n = len(board)
    for i in range(n-1):
        for j in range(i + 1, n):
            if abs(board[i] - board[j]) == j - i:
                return False
    return True
def total_options(n):
    count = 0
    for a in permutations(range(n)):
        if correctness(a):
            count += 1
    return count
n=int(input())
print(total_options(n))
