import sys

PIN, EMPTY = 'o', '.'
board, move_count = None, None

m = [[1, 0], [-1, 0], [0, 1], [0, -1]]
def within_board(r, c):
    return 0 <= r and r < 5 and 0 <= c and c < 9
def move(r, c, moves):
    global board, move_count    
    if move_count < moves:
        move_count = moves
                
    for mr, mc in m:
        nr, nc = r + mr, c + mc
        nnr, nnc = nr + mr, nc + mc
        
        if within_board(nr, nc) and board[nr][nc] == PIN and within_board(nnr, nnc) and board[nnr][nnc] == EMPTY:    
            board[r][c] = EMPTY
            board[nr][nc] = EMPTY
            board[nnr][nnc] = PIN
            
            for x in range(5):
                for y in range(9):
                    if board[x][y] == PIN:
                        move(x, y, moves + 1) # nnr, nnc에서 호출 보장
            
            board[r][c] = PIN
            board[nr][nc] = PIN
            board[nnr][nnc] = EMPTY

N = int(sys.stdin.readline())
for t in range(N):    
    board, total = [], 0
    for r in range(5):
        board.append(list(sys.stdin.readline().strip()))
        if PIN in board[r]:
            total += board[r].count(PIN)
    
    min_pins, move_count = total, 0
    for r in range(5):
        for c in range(9):
            if board[r][c] == PIN:
                move(r, c, 0)
    print(total - move_count, move_count)
    
    if t != N - 1:
        sys.stdin.readline()