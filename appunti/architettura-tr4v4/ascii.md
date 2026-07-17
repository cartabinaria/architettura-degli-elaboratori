---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
  - topic/tecnologie-web
date: 12-10-2023 19:57:56
links:
  - "[[lecture-11102023151203|Lecture 11102023151203]]"
---
# ASCII
---
## Introduzione
> La [[codifica-dei-caratteri|codifica]] **ASCII** (_American Standard Code for Information Interchange_) è storicamente la più importante e diffusa.

## Struttura
Si compone di 8 bit, di cui 7 usati effettivamente per la codifica e 1 come [[bit-di-parita|bit di parità]], e **assegna ad ogni carattere un codice**. Per le sue origini i primi 20 caratteri sono dedicati al controllo dell'invio e ricezione di messaggi (_caratteri speciali_).
![[ascii-table.webp]]

Possiede 33 caratteri di controllo e 95 caratteri dell'alfabeto latino.

### Code page
Con la disponibilità di hardware più affidabile, IBM e Microsoft propongono un meccanismo di estensione dell'ASCII che sfrutti i 128 caratteri rimanenti (togliendo il bit di parità) per le necessità di _script e alfabeti diversi_: **code page**.

Per esempio, la CP 737 è la code page ASCII per il greco; le CP 720, 864 e 1256 sono per l'arabo; la CP 862 è per l'ebraico moderno.

## Problemi
Il problema alla base dell'ASCII è che esclude completamente ogni alfabeto che non abbia le stesse lettere anglosassoni. Inoltre, 256 caratteri sono troppo pochi.

## Referenze