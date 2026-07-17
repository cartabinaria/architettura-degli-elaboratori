---
tags:
  - category/note
  - status/finished
  - topic/architettura-degli-elaboratori
date: 07-11-2023 22:25:26
links:
  - "[[lecture-06112023131103|Lecture 06112023131103]]"
---
# Computer HACK
---
## Introduzione
Il computer HACK è un grande [[circuiti-sequenziali|circuito sequenziale]] di architettura simile a quella di [[architettura-di-von-neumann|von Neumann]] a _16 bit_ con la differenza che la [[memorie|memoria]] è separata in [[ram|RAM]], _contenente i dati_, e [[rom|ROM]], _contenente i programmi_, così da **permettere il caricamento contemporaneo di dati e istruzioni**.

![[computer-hack.png]]

## Componenti
- memoria
	- [[rom|ROM]]
	- [[ram|RAM]]
		- dati
			- range: `0-16383`
		- schermo
			- range: `16384-24575`
			- funzionamento
				- ogni bit di ogni locazione di memoria corrisponde a un pixel
					- lo schermo è una [[matrice-informatica|matrice]] da 256 righe e 512 colonne
				- formula usando valori di `row` e `col`
					- `Screen[row*32+col/16]` --> per ottenere cella[^1]
					- `col%16 = 1` --> per porre a `1` il `col%16`-esimo bit della locazione
			- ![[screen-hack.png]]
		- tastiera
			- range: `24576` (un registro a 16 bit)
			- funzionamento
				- _possiamo solo leggere dalla memoria i tasti premuti sulla tastiera_ --> vengono automaticamente caricati in memoria dal simulatore
				- si usa tecnica del [[memory-mapped-i-o|memory mapping]]
	- ![[memoria-hack.png]]
	- osservazioni:
		- per indirizzare 24576 indirizzi servono per forza 15 bit dell'address --> i restanti indirizzi non vengono considerati
- [[cpu-hack|CPU HACK]]
	- componenti:
		- [[alu-hack|ALU HACK]]
		- [[microarchitettura-hack-componenti|registro A]]
		- [[microarchitettura-hack-componenti|registro D]]
		- [[microarchitettura-hack-componenti|registro PC]]
		- eventualmente il [[cu-hack|control HACK]]
	- ![[cpu-hack.png]]

## Referenze
- [[architettura-hack|Architettura HACK]]

[^1]: `@SCREEN` come variabile predefinita nell'[[isa-hack|ISA HACK]] per puntare alla sezione di RAM dello schermo