# import
from cs50 import get_int

# get height of the pyramid from user
answer = get_int("Height: ")

while(answer < 1 or answer > 8):
    answer = get_int("Height: ")

# assign variables
x = answer
y = 0

# nested for loops
for i in range(answer):
    # decrease the number of spaces as the first loop iterates again and again
    x -= 1
    # increase the number of spaces as the first loop iterates again and again
    y += 1

    # print left side of pyramid
    for j in range(x):

        print(" ", end="")

    for k in range(y):

        print("#", end="")

    # print two spaces between two pyramids
    print("  ", end="")

    # print right side of pyramid
    for k in range(y):

        print("#", end="")

    # move to a new line
    print()