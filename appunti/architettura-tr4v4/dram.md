---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 18-10-2023 22:10:42
links:
  - "[[lecture-18102023151217|Lecture 18102023151217]]"
---
# DRAM
---
## Introduzione
Le **DRAM** sono una tipologia di implementazione di [[memorie|memorie]] che sfruttano i principi del [[condensatore|condensatore]]. Fondamentalmente uno _pseudo-[[1-bit-register|registro a 1 bit]]_ DRAM sarebbe composto solo da un [[transistor|transistor]] e un condensatore: questi ultimi infatti mantengono la carica (e quindi l'_informazione_) per qualche frazione di secondo.

## Utilizzi
Le DRAM sono alla base di:
- [[ram|RAM]]

## Vantaggi e svantaggi
A differenza delle [[sram|SRAM]], le DRAM hanno il difetto di dover fare dei _refresh_ ad intervalli di tempo estremamente piccoli per _mantenere vivi i bit nei condensatori_. E' proprio a causa del refresh che sono più lente. Si guadagna invece in impegno tecnologico e in sforzo economico.

## Referenze