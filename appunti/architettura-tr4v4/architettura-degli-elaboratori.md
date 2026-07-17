---
tags:
  - category/moc
  - status/finished
  - topic/architettura-degli-elaboratori
date: 18-09-2023 12:56:24
---
# Architettura degli elaboratori
---
## Lezioni
### Ultima lezione
<!-- QueryToSerialize: TABLE WITHOUT ID file.link AS Lezione, file.inlinks AS Note FROM #category/lecture AND #topic/architettura-degli-elaboratori SORT file.ctime DESC LIMIT 1 -->
<!-- SerializedQuery: TABLE WITHOUT ID file.link AS Lezione, file.inlinks AS Note FROM #category/lecture AND #topic/architettura-degli-elaboratori SORT file.ctime DESC LIMIT 1 -->

| Lezione                                                           | Note                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| ----------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| [[lecture-18102023151217|Lecture 18102023151217]] | <ul><li>[[architettura-degli-elaboratori|Architettura degli elaboratori]]</li><li>[[cache|Cache]]</li><li>[[dram|DRAM]]</li><li>[[direct-mapped-cache|Direct Mapped Cache]]</li><li>[[memorie|Memorie]]</li><li>[[microarchitettura-hack|Microarchitettura HACK]]</li><li>[[microarchitettura|Microarchitettura]]</li><li>[[sram|SRAM]]</li></ul> |
<!-- SerializedQuery END -->

### Lista
<!-- QueryToSerialize: TABLE WITHOUT ID file.link AS Lezione, date AS Data FROM #category/lecture AND #topic/architettura-degli-elaboratori SORT file.ctime DESC -->
<!-- SerializedQuery: TABLE WITHOUT ID file.link AS Lezione, date AS Data FROM #category/lecture AND #topic/architettura-degli-elaboratori SORT file.ctime DESC -->

| Lezione                                                           | Data                |
| ----------------------------------------------------------------- | ------------------- |
| [[lecture-18102023151217|Lecture 18102023151217]] | 18-10-2023 15:12:17 |
| [[lecture-21092023130150|Lecture 21092023130150]] | 21-09-2023 13:01:50 |
| [[lecture-22112023151203|Lecture 22112023151203]] | 22-11-2023 15:12:03 |
| [[lecture-05102023130513|Lecture 05102023130513]] | 05-10-2023 13:05:13 |
| [[lecture-02112023130607|Lecture 02112023130607]] | 02-11-2023 13:06:07 |
| [[lecture-25092023130405|Lecture 25092023130405]] | 25-09-2023 13:04:05 |
| [[lecture-19102023130600|Lecture 19102023130600]] | 19-10-2023 13:06:00 |
| [[lecture-16112023133640|Lecture 16112023133640]] | 16-11-2023 13:36:40 |
| [[lecture-20092023151652|Lecture 20092023151652]] | 20-09-2023 15:16:52 |
| [[lecture-16102023125805|Lecture 16102023125805]] | 16-10-2023 12:58:05 |
| [[lecture-20112023130829|Lecture 20112023130829]] | 20-11-2023 13:08:29 |
| [[lecture-28092023130653|Lecture 28092023130653]] | 28-09-2023 13:06:53 |
| [[lecture-11102023151203|Lecture 11102023151203]] | 11-10-2023 15:12:03 |
| [[lecture-25102023150405|Lecture 25102023150405]] | 25-10-2023 15:04:05 |
| [[lecture-12102023130419|Lecture 12102023130419]] | 12-10-2023 13:04:19 |
| [[lecture-13112023131012|Lecture 13112023131012]] | 13-11-2023 13:10:12 |
| [[lecture-26102023132035|Lecture 26102023132035]] | 26-10-2023 13:20:35 |
| [[lecture-09112023093612|Lecture 09112023093612]] | 09-11-2023 09:36:12 |
| [[lecture-18092023130242|Lecture 18092023130242]] | 18-09-2023 13:02:42 |
| [[lecture-27092023150312|Lecture 27092023150312]] | 27-09-2023 15:03:12 |
| [[lecture-23112023130836|Lecture 23112023130836]] | 23-11-2023 13:08:36 |
| [[lecture-06112023131103|Lecture 06112023131103]] | 06-11-2023 13:11:03 |
| [[lecture-09102023132029|Lecture 09102023132029]] | 09-10-2023 13:20:29 |
| [[lecture-02102023130256|Lecture 02102023130256]] | 02-10-2023 13:02:56 |
| [[lecture-15112023151146|Lecture 15112023151146]] | 15-11-2023 15:11:46 |
<!-- SerializedQuery END -->

### Da processare
<!-- QueryToSerialize: TABLE WITHOUT ID file.link as Lezione, filter(file.tags, (t) => t="#status/pending" OR t="#status/ongoing") AS Status FROM #category/lecture AND #topic/architettura-degli-elaboratori AND (#status/pending OR #status/ongoing) SORT date DESC -->
<!-- SerializedQuery: TABLE WITHOUT ID file.link as Lezione, filter(file.tags, (t) => t="#status/pending" OR t="#status/ongoing") AS Status FROM #category/lecture AND #topic/architettura-degli-elaboratori AND (#status/pending OR #status/ongoing) SORT date DESC -->

| Lezione | Status |
| ------- | ------ |
<!-- SerializedQuery END -->

## Note
Argomenti:
- [[storia-degli-elaboratori|Storia degli elaboratori]]
- [[architettura-di-von-neumann|Architettura di von Neumann]]
- [[parallelismo|Parallelismo]]
- [[macchina-multilivello|Macchina multilivello]]
- Livello logico digitale
	- [[porte-logiche|Porte logiche]] e [[circuiti-combinatori|Circuiti combinatori]]
	- [[rappresentazione-dell-informazione|Rappresentazione dell'informazione]]
		- [[codici-correttori|Codici correttori]]
	- [[alu-hack|ALU HACK]]
	- [[circuiti-sequenziali|Circuiti sequenziali]]
	- [[memorie|Memorie]]
- [[microarchitettura|Microarchitettura]]
	- [[microarchitettura-hack|Microarchitettura HACK]]
	- [[cache|Cache]]
	- [[pipelining|Pipelining]]
- [[isa|ISA]]
	- [[istruzioni-isa|Istruzioni ISA]]
		- [[isa-hack|ISA HACK]]
		- [[computer-hack|Computer HACK]]
	- [[invocazione-di-procedura|Invocazione di procedura]]
		- [[record-di-attivazione|Record di attivazione]]
		- [[trap|Trap]]
		- [[interrupt|Interrupt]]
- [[sistema-operativo|Sistema operativo]]
	- Compiti
		- [[paginazione|Paginazione]]
		- [[segmentazione|Segmentazione]]
		- [[frammentazione|Frammentazione]]
		- [[combinazione-segmentazione-paginazione|Combinazione segmentazione-paginazione]]
	- [[workflow-di-compilazione|Workflow di compilazione]]
		- [[linker|Linker]]
			- [[linking-statico|Linking statico]]
			- [[linking-dinamico|Linking dinamico]]
		- [[compilazione-diretta|Compilazione diretta]]
		- [[compilazione-a-2-livelli|Compilazione a 2 livelli]]
	- [[virtual-machine|Virtual machine]]
		- [[virtual-machine-hack|Virtual machine HACK]]

<!-- QueryToSerialize: TABLE WITHOUT ID file.link AS Note, filter(file.tags, (t) => t="#status/pending" OR t="#status/ongoing" OR t="#status/finished") AS Status FROM #category/note AND #topic/architettura-degli-elaboratori SORT file.ctime DESC -->
<!-- SerializedQuery: TABLE WITHOUT ID file.link AS Note, filter(file.tags, (t) => t="#status/pending" OR t="#status/ongoing" OR t="#status/finished") AS Status FROM #category/note AND #topic/architettura-degli-elaboratori SORT file.ctime DESC -->

| Note                                                                                             | Status                             |
| ------------------------------------------------------------------------------------------------ | ---------------------------------- |
| [[big-endian-little-endian|Big-endian [[Big-endian & Little-endian]] Little-endian]]                           | <ul><li>#status/finished</li></ul> |
| [[unicode|UNICODE]]                                                                 | <ul><li>#status/finished</li></ul> |
| [[ascii|ASCII]]                                                                     | <ul><li>#status/finished</li></ul> |
| [[codifica-dei-caratteri|Codifica dei caratteri]]                                   | <ul><li>#status/finished</li></ul> |
| [[rappresentazione-dell-informazione|Rappresentazione dell'informazione]]           | <ul><li>#status/finished</li></ul> |
| [[utf-8|UTF-8]]                                                                     | <ul><li>#status/finished</li></ul> |
| [[memorie|Memorie]]                                                                 | <ul><li>#status/finished</li></ul> |
| [[codifica-floating-point|Codifica floating-point]]                                 | <ul><li>#status/finished</li></ul> |
| [[pipelining|Pipelining]]                                                           | <ul><li>#status/finished</li></ul> |
| [[virtual-machine-hack|Virtual machine HACK]]                                       | <ul><li>#status/finished</li></ul> |
| [[paginazione|Paginazione]]                                                         | <ul><li>#status/finished</li></ul> |
| [[cache|Cache]]                                                                     | <ul><li>#status/finished</li></ul> |
| [[alu-hack|ALU HACK]]                                                               | <ul><li>#status/finished</li></ul> |
| [[direct-mapped-cache|Direct Mapped Cache]]                                         | <ul><li>#status/finished</li></ul> |
| [[ciclo-di-fetch-decode-execute|Ciclo di fetch-decode-execute]]                     | <ul><li>#status/finished</li></ul> |
| [[mappe-di-karnaugh|Mappe di Karnaugh]]                                             | <ul><li>#status/finished</li></ul> |
| [[dimostrazione-r-non-numerabile|Dimostrazione R non numerabile]]                   | <ul><li>#status/finished</li></ul> |
| [[isa-hack|ISA HACK]]                                                               | <ul><li>#status/finished</li></ul> |
| [[linking-statico|Linking statico]]                                                 | <ul><li>#status/finished</li></ul> |
| [[codici-correttori|Codici correttori]]                                             | <ul><li>#status/finished</li></ul> |
| [[ram|RAM]]                                                                         | <ul><li>#status/finished</li></ul> |
| [[codifica-numeri-interi|Codifica numeri interi]]                                   | <ul><li>#status/finished</li></ul> |
| [[microarchitettura|Microarchitettura]]                                             | <ul><li>#status/finished</li></ul> |
| [[microarchitettura-hack|Microarchitettura HACK]]                                   | <ul><li>#status/finished</li></ul> |
| [[combinazione-segmentazione-paginazione|Combinazione segmentazione-paginazione]]   | <ul><li>#status/finished</li></ul> |
| [[storia-degli-elaboratori|Storia degli elaboratori]]                               | <ul><li>#status/finished</li></ul> |
| [[computer-hack|Computer HACK]]                                                     | <ul><li>#status/finished</li></ul> |
| [[conversione-binario-decimale|Conversione binario-decimale]]                       | <ul><li>#status/finished</li></ul> |
| [[linking-dinamico|Linking dinamico]]                                               | <ul><li>#status/finished</li></ul> |
| [[interrupt|Interrupt]]                                                             | <ul><li>#status/finished</li></ul> |
| [[architettura-di-von-neumann|Architettura di von Neumann]]                         | <ul><li>#status/finished</li></ul> |
| [[clock|Clock]]                                                                     | <ul><li>#status/finished</li></ul> |
| [[record-di-attivazione|Record di attivazione]]                                     | <ul><li>#status/finished</li></ul> |
| [[segmentazione|Segmentazione]]                                                     | <ul><li>#status/finished</li></ul> |
| [[complemento-a-2|Complemento a 2]]                                                 | <ul><li>#status/finished</li></ul> |
| [[nand|NAND]]                                                                       | <ul><li>#status/finished</li></ul> |
| [[codice-di-hamming|Codice di Hamming]]                                             | <ul><li>#status/finished</li></ul> |
| [[registro|Registro]]                                                               | <ul><li>#status/finished</li></ul> |
| [[forma-canonica-booleana|Forma canonica booleana]]                                 | <ul><li>#status/finished</li></ul> |
| [[invocazione-di-procedura|Invocazione di procedura]]                               | <ul><li>#status/finished</li></ul> |
| [[linker|Linker]]                                                                   | <ul><li>#status/finished</li></ul> |
| [[sistema-operativo|Sistema operativo]]                                             | <ul><li>#status/finished</li></ul> |
| [[istruzioni-isa|Istruzioni ISA]]                                                   | <ul><li>#status/finished</li></ul> |
| [[modalita-di-indirizzamento|Modalità di indirizzamento]]                           | <ul><li>#status/finished</li></ul> |
| [[dff-latch|DFF Latch]]                                                             | <ul><li>#status/finished</li></ul> |
| [[frammentazione-esterna|Frammentazione esterna]]                                   | <ul><li>#status/finished</li></ul> |
| [[multiplexer|Multiplexer]]                                                         | <ul><li>#status/finished</li></ul> |
| [[compilazione-a-2-livelli|Compilazione a 2 livelli]]                               | <ul><li>#status/finished</li></ul> |
| [[isa|ISA]]                                                                         | <ul><li>#status/finished</li></ul> |
| [[array-computer|Array computer]]                                                   | <ul><li>#status/finished</li></ul> |
| [[circuiti-sequenziali|Circuiti sequenziali]]                                       | <ul><li>#status/finished</li></ul> |
| [[pc|PC]]                                                                           | <ul><li>#status/finished</li></ul> |
| [[cisc-e-risc|CISC e RISC]]                                                         | <ul><li>#status/finished</li></ul> |
| [[cu|CU]]                                                                           | <ul><li>#status/finished</li></ul> |
| [[bit-di-parita|Bit di parità]]                                                     | <ul><li>#status/finished</li></ul> |
| [[commutazione-al-fronte|Commutazione al fronte]]                                   | <ul><li>#status/finished</li></ul> |
| [[cpu|CPU]]                                                                         | <ul><li>#status/finished</li></ul> |
| [[macchina-multilivello|Macchina multilivello]]                                     | <ul><li>#status/finished</li></ul> |
| [[hdl|HDL]]                                                                         | <ul><li>#status/finished</li></ul> |
| [[sram|SRAM]]                                                                       | <ul><li>#status/finished</li></ul> |
| [[algoritmi-di-paginazione|Algoritmi di paginazione]]                               | <ul><li>#status/finished</li></ul> |
| [[workflow-di-compilazione|Workflow di compilazione]]                               | <ul><li>#status/finished</li></ul> |
| [[hardwaresimulator|HardwareSimulator]]                                             | <ul><li>#status/finished</li></ul> |
| [[dram|DRAM]]                                                                       | <ul><li>#status/finished</li></ul> |
| [[algebra-di-boole|Algebra di Boole]]                                               | <ul><li>#status/finished</li></ul> |
| [[first-fit|First fit]]                                                             | <ul><li>#status/finished</li></ul> |
| [[pla|PLA]]                                                                         | <ul><li>#status/finished</li></ul> |
| [[sr-latch|SR Latch]]                                                               | <ul><li>#status/finished</li></ul> |
| [[full-adder|Full-adder]]                                                           | <ul><li>#status/finished</li></ul> |
| [[cu-hack|CU HACK]]                                                                 | <ul><li>#status/finished</li></ul> |
| [[fifo-paginazione|FIFO paginazione]]                                               | <ul><li>#status/finished</li></ul> |
| [[1-bit-register|1-bit register]]                                                   | <ul><li>#status/finished</li></ul> |
| [[i-o|I-O]]                                                                         | <ul><li>#status/finished</li></ul> |
| [[circuiti-combinatori|Circuiti combinatori]]                                       | <ul><li>#status/finished</li></ul> |
| [[pre-fetch|Pre-fetch]]                                                             | <ul><li>#status/finished</li></ul> |
| [[alu|ALU]]                                                                         | <ul><li>#status/finished</li></ul> |
| [[d-latch|D Latch]]                                                                 | <ul><li>#status/finished</li></ul> |
| [[half-adder|Half-adder]]                                                           | <ul><li>#status/finished</li></ul> |
| [[hd|HD]]                                                                           | <ul><li>#status/finished</li></ul> |
| [[trap|Trap]]                                                                       | <ul><li>#status/finished</li></ul> |
| [[raid|RAID]]                                                                       | <ul><li>#status/finished</li></ul> |
| [[dirty-bit|Dirty bit]]                                                             | <ul><li>#status/finished</li></ul> |
| [[codifica-in-eccesso|Codifica in eccesso]]                                         | <ul><li>#status/finished</li></ul> |
| [[sr-latch-temporizzato|SR Latch temporizzato]]                                     | <ul><li>#status/finished</li></ul> |
| [[distanza-di-hamming|Distanza di Hamming]]                                         | <ul><li>#status/finished</li></ul> |
| [[complemento-a-1|Complemento a 1]]                                                 | <ul><li>#status/finished</li></ul> |
| [[not|NOT]]                                                                         | <ul><li>#status/finished</li></ul> |
| [[modulo-e-segno|Modulo e segno]]                                                   | <ul><li>#status/finished</li></ul> |
| [[best-fit|Best fit]]                                                               | <ul><li>#status/finished</li></ul> |
| [[multicomputer|Multicomputer]]                                                     | <ul><li>#status/finished</li></ul> |
| [[multiprocessori|Multiprocessori]]                                                 | <ul><li>#status/finished</li></ul> |
| [[lru|LRU]]                                                                         | <ul><li>#status/finished</li></ul> |
| [[transistor|Transistor]]                                                           | <ul><li>#status/finished</li></ul> |
| [[architettura-hack|Architettura HACK]]                                             | <ul><li>#status/finished</li></ul> |
| [[frammentazione|Frammentazione]]                                                   | <ul><li>#status/finished</li></ul> |
| [[ssd|SSD]]                                                                         | <ul><li>#status/finished</li></ul> |
| [[cd|CD]]                                                                           | <ul><li>#status/finished</li></ul> |
| [[frammentazione-interna|Frammentazione interna]]                                   | <ul><li>#status/finished</li></ul> |
| [[stack|Stack]]                                                                     | <ul><li>#status/finished</li></ul> |
| [[commutazione-a-livello|Commutazione a livello]]                                   | <ul><li>#status/finished</li></ul> |
| [[principio-di-astrazione-implementazione|Principio di astrazione-implementazione]] | <ul><li>#status/finished</li></ul> |
| [[memoria-virtuale|Memoria virtuale]]                                               | <ul><li>#status/finished</li></ul> |
| [[conversione-binario-ottale-esadecimale|Conversione binario-ottale-esadecimale]]   | <ul><li>#status/finished</li></ul> |
| [[multicore|Multicore]]                                                             | <ul><li>#status/finished</li></ul> |
| [[tabella-di-verita|Tabella di verità]]                                             | <ul><li>#status/finished</li></ul> |
| [[defrag|Defrag]]                                                                   | <ul><li>#status/finished</li></ul> |
| [[parallelismo|Parallelismo]]                                                       | <ul><li>#status/finished</li></ul> |
| [[compilazione-diretta|Compilazione diretta]]                                       | <ul><li>#status/finished</li></ul> |
| [[circuiti-digitali|Circuiti digitali]]                                             | <ul><li>#status/finished</li></ul> |
| [[w-bit-register|w-bit register]]                                                   | <ul><li>#status/finished</li></ul> |
| [[virtual-machine|Virtual machine]]                                                 | <ul><li>#status/finished</li></ul> |
| [[porte-logiche|Porte logiche]]                                                     | <ul><li>#status/finished</li></ul> |
| [[gpu|GPU]]                                                                         | <ul><li>#status/finished</li></ul> |
| [[adder|Adder]]                                                                     | <ul><li>#status/finished</li></ul> |
<!-- SerializedQuery END -->

## Referenze
- [virtuale](https://virtuale.unibo.it/course/view.php?id=53548)
- [dynamik](https://dynamik.vercel.app/architettura-degli-elaboratori)