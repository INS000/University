from word2number import w2n
from num2words import num2words

def sort_word(lista):
    return map(lambda x:num2words(x), list(map(lambda x: w2n.word_to_num(x), lista)).sort())

test = ["thirty thousand two hundred","eight hundred fifteen","one hundred twenty three"]
print(sortowanie(test))
