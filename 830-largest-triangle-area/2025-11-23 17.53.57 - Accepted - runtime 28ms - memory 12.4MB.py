class Solution(object):
    def largestTriangleArea(self, points):
        n = len(points)
        ans = 0.0
        pts = points  

        for i in range(n):
            x1, y1 = pts[i]
            for j in range(i + 1, n):
                x2, y2 = pts[j]
                for k in range(j + 1, n):
                    x3, y3 = pts[k]

                    area = abs(
                        x1 * (y2 - y3) +
                        x2 * (y3 - y1) +
                        x3 * (y1 - y2)
                    )

                    if area > ans:
                        ans = area

        return ans / 2.0
