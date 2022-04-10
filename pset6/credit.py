# Import
from cs50 import get_int


# Get positive int converted to str
def get_positive_str():

    # Ask for int
    input = get_int("Number: ")

    # Repetadly ask for int if given int is negative
    while (input < 0):
        input = get_int("Number: ")

    # Returns int converted to str
    return str(input)


# Luhn's algorithem function

def luhn_algo():
    # Call function to get positive int as string
    input = get_positive_str()

    # Counter
    sum = 0

    # Length
    length = len(input)

    # Counter values which should not be multiplied by 2
    for i in range(length - 1, -1, -2):
        sum = sum + int(input[i])

    # Count values which should be multiplied by 2
    for i in range(length - 2, -1, -2):
        z = 2 * int(input[i])
        if z > 9:
            x = str(z)
            sum = sum + int(x[0]) + int(x[1])
        else:
            sum = sum + z

    if sum % 10 == 0:
        print_name(input, length)
    else:
        print("INVALID")


def print_name(input, length):
    if length == 15 and input[0] == str(3) and (input[1] == str(4) or input[1] == str(7)):
        print("AMEX")
    elif length == 13:
        print("VISA")
    elif length == 16 and input[0] == str(4):
        print("VISA")
    elif length == 16 and input[0] == str(5) and (int(input[1]) >= 1 and int(input[1]) <= 5):
        print("MASTERCARD")


# Main function
def main():
    luhn_algo()


# If Main function exists
if __name__ == "__main__":
    main()