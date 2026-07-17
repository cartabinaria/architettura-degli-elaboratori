---
tags:
  - "#category/note"
  - "#status/finished"
  - topic/architettura-degli-elaboratori
date: 22-09-2023 19:28:38
links:
  - "[[lecture-20092023151652|Lecture 20092023151652]]"
---
# Registro
---
## Introduzione
> Un **registro** è una memoria interna alla [[cpu|CPU]] usata per memorizzare risultati temporanei o informazioni necessarie al funzionamento di determinate operazioni.

All'interno della CPU si trovano tanti registri, suddivisi in:
- _registri generali_
- _registri speciali_

### Registri generali
I registri generali sono dedicati unicamente alla memorizzazione di calcoli temporanei da parte della [[alu|ALU]], e solitamente si indicano come:
- `AX`
- `BX`
- `CX`
- `DX`

### Registri speciali
I registri speciali, o _dedicati_, sono per l'appunto specializzati a memorizzare determinati valori per contribuire al corretto funzionamento della CPU. In particolare tra di essi ritroviamo:
- [[pc|PC]] (_Program Counter_) --> contiene l'indirizzo della prossima istruzione da eseguire[^1]
- [[ir|IR]] (_Instruction Register_) --> contiene il valore della prossima istruzione da eseguire
- [[mar|MAR]] (_Memory Address Register_) --> contiene l'indirizzo di una cella di RAM (sulla quale si vuole svolgere una qualsivoglia operazione)
- [[mdr|MDR]] (_Memory Data Register_) --> contiene un valore ottenuto da o che si vuole inserire in RAM
- [[psw|PSW]] (_Program Status Word_) --> contiene una serie di _flag_ quali costituiscono nel loro insieme lo stato della macchina dopo l'esecuzione dell'ultima operazione

## Referenze
[^1]: inoltre si incrementa sempre all'indirizzo della prossima istruzione da eseguire, contemplando anche il caso speciale del _salto_ ([[jmp|JMP]])