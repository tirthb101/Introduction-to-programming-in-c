# Import
import csv
import sys

# Check for correct useage of file
if len(sys.argv) != 3:
    sys.exit("Usage: python dna.py CSVFILE SEQUENCE")

# Declare structs
lists = []
sequences = {}


# Main function
def main():

    # execute few functions that read data into memory
    read_csv()
    read_data = read_sequences()

    # Individually check how many times a perticular sequence repeats and assign the value in dictionary file
    for sqnc in sequences:
        sequences[sqnc] = chk_sq_row(sqnc, read_data)

    # Print match
    print_match()


# Read csv file and prepare sequences that we want to check for
def read_csv():
    # Load csv file in lists as lists inside lists sort of like 2D array
    with open(sys.argv[1], "r") as csvfile:
        reader = csv.reader(csvfile)
        for row in reader:
            lists.append(row)

    # Add sequences that we will be checking for in sequences dictionary
    for i in range(1, len(lists[0]), 1):
        sequences[lists[0][i]] = 0


# Read sequence of given sample of dna and store in memory as string
def read_sequences():
    with open(sys.argv[2], "r") as file:
        read_data = file.read()
    return read_data

# Check for perticular sequence's longest repeat


def chk_sq_row(sqnc, read_data):

    # Variables
    counter_loop = 0
    permenant = 0
    temporary = 0

    # Some calculations
    increment = len(sqnc)
    till = len(read_data) - increment

    # While loop
    while counter_loop < till:

        # If sequence found
        if read_data[counter_loop: counter_loop + increment] == sqnc:
            temporary += 1
            counter_loop += increment

        # If sequence stops continuing and is longer than previously found
        elif temporary >= permenant:
            permenant = temporary
            temporary = 0
            counter_loop += 1

        # If sequence stops continuing and is not longer than previously found
        else:
            temporary = 0
            counter_loop += 1

    # Retern str count
    return permenant


def print_match():

    # Calculate rows and collums of 2D array like structure lists
    len_row = len(lists[0])
    len_col = len(lists)

    # Check each row one by one
    for i in range(1, len_col, 1):

        # Counter
        counter = 0

        # Check colum by colum
        for j in range(1, len_row, 1):
            if int(lists[i][j]) == sequences[lists[0][j]]:
                counter += 1
            else:
                counter = 0
                break

        # if counter equal len_row - 1 than print name and close program
        if counter == (len_row - 1):
            print(lists[i][0])
            return 0

    # IF no match found
    print("No match")


# Executes main function if main function exists
if __name__ == "__main__":
    main()