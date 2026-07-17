---
tags:
  - "#category/note"
  - "#status/finished"
  - topic/architettura-degli-elaboratori
date: 22-09-2023 19:39:53
links:
  - "[[lecture-20092023151652|Lecture 20092023151652]]"
  - "[[lecture-21092023130150|Lecture 21092023130150]]"
---
# Ciclo di fetch-decode-execute
---
## Introduzione
Il ciclo di esecuzione di un'istruzione svolto dalla [[cpu|CPU]] nell'[[architettura-di-von-neumann|architettura di von Neumann]] si divide in 3 parti: _fetch_, _decode_ ed _execute_. E' importante partire dal presupposto che **è la [[cu|CU]] a governare questo ciclo**, e per farlo utilizza una serie di [[multiplexer|multiplexer]] che instradano il segnale in quelle componenti che vuole "attivare".
Quindi:
1. **Fetch** - caricamento di un'istruzione del programma dalla [[ram|RAM]]
	1. la CU dice di copiare il valore dal [[pc|PC]] al [[mar|MAR]]
	2. la CU accende il segnale _LEGGI_ della RAM
	3. il valore all'indirizzo dalla RAM viaggia sui _bus_ fino a [[mdr|MDR]]
	4. la CU dice di copiare il valore (_istruzione in binario_) dal MDR all'[[ir|IR]]
2. **Decode** - identificazione del tipo di istruzione da eseguire
	1. la CU analizza e decodifica l'istruzione
	2. la CU invia alla [[alu|ALU]] l'istruzione da eseguire
3. **Execute** - esecuzione delle operazioni corrispondenti all'istruzione
	1. la ALU esegue l'istruzione
		- se ci sono operandi da prelevare in memoria si usa lo stesso processo di prima (con MAR e MDR)
	2. terminata l'esecuzione il risultato va sul [[registro|registro]] di destinazione
		- se bisogna scrivere in memoria si usa lo stesso processo di prima (con MAR e MDR), attivando il segnale _SCRIVI_
	3. la CU incrementa PC

### Esempi
### `MOV AX, 5`
1. la CU dice di copiare il valore dal PC al MAR (inviando al multiplexer il segnale per instradare il segnale dal PC al MAR)
2. la CU accende il segnale LEGGI della RAM
3. la RAM mette sulle sue uscite il valore della cella
4. il valore viaggia sul bus dati fino al MDR
5. la CU dice di copiare il valore (codifica binaria dell'istruzione) dal MDR all'IR
6. la CU analizza l'istruzione, ci sono due opzioni
	- 1° opzione
		- la CU dice di copiare la fine di IR su AX (e mettere 0 sul resto)
	- 2° opzione
		- la CU dice di mandare la fine di IR a un ingresso della ALU (e mettere 0 per completare)
		- la CU dice di mandare 0 all'altro ingresso della ALU
		- la CU dice alla ALU di fare la somma
		- la CU dice alla ALU di mandare il suo risultato ad AX
7. incremento PC

### `JZ [AX]`
1. la CU dice di copiare il valore dal PC al MAR (inviando al multiplexer il segnale per instradare il segnale dal PC al MAR)
2. la CU accende il segnale LEGGI della RAM
3. la RAM mette sulle sue uscite il valore della cella
4. il valore viaggia sul bus dati fino al MDR
5. la CU dice di copiare il valore (codifica binaria dell'istruzione) dal MDR all'IR
6. la CU analizza l'istruzione
7.  la CU analizza il valore del bit di 0 di PSW, ci sono due opzioni
	- 1° opzione - se il bit di 0 non è acceso
		- la CU incrementa PC
	- 2° opzione - se il bit di 0 è acceso
		- la CU prende il valore di AX e lo copia su MAR
		- la CU accende il segnale LEGGI della RAM
		- la RAM invia sulle uscite il valore della cella all'indirizzo salvato in MAR
		- il valore viaggia sul bus dati e arriva al MDR
		- la CU copia il valore del MDR sul PC

## Referenze