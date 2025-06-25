#!/usr/bin/env python3

import math

class Vector:
    def __init__(self, x=0, y=0):                   # constructor 
        self.x = x
        self.y = y

    def __repr__(self):                             # string representation for inspection
        return f'Vector({self.x!r}, {self.y!r})'    # !r means we get Vector(1,2) instead of Vector('1','2')

    def __abs__(self):                              # absolute value
        return math.hypot(self.x, self.y)

    def __bool__(self):                             # boolean
        return bool(abs(self))

    def __add__(self, other):                       # + operator
        x = self.x + other.x
        y = self.y + other.y
        return Vector(x, y)

    def __mul__(self, scalar):                      # * operator
        return Vector(self.x * scalar, self.y * scalar)
