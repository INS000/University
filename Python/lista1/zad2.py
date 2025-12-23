def is_palindrom(text):
    pom = text.lower()
    punc = '''!@#$%^&*()-_+=~` {}[]'"\,|:;/?.><'''
    for a in pom:
        if a in punc:
            pom = pom.replace(a, '')
    pom2 = pom[::-1]
    return pom == pom2

print(is_palindrom('al,A'))
print(is_palindrom("Eine güldne, gute Tugend: Lüge nie!"))
print(is_palindrom("Míč omočím.")) #nie działa =(
