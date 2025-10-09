import itertools
def correctness(board):
    n = len(board)
    for i in range(n):
        for j in range(i + 1, n):
            if board[i] == board[j] or abs(board[i] - board[j]) == j - i:
                return False
    return True
def total_options(n):
    count = 0
    for a in itertools.permutations(range(n)):
        if correctness(a):
            count += 1
    return count
n=int(input())
print(total_options(n))
