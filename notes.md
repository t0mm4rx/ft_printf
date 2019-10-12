## Syntaxe
"%[flags][width][.precision][size]type"

## Types
cspdiuxX%
c: char
s: char*
p: void* --> 0x7ffeeb7d79cc
d: int --> == i
i: int
u: unsigned
x: hexa non signe en minuscules --> 7a
X: hexa non signe en majuscules --> 7A

## Flags
"-0.*"
-: justifier a gauche
*: definie la largeur, ex: printf("number: %*d", width, number)
## Width
La chaine est completee avec des espaces si taille inferieure a width.
Par default, espaces avant.
Si flag -, espaces apres.
Si flag 0 et nombre, complete avec des 0

## Cas foireux
"%%"
"%"
"%x" sans arguiments
gestion des erreurs
width < len(s)
flag avec type incompatible
