%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%IMPLEMENTARE%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

- DRUM MAXIM DE COST MINIMC IN GRAF.

NUME: GEORGESCU
PRENUME: Alexandru Ionut
FACULTATE: Automatica si Calculatoare, Univeristatea Politehnica
GRUPA: 313CD

Algorimtul de calculare a costului minim din grafic se bazeasa pe alogoritmul
lui Kuhn.

 
Implementare:

Pasul unul:
 Se selecteaza minimul de pe fiecare linie si se scade din fiecare element
 de pe linie urmand sa creeze un zero pe linia respectiva, se aplica acest
 pas pe fiecare linie.

Pasul doi:
 Se verifica daca coloana are un zero, daca nu atunci se gaseste minimul si 
 se scade din ficare element pentru a construi un zero, se aplica pasul
 pentru fiecare coloana.

Pasul trei:
 Se marcheaza toate zerourile cu un numar minim de linii.
 Conditii de selectare:
  Daca se gaseste un zero pe o linie atunci se marcheaza acel 0 si se mar-
  cheaza coloana cu 0 respectiv. Se aplica acest lucru pentru fiecare linie.

  Daca se gaseste un zero pe o coloana atunci se marcheaza acel 0 si se mar-
  cheaza linia cu 0 respectiv. Se aplica acest lucru pentru fiecare linie.
 
  Daca se intalneste o coloana/linie cu mai multe zerouri atunci se ignora.

  Daca toate zeoruile au fost selectate si numarul lor corespund cu numarul
  de linii totale ale matricei atunci se trece la pasul 5, altfel si continua
  cu pasul 4.

Pasul patru:
  
  Se selecteaza cel mai mic element nemarcat, se scade din fiecare element 
  nemarcat si se aduna la fiecare punct de intersectie dintre linie, in acest
  mod se creeaza inca un zero si nu se schimba rezultatul. Apoi se revine la
  pasul 3.

Pasul cinci: 
 
  Se aduna fiecare element de pe pozitile zeorourilor marcat corespunzatoare
  matricei intiale iar acest lucru duce la costul minim din graf.

 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%IMPLEMENTARE%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
