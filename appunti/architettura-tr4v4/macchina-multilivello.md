---
tags:
  - "#category/note"
  - "#status/finished"
  - topic/architettura-degli-elaboratori
date: 18-09-2023 21:54:20
links:
  - "[[lecture-18092023130242|Lecture 18092023130242]]"
---
# Macchina multilivello
---
## Introduzione
> Gli elaboratori digitali sono macchine multilivello.

Di esse, ogni livello:
- è astratto e virtualizzato da quello sovrastante
- implementa quello sottostante

## Elaboratore a 6 livelli
![[elaboratore-6-livelli.png]]

Nel dettaglio:
- **livello 0** --> logico digitale, composto da [[porte-logiche|porte logiche]], [[circuiti-combinatori|circuiti combinatori]] e [[circuiti-sequenziali|circuiti sequenziali]]
- **livello 1** --> [[microarchitettura|microarchitettura]], governa il flusso dei dati fra i componenti del livello logico digitale
- **livello 2** --> [[isa|ISA]] (_Instruction Set Architecture_), interfaccia tra hardware e software
- **livello 3/4** --> [[sistema-operativo|Sistema operativo]] (_Sistema Operativo_), [[assembly|Assembly]]
- **livello 5** --> linguaggi ad alto livello

## Referenze