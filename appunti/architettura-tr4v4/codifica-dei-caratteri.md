---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
  - topic/tecnologie-web
date: 12-10-2023 19:51:48
links:
  - "[[lecture-11102023151203|Lecture 11102023151203]]"
---
# Codifica dei caratteri
---
## Introduzione
A differenza di quanto concerne la [[codifica-numeri-interi|codifica degli interi]] e la [[codifica-floating-point|codifica dei decimali]], **la codifica dei caratteri è una convenzione**, e non ha quindi presupposti matematici su cui basarsi.

## Definizione
> Codifica un carattere significa _associarvi un numero_ così da identificarlo e rappresentarne le caratteristiche più importanti.

Internet ha posto il _problema di codificare i caratteri di tutte le lingue del mondo in modo univoco e non ambiguo_: infatti ogni alfabeto ha particolarità diverse.

Si associano ai caratteri un insieme di valori numerici in base a 3 criteri:
- _ordine_, i valori numerici seguono l'ordine alfabetico culturalmente riconosciuto;
- _contiguità_, ogni valore numerico compreso tra il più basso e il più alto è associato ad un carattere;
- _raggruppamento_, l'appartenenza ad un gruppo logico è facilmente riconoscibile da considerazioni numeriche.

In più si possono riconoscere altri termini, come lo _shift_, i _codici liberi_ e i _codici di controllo_. Si prenda come esempio il codice della prima telescrivente inventata da Baudot.

## Principali codifiche
- [[ascii|ASCII]]
- [[ebcdic|EBCDIC]]
- [[iso-646-1991|ISO 646-1991]]
- [[koi7|KOI7]]
- [[codifiche-cjk|Codifiche CJK]]
- [[iso-latin-1|ISO Latin 1]]
- [[unicode|UNICODE]]
- [[utf-8|UTF-8]] e [[utf-16|UTF-16]]

## Referenze