---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 08-10-2023 19:14:30
links:
  - "[[lecture-05102023130513|Lecture 05102023130513]]"
---
# Codifica numeri interi
---
## Introduzione
Le "buone" codifiche sono quelle che si appoggiano ad un sistema matematico. Nel caso della codifica di [[numeri-interi|numeri interi]], vale che:
> Data una codifica in base $b$ è possibile rappresentare i numeri interi tramite sequenze di cifre da $0$ a $b-1$.

Per esempio la codifica in base 10 utilizza le cifre da 0 a 9; la codifica in base 2 le cifre 0 e 1; e così via.

Esiste una formula di conversione da qualsiasi codifica a quella base 10:
$$\sum\limits_{i=0..k} d_{i} \times b^{i}$$
dove:
- $k$ è il numero di cifre
- $d_{i}$ è l'i-esima cifra
- $b^{i}$ è la base alla i

## Tipologie di codifiche
Nel campo informatico le principali codifiche sono:
- [[codice-binario|codifica binaria]]
- [[codice-ottale|codifica ottale]]
- [[codice-esadecimale|codifica esadecimale]]

Si può notare come tutte e tre le basi siano _potenze di 2_, ovvio per la natura stessa degli elaboratori.

Un qualunque numero può essere quindi rappresentato in queste 3 codifiche. Per esempio per `2001` si ha:
![[codifiche-informatiche.png]]

<u>Attenzione</u>: **il computer lavora solo e unicamente con il codice binario**, _quello ottale ed esadecimale serve a noi_ per visualizzare con più facilità grandi quantità di bit e semplificare i calcoli.

### Conversioni
Il punto ora è passare da una codifica all'altra:
- [[conversione-binario-ottale-esadecimale|Conversione binario-ottale-esadecimale]]
- [[conversione-binario-decimale|Conversione binario-decimale]]

## Numeri negativi
Abbiamo visto come rappresentare i numeri in tutte e 3 le principali codifiche informatiche, ma senza tenere in considerazione l'_esistenza dei negativi_. Quindi: come si rappresentano i numeri negativi in binario?

Ebbene, qui la matematica non ci può essere d'aiuto: dobbiamo inventarci noi una _convenzione_ per rappresentarli. Per questo esistono diverse tecniche:
- [[modulo-e-segno|modulo e segno]]
- [[complemento-a-1|complemento a 1]]
- [[complemento-a-2|complemento a 2]]
- [[codifica-in-eccesso|codifica in eccesso]]

## Referenze