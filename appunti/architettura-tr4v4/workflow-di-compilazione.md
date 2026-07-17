---
tags:
  - "#category/note"
  - "#status/finished"
  - topic/programmazione
  - topic/architettura-degli-elaboratori
date: 19-09-2023 09:43:09
links:
  - "[[lecture-18092023150410|Lecture 18092023150410]]"
  - "[[lecture-25102023150405|Lecture 25102023150405]]"
  - "[[lecture-22112023151203|Lecture 22112023151203]]"
---
# Workflow di compilazione
---
## Processi
I processi consistono in:
1. il [[compilatore|compilatore]] traduce il linguaggio ad alto livello in linguaggio oggetto (_source code_ --> _object code_), ovvero [[assembly|assembly]]
2. il [[linker|linker]] unisce al codice compilato il codice oggetto delle librerie importate
3. il computer (e in particolare l'[[assemblatore|assemblatore]]) traduce il codice oggetto in codice macchina (in [[codice-binario|binario]]) e lo esegue (con il [[loader|loader]])

### Schema
![[compilazione-ed-esecuzione-programma.png]]

![[traduzione.png]]

## Tipologie
- [[compilazione-diretta|Compilazione diretta]]
- [[compilazione-a-2-livelli|Compilazione a 2 livelli]]

## Referenze