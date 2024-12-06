from collections import deque
from typing import List

class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        red = deque()
        visited = set()
        
        # Add deadends to the visited set
        for d in deadends:
            visited.add(d)
            
        # Check if starting point is in deadends
        if "0000" in visited:
            return -1
        
        # Initialize the queue and visited set
        red.append("0000")
        visited.add("0000")
        
        steps = 0
        
        while red:
            length = len(red)
            for _ in range(length):
                current = red.popleft()
                if current == target:
                    return steps
                
                # Explore neighbors by incrementing and decrementing each wheel
                for i in range(4):
                    # Increment wheel
                    inc = (int(current[i]) + 1) % 10
                    currInc = current[:i] + str(inc) + current[i+1:]
                    
                    # Decrement wheel
                    dec = (int(current[i]) - 1 + 10) % 10
                    currDec = current[:i] + str(dec) + current[i+1:]
                    
                    # Add new states to the queue if not visited
                    if currInc not in visited:
                        visited.add(currInc)
                        red.append(currInc)
                    if currDec not in visited:
                        visited.add(currDec)
                        red.append(currDec)
                
            steps += 1
            
        return -1
