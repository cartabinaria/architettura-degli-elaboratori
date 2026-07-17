---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 18-10-2023 21:56:14
links:
  - "[[lecture-21092023130150|Lecture 21092023130150]]"
---
# Multicomputer
---
## Introduzione
Infine, qualora il numero dei processori che accedono alla memoria condivisa fosse troppo alto, si passa al modello **multicomputer**, che prevede che singole [[cpu|CPU]] reperiscano le istruzioni da eseguire scambiandosi i messaggi a vicenda attraverso un'infrastruttura di rete.
![[multicomputer.png]]

Con questa tecnica è possibile far cooperare tantissime CPU, andando a costituire a tutti gli effetti un [[cluster|cluster]].

## Referenze