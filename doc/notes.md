## Syntaxe
"%[flags][width][.precision][size]type"

## Types
cspdiuxX%
c: char  V
s: char*  V
p: void* --> 0x7ffeeb7d79cc
d: int --> == i  V
i: int  V
u: unsigned  V
x: hexa non signe en minuscules --> 7a  V
X: hexa non signe en majuscules --> 7A  V
%: symbole % <-- putchar

## Flags
"-0.*"
-: justifier a gauche
*: definie la largeur, ex: printf("number: %*d", width, number)
## Width
La chaine est completee avec des espaces si taille inferieure a width.
Par default, espaces avant.
Si flag -, espaces apres.
Si flag 0 et nombre, complete avec des 0

## Size
String --> length
Int --> nombre de 0 avant
Hexa --> nombre de 0 avant

## Valeur de retour
nm de char printed

## Cas foireux
"%%"
"%"
"%1"
"%x" sans arguments
gestion des erreurs
width < len(s)
flag avec type incompatible
chaine vide, (null)
flags non geres
gerer etoiles
% en fin de chaine
