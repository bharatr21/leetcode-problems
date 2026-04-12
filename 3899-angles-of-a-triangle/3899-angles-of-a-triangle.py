def exists(sides):
    x, y, z = sides[0], sides[1], sides[2]
    return x + y > z and y + z > x and x + z > y and abs(x - y) < z and abs(y - z) < x and abs(x - z) < y
class Solution:
    def internalAngles(self, sides: list[int]) -> list[float]:
        if not exists(sides): 
            return []
        else:
            a, b, c = sides
            conv = 180 / math.pi
            A = math.acos((b**2 + c**2 - a**2) / (2 * b * c))
            B = math.acos((a**2 + c**2 - b**2) / (2 * a * c))
            C = math.acos((a**2 + b**2 - c**2) / (2 * a * b))
            A, B, C = A * conv, B * conv, C * conv 
            return sorted([A, B, C])
