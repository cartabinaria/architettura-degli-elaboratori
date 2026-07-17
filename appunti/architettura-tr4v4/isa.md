---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 28-10-2023 12:44:24
links:
  - "[[lecture-25102023150405|Lecture 25102023150405]]"
  - "[[lecture-02112023130607|Lecture 02112023130607]]"
---
# ISA
---
## Introduzione
> L'**ISA** (_Instruction Set Architecture_) indica di una specifica [[microarchitettura|microarchitettura]] l'_insieme delle istruzioni software eseguibili dall'hardware_.

Prendendo come riferimento il concetto di [[macchina-multilivello|macchina multilivello]], il livello ISA si occupa di **interfacciare l'hardware con il software**, associando (a seconda del tipo di microarchitettura) istruzioni di basso livello software a "comandi" computabili dalla [[cpu|CPU]].

![[livello-isa.png]]

Ogni microarchitettura ha il suo _instruction set_, cucito su misura per quel particolare processore[^2].

### Workflow
1. dai livelli superiori l'ISA riceve programmi ad alto livello
2. li traduce attraverso il [[compilatore|compilatore]] in istruzioni di basso livello ([[assembly|assembly]])
3. le traduce attraverso l'[[assemblatore|assemblatore]] in [[codice-binario|codice binario]] eseguibile dalla CPU
[^1]

## Referenze
- [[isa-hack|ISA HACK]]
- [[istruzioni-isa|Istruzioni ISA]]

[^1]: vedi [[workflow-di-compilazione|workflow di compilazione]]
[^2]: si veda il dibattito [[cisc-e-risc|CISC e RISC]]