---
tags:
  - "#category/note"
  - "#status/finished"
  - topic/programmazione
  - topic/architettura-degli-elaboratori
date: 18-09-2023 22:11:42
links:
  - "[[lecture-18092023150410|Lecture 18092023150410]]"
  - "[[lecture-20092023151652|Lecture 20092023151652]]"
---
# CPU
---
## Introduzione
> La **CPU** (_Central Processing Unit_) è quella componente hardware di un elaboratore che ha il compito di _eseguire le istruzioni in memoria_.

Le CPU eseguono solo codice macchina, per questo il _linguaggio ad alto livello_ dev'essere tradotto (o meglio, [[compilatore|compilato]]) in un _linguaggio a basso livello_, per l'appunto il **linguaggio macchina**.

## Composizione
La CPU si compone di diverse parti, ognuna di esse specializzate per svolgere precise operazioni:
- [[cu|CU]]
- [[alu|ALU]]
- [[registro|Registri]]

![[architettura-von-neumann.png]]

Il funzionamento di queste parti all'opera viene chiamato [[ciclo-di-fetch-decode-execute|ciclo di fetch-decode-execute]].

## Referenze
- [[cisc-e-risc|CISC e RISC]]