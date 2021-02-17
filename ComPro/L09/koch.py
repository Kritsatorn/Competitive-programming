# Draw a Koch snowflake

from turtle import *

def koch(a, order):
    if order > 0:
        for t in [60, -120, 60, 0]:
            forward(a/3)
            left(t)
    else:
        forward(a)

# Test
#koch(100, 0)
##pensize(3)
#koch(100, 1)

# Choose colours and size
color("sky blue", "white")
bgcolor("black")
size = 400
order = 0

# Ensure snowflake is centred
penup()
backward(size/1.732)
left(30)
pendown()

# Make it fast
tracer(100)
hideturtle()

begin_fill()

# Three Koch curves
for i in range(3):
    koch(size, order)
    right(120)

end_fill()

# Make the last parts appear
update()
n = input('')