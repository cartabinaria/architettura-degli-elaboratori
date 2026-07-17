---
tags:
  - "#category/note"
  - "#status/finished"
  - topic/programmazione
  - topic/architettura-degli-elaboratori
date: 19-09-2023 09:39:00
links:
  - "[[lecture-18092023150410|Lecture 18092023150410]]"
  - "[[lecture-22112023151203|Lecture 22112023151203]]"
---
# Linker
---
## Introduzione
> Il **linker** è il programma che, nella fase di [[workflow-di-compilazione|compilazione]], _prende in input i moduli oggetto tradotti da un [[compilatore|compilatore]] e li unisce_ (per l'appunto _linka_) _per ottenere un unico file eseguibile_.

## Motivazioni
Il ruolo del linker risulta fondamentale in relazione alle [[libreria|librerie]]. Se di queste _fossero disponibili i file sorgente il problema del linking non si porrebbe_: basterebbe, prima della compilazione, unire tutti i file in un unico grande `main`. Il problema, però è che _nella maggior parte dei casi le librerie si presentano come file oggetto_, già compilate (per questioni legate alla licenza)...

Risulta quindi ovvio che il processo di "copia e incolla" di due file oggetto, già compilati, produrrebbe solo errori: **gli indirizzi dei [[salto-informatico|salti]] vanno rilocati**.

## Tipologie
Esistono due tipologie principali di linking:
- [[linking-statico|linking statico]]
- [[linking-dinamico|linking dinamico]]

## Referenze
- [esempio di linking](https://virtuale.unibo.it/pluginfile.php/1695559/mod_resource/content/2/14-EsRilocazione.txt)
- [spiegazione alternativa](https://www.docenti.unina.it/webdocenti-be/allegati/materiale-didattico/34403005)