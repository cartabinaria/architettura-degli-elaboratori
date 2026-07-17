---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 12-10-2023 22:56:34
links:
  - "[[lecture-12102023130419|Lecture 12102023130419]]"
---
# Codice di Hamming
---
## Introduzione
Il **codice di Hamming** è un [[codici-correttori|codice correttore]] in grado di _correggere gli errori su singoli bit usando il minor numero possibile di bit di controllo_ ($r$). Infatti, prendendo come riferimento la [[codici-correttori-principi-base|disequazione fondamentale]], tale codice trova un valore di $r$ minimo in grado di soddisfarla per qualunque valore di $m$.

## Funzionamento
### Codifica
```
Dato da codificare:
11001011    m = 8

0  0     0           1 
X  X  1  X  1  0  0  X  1  0  1  1

1  2  3  4  5  6  7  8  9 10 11 12

0  0  0  0  0  0  0  1  1  1  1  1
0  0  0  1  1  1  1  0  0  0  0  1
0  1  1  0  0  1  1  0  0  1  1  0
1  0  1  0  1  0  1  0  1  0  1  0

X     1     1     0     1     1

   X  1        0  0        0  1

         X  1  0  0              1

                     X  1  0  1  1

Dato codificato:
001010011011
```

### Decodifica
```
Dato da decodificare:
0  1  1  0  1  0  0  1  1  0  1  1

1  2  3  4  5  6  7  8  9 10 11 12

0  0  0  0  0  0  0  1  1  1  1  1
0  0  0  1  1  1  1  0  0  0  0  1
0  1  1  0  0  1  1  0  0  1  1  0
1  0  1  0  1  0  1  0  1  0  1  0

0     1     1     0     1     1      OK   1  

   1  1        0  0        0  1      X    2    2

         0  1  0  0              1   OK   4
    
                     1  1  0  1  1   OK   8

Scrivendo 1 per i bit di parita' errati e 0 per quelli corretti
ottengo la posizione dell'errore:

0010 pos 2
```

## Referenze