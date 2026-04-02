class Solution:
    def countPoints(self, points, queries):
        result = []
        
        for cx, cy, r in queries:
            count = 0
            r2 = r * r  # precompute
            
            for px, py in points:
                dx = px - cx
                dy = py - cy
                
                if dx * dx + dy * dy <= r2:
                    count += 1
            
            result.append(count)
        
        return result