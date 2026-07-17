---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 18-10-2023 22:06:41
links:
  - "[[lecture-18102023151217|Lecture 18102023151217]]"
---
# SRAM
---
## Introduzione
Le **SRAM** sono una tipologia di implementazione di [[memorie|memorie]] basate sui [[flip-flop|Flip-Flop]]. In particolare abbiamo visto come creare dei [[1-bit-register|registri a 1 bit]] usando i [[dff-latch|DFF Latch]].

## Utilizzi
Le SRAM sono alla base di:
- [[registro|registri]] (sia _generali_ che _speciali_)
- [[cache|cache]]

## Vantaggi e svantaggi
In rapporto alle [[dram|DRAM]], le SRAM **sono estremamente più veloci ma al contempo più costose in termini tecnologici**. Per realizzare un singolo registro a 1 bit servono molte [[porte-logiche|porte logiche]], a loro volta composte da non pochi [[transistor|transistors]]. A lungo andare, realizzare un'intera memoria SRAM è svantaggioso in termini economici.

## Referenze