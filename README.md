# hex game in c rule-based ai

## Assignment Description
Implementation of the Hex Board Game in C with a Rule-Based Computer Opponent

A command-line version of the board game Hex, where a human plays against the computer
on an N × N board of hexagons. Each player tries to connect their two opposite sides of
the board with a continuous chain of their own tiles. It supports:

- Board drawn in ASCII art with column letters (A, B, C, ...) and row numbers
  (1, 2, 3, ...), for sizes up to 26 × 26
- Command-line options for board size (`-n <size>`), difficulty (`-d <difficulty>`),
  player color (`-b`) and enabling the swap rule (`-s`)
- In-game commands: `newgame`, `play <move>` (e.g. `play E4`), `cont` (computer's turn),
  `undo`, `swap`, `showstate`, `save <file>`, `load <file>` and `quit`
- A basic version of the swap rule, where the opening move is mirrored across the
  diagonal (e.g. `D2` becomes `B4`)
- Saving and loading games in a binary file (board size, player to move, and the
  board contents row by row)
- Undo of the last moves using a linked list that keeps the move history

The computer opponent is rule-based: its first move is random and after that it tries
to place a tile on a free hexagon next to its first tile, checking the neighbors in a
fixed order.

## Compilation and Execution
```bash
a) Open linux terminal
b) Go to the same directory as the files 
c) Type
	1. gcc -c hex.c lists.c prints.c
	2. gcc -o run hex.o lists.o prints.o
	3. ./run <command line arguments>
	4. give as input newgame <arguments> or load <file>
	5. Play the game
```

## Known Limitations
- The program does not detect the winner of the game
- The `suggest` and `level` commands are not implemented, and the difficulty level
  does not affect the computer's play
- The computer opponent stops placing tiles after its first few moves
- `newgame` and `load` are only accepted as the first command, and after `save`
  only `quit` is accepted
- The `-b` option and the swap rule do not fully follow the assignment's specification
- Board size is not validated (sizes outside 4–26 are not rejected)

## -Creators - Team
1)EMIL BANTAK 		SDI 1115201800122 <br>
2)GURPREET SINGH VIRDI	SDI 1115201800020
