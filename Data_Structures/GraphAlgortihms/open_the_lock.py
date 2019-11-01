from collections import deque


class Solution:
    def __init__(self):
        self._moves = [(0, 1), (0, -1), (1, 1), (1, -1), (2, 1), (2, -1), (3, 1), (3, -1)]
        self._visited_nodes = set()
        self._deadends = set()
        self._target = "0000"
        self._my_queue = deque()

    def move_elt(self, node_str, move_pair):
        # node_str = list(node_str)
        # node_str[move_pair[0]] = "{}".format((int(node_str[move_pair[0]]) + move_pair[1]) % 10)
        return node_str[:move_pair[0]] + str((int(node_str[move_pair[0]]) + move_pair[1]) % 10) + node_str[
                                                                                                  move_pair[0] + 1:]

    def convert_to_string(self, num):
        return "{0:04d}".format(num)

    def openLock(self, deadends: List[str], target: str) -> int:
        if (self._target in deadends) or (target in deadends):
            return -1
        self._my_queue.append((target, 0))
        self._visited_nodes.add(target)
        self._deadends = set(deadends)
        num_moves = 0
        return self.bfs()

    def bfs(self) -> int:
        while not (len(self._my_queue) == 0):
            # get element in the queue
            root_node, depth = self._my_queue.popleft()
            depth = depth + 1
            # look at all neighbors that are not
            for move in self._moves:
                new_node = self.move_elt(root_node, move)
                if (new_node in self._visited_nodes) or (new_node in self._deadends):
                    continue
                if new_node == self._target:
                    return depth
                # print(new_node, depth)
                self._my_queue.append((new_node, depth))
                self._visited_nodes.add(new_node)
        else:
            return -1