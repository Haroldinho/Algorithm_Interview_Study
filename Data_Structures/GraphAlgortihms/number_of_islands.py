import queue


class Solution:
    def __init__(self):
        self._max_col = 0
        self._max_row = 0
        self._horizontal_moves = [-1, 0, 0, 1]
        self._vertical_moves = [0, -1, 1, 0]

    def isValid(self, row, col):
        if (0 <= row < self._max_row) and (0 <= col < self._max_col):
            return True
        else:
            return False

    def numIslands(self, grid) -> int:
        if not grid:
            return 0
        num_islands = 0
        # 1. Initialize a matrix of visited land locations to zeros
        visited_matrix = [[0 for i in grid[l]] for l in range(len(grid))]
        # 3. For each node of the matrix
        self._max_row = len(grid)
        self._max_col = len(grid[0])
        for row in range(len(grid)):
            for col in range(len(grid[row])):
                # 4.  See if the node has been visited
                # 5.  If not, run BFS on the matrix and increment the number of islands
                exists = int(grid[row][col]) == 1
                not_visited = visited_matrix[row][col] == 0
                if exists and not_visited:
                    visited_matrix = self.bfs(row, col, visited_matrix, grid)
                    num_islands += 1
        return num_islands

    # 0. Create an empty queue
    # 1. Mark current cell as visited
    # 2. For each neighbor of my current cell
    # 3. If the cell is valid and if the cell has not been visited
    # 4. add it to the queue
    # 5 once I have visited all the neighbor, remove the first element of the queue
    # 6. Go to the next element of the queue and do hte same thing
    def bfs(self, a_row, a_col, visited_matrix, a_grid):
        # print("Entered bfs", a_row, a_col)
        my_queue = queue.Queue()
        my_queue.put((a_row, a_col))
        while not my_queue.empty():
            row, col = my_queue.get()
            visited_matrix[row][col] = 1
            for adj_idx in range(len(self._horizontal_moves)):
                adj_row = row + self._vertical_moves[adj_idx]
                adj_col = col + self._horizontal_moves[adj_idx]
                if self.isValid(adj_row, adj_col):
                    if (visited_matrix[adj_row][adj_col] == 0) and (int(a_grid[adj_row][adj_col]) == 1):
                        visited_matrix[adj_row][adj_col] = 1
                        my_queue.put((adj_row, adj_col))
        return visited_matrix

