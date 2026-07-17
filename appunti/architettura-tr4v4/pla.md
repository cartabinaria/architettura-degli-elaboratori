---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 30-09-2023 19:57:25
links:
  - "[[lecture-28092023130653|Lecture 28092023130653]]"
---
# PLA
---
## Definizione
> I **PLA** (_Programmable Logic Array_) sono _circuiti universali_ pre-costruiti per adattarsi alla [[forma-canonica-booleana|forma canonica]]. Sono composti infatti da $n$ ingressi ognuno dei quali sarà fatto confluire in un [[and|AND]] che rappresenta un _mintermine_, cui output a loro volta saranno raccolti in un [[or|OR]].

All'ingresso di ogni AND è possibile **rompere uno dei due fusibili che collega l'input al mintermine, a seconda che il segnale si voglia invertito o meno**. Quindi ad ogni ingresso si può scegliere se far collegare al mintermine il segnale con un [[not|NOT]] oppure senza, per ottenere applicata al circuito la forma canonica.

![[pla.png]]

## Referenze