# VMtranslator - Progetto Bonus

**Autore:** Andrea Manzo  

Traduttore **VM → Assembly Hack** per il **Progetto Bonus** del corso di Architettura degli Elaboratori.

Il programma accetta in input **un singolo file `.vm`** oppure **una directory** contenente più file `.vm` e produce un file di output **`.asm`** pronto per l’assembler/simulatore Hack.

Di default include automaticamente anche i file dell’**OS** (cartella `./OS/`), utile per eseguire programmi VM che utilizzano le funzioni fornite dal Sistema Operativo Hack. È possibile disabilitare questa funzione con la flag `--no-os` (vedi sotto).

---

## Build (Makefile)

Compilazione:

```bash
make
```

L’eseguibile generato è:

```text
./VMtranslator
```

---

## Uso

```bash
./VMtranslator <file.vm | directory> [--no-os]
```

- **`<file.vm>`**: traduce un singolo file VM
- **`<directory>`**: traduce tutti i `.vm` dentro la directory
- **`--no-os`**: disabilita l’inclusione automatica dei file OS (`./OS/`)

Esempi:

```bash
./VMtranslator SimpleSnake/Main.vm
./VMtranslator SimpleSnake/
./VMtranslator SimpleSnake/ --no-os
```

---

## Output

Il nome dell’output viene generato automaticamente:

- Se l’input è un **file** `path/file.vm` → output `path/file.asm`
- Se l’input è una **directory** `path/Prog/` → output `path/Prog/Prog.asm`  
  (il file `.asm` viene creato **dentro** la directory, con lo stesso nome della cartella)

---


## Errori

In caso di errori di apertura/lettura/scrittura, o **errori di compilazione** (errori nei file `.vm`) il programma stampa un messaggio esplicativo su `stderr` e termina con codice di uscita diverso da 0.

## Programmi in linguaggio VM

Nel repository sono presenti due programmi scritti in linguaggio VM:

- `HelloWorld`:  un classico e immancabile Hello World!
- `SimpleSnake`: un semplice gioco Snake (più informazioni nel `README.md` all'interno della cartella).