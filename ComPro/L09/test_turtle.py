def koch(n):
    if n==0:
        return 'F'
    a=koch(n-1)
    return a+'L'+a+'R'+a+'L'+a
        
from turtle import Screen,Turtle

def drawkoch(n):
    s=Screen()
    t=Turtle();t.speed(10)
    directions=koch(n)
    for move in directions:
        if move=='F':
            t.forward(500/3**n)
        elif move=='L':
            t.lt(60)
        elif move=='R':
            t.rt(120)

drawkoch(3)
k = input('')