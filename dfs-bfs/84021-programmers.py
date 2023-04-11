from collections import deque

def solution(game_board, table):
    N = len(game_board)
    
    m = [[0, 1], [0, -1], [1, 0], [-1, 0]]
    def search_shape(board, x, y, valid):
        shape = [[0, 0]]
        board[x][y] = -1
        Q = deque([[x, y, 0, 0]])
        while Q:
            r, c, mx, my = Q.popleft()
            for mr, mc in m:
                nr, nc = r + mr, c + mc
                
                is_out_of_bound = nr < 0 or N <= nr or nc < 0 or N <= nc
                if is_out_of_bound or board[nr][nc] != valid:
                    continue
                
                board[nr][nc] = -1
                offset_r, offset_c = mx + mr, my + mc
                Q.append([nr, nc, offset_r, offset_c])
                shape.append([offset_r, offset_c])
        return shape

    def process_shape(shape):
        min_x, max_x, min_y, max_y = 100, -100, 100, -100
        for x, y in shape:
            min_x = min(min_x, x)
            max_x = max(max_x, x)
            min_y = min(min_y, y)
            max_y = max(max_y, y)
        puzzle = [[0 for _ in range(min_y, max_y + 1)] for _ in range(min_x, max_x + 1)]
        sx, sy = max(0, -1 * min_x), max(0, -1 * min_y)
        for x, y in shape:
            puzzle[sx + x][sy + y] = 1
        return puzzle
    
    puzzles = []
    for r in range(N):
        for c in range(N):
            if table[r][c] == 1:
                puzzle_shape = search_shape(table, r, c, 1)
                puzzle = process_shape(puzzle_shape)
                puzzles.append(puzzle)
    
    def rotate(puzzle):
        return [list(row) for row in zip(*puzzle[::-1])] # spread > reverse > zip
    
    def match(r, c):
        shape = search_shape(game_board, r, c, 0)
        if len(shape) <= 6:
            empty_area = process_shape(shape)
            for p in puzzles:
                puzzle, r_count = [row[:] for row in p], 0
                while True:
                    if puzzle == empty_area:
                        puzzles.remove(p)
                        return len(shape)
                    if r_count == 3:
                        break
                    puzzle = rotate(puzzle)
                    r_count += 1
        return 0
    
    answer = 0
    for r in range(N):
        for c in range(N):
            if game_board[r][c] == 0:
                answer += match(r, c)
    return answer