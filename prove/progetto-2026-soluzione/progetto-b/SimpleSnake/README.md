# Simple Snake

**Autore:** Andrea Manzo  

Progetto VM / Hack che implementa un semplice gioco Snake.

## Contenuto della cartella

- **`*.txt`**  
  Contengono lo **pseudocodice** usato come base/progetto iniziale.

- **`*.vm`**  
  Contengono il **codice VM** eseguibile.


## Come funziona

Il gioco implementa un **semplice Snake**:
- controlli il serpente con le **frecce** della tastiera
- se il serpente **sbatte contro un bordo**, hai perso e la partita termina

## Dove testarlo

Si consiglia di testarlo direttamente sull’IDE online di nand2tetris (più comodo e spesso più fluido per input/visualizzazione):

https://nand2tetris.github.io/web-ide/vm

### Impostazioni per testarlo
- Nell’IDE online: imposta la **velocità al massimo**.
- Se usi `VMEmulator.sh`: attiva **No animation**.
- In entrami i casi impostare **Enable Keyboard**

## Dipendenze / OS

Il codice usa funzioni dell’**OS di nand2tetris** (es. `Screen`, `Keyboard`, `Sys`, `Memory`, `Array`, …).  
Non sono incluse nel repository perché **sono già disponibili di default** nell’ambiente/compilatore.
