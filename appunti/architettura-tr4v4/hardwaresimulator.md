---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 30-09-2023 20:36:12
links:
  - "[[lecture-28092023130653|Lecture 28092023130653]]"
  - "[[lecture-16102023125805|Lecture 16102023125805]]"
---
# HardwareSimulator
---
## Introduzione
> **HardwareSimulator** è un software che permette di caricare [[circuiti-combinatori|circuiti combinatori]] codificati in [[hdl|HDL]] e di testarli.

Permette anche di utilizzare [[circuiti-sequenziali|circuiti sequenziali]] _solo se implementati attraverso un [[dff-latch|DFF Latch]] built-in_. Altri "cicli" (tipici dei sequenziali) non sono ammessi.

## Workflow
1. si scrive l'_HDL_
2. si prepara il _.TST_ --> file di testing[^1]
3. si prepara il _.CMP_ --> tabella di verità
4. si carica il .TST e si fa il test

## Referenze
- [documentazione](https://virtuale.unibo.it/pluginfile.php/1695569/mod_resource/content/1/Hardware_Simulator_Tutorial.pdf)

[^1]: sulla falsa riga delle [[junit|JUnit]]