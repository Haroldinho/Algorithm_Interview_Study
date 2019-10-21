from collections import deque
class Solution:
    def numSquares(self, n: int) -> int:
        visited_nodes = set()
        my_queue = deque()
        my_queue.append((n,0))
        print(n,0)
        print(my_queue)
        list_perfect_squares = [i*i for  i in range(1,int(n/2) + 2) if i*i <= n]
        while len(my_queue)>0:
            curr_node, depth = my_queue.popleft()
            print(curr_node, depth)
            if curr_node == 0:
                return depth
            depth +=1
            for num in list_perfect_squares:
                if num> curr_node:
                    break
                new_node_val = curr_node - num
                if new_node_val in visited_nodes:
                    continue
                visited_nodes.add(new_node_val)
                my_queue.append((new_node_val, depth))
                print("\t add {}, {}".format(new_node_val, depth))
        print("Error in the code")
        return -1

def main():
    n = 1
    solution_instance = Solution()
    print(" Returned {} steps with numSquares.".format(solution_instance.numSquares(n)))


if __name__ == "__main__":
    main()
