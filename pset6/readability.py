from cs50 import get_string

# Main function


def main():
    # Get text from user
    text = get_string("Text: ")

    # Count letters, words, sentences
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    # count L and S
    L = 100.0 * (letters/words)
    S = 100.0 * (sentences/words)

    # Calculate index
    index = 0.0588 * L - 0.296 * S - 15.8

    # Print grade
    if index > 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print("Grade {}".format(round(index)))


# Counts letters
def count_letters(text):
    letter_counter = 0

    for x in text:
        c = x.upper()
        if c >= 'A' and c <= 'Z':
            letter_counter += 1

    print(letter_counter)
    return letter_counter


# Counts words
def count_words(text):
    word_counter = 1

    for x in text:
        if x == ' ':
            word_counter += 1

    print(word_counter)
    return word_counter


# Counts sentences
def count_sentences(text):
    sentence_counter = 0

    for x in text:
        if x == '.':
            sentence_counter += 1
        elif x == '!':
            sentence_counter += 1
        elif x == '?':
            sentence_counter += 1

    print(sentence_counter)
    return sentence_counter


# Calls main function if main function exist
if __name__ == "__main__":
    main()