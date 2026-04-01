class Solution:
    def survivedRobotsHealths(self, positions, healths, directions):
        robots = sorted(zip(positions, healths, directions, range(len(positions))))
        
        stack = []
        
        for pos, h, d, idx in robots:
            if d == 'R':
                stack.append([h, idx])
            else:
                while stack and h > 0:
                    if stack[-1][0] < h:
                        h -= 1
                        stack.pop()
                    elif stack[-1][0] > h:
                        stack[-1][0] -= 1
                        h = 0
                    else:
                        stack.pop()
                        h = 0
                
                if h > 0:
                    stack.append([h, idx])
        
        stack.sort(key=lambda x: x[1])
        return [h for h, _ in stack]