class Point(object):
    _slots__ = ['x', 'y', 'z']

    def __init__(self, x=0, y=0, z=None):
        self.x = x
        self.y = y
        self.z = z

def area(p1, p2, p3):
    # we calcute the absolute of the cross_product ((b - a) x (c - a) / 2)
    return abs((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2)

def pointInTriangle(p, a, b, c):
    # if the point is inside the triangle then the area of the triangle is the same
    # as the sum of the areas of the three triangles created from the four points
    return area(a, b, c) == area(p, b, c) + area(a, p, c) + area(a, b, p)
    
def main():
    cnt = 0
    for i in range(1000):
        ax, ay, bx, by, cx, cy = [int(c) for c in input().split(",")]
        o = Point(0, 0)
        a = Point(ax, ay)
        b = Point(bx, by)
        c = Point(cx, cy)
        cnt += pointInTriangle(o, a, b, c)
    print (cnt)

if __name__ == "__main__":
    main()
