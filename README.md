# Quiz Tic-Tac-Toe

A trivia-based twist on Tic-Tac-Toe, built with **C++** and **SFML**. Before placing your mark, you have to answer a question correctly — get it wrong, and your turn is skipped.

All visuals — clouds, flowers, stars, balloons, hearts — are drawn directly with SFML shapes. No external image assets.

---

## Features

- **1 Player mode** — play against a simple computer AI
- **2 Player mode** — play against a friend on the same machine
- **Two question sets:**
  - **Fun Mode** — 60 riddles and lighthearted questions
  - **Academic Mode** — 60 Physics / C++ / general science questions
- **No repeat questions** — each question is removed from the pool after use; the pool only reloads once exhausted
- **Custom player names** (up to 12 characters each)
- **Pastel, hand-drawn UI** with hover effects on buttons
- **Clean reset** — "Play Again" returns straight to the main menu

---

## How it works

The game moves through six states:

| State | Screen |
|---|---|
| 0 | Main Menu — choose 1 or 2 player |
| 1 | Mode Select — Fun or Academic |
| 2 | Name Entry — type in player name(s) |
| 3 | Game Board — click a cell to trigger a question |
| 4 | Question Popup — answer A / B / C |
| 5 | Game Over — winner or draw announced |

**To play:**
1. Choose 1 Player or 2 Players
2. Pick Fun Mode or Academic Mode
3. Enter player name(s) and start
4. Click any empty cell — answering correctly places your mark (X or O); answering wrong skips your turn
5. First to get 3 in a row wins. A full board with no winner is a draw.
6. Hit "Play Again" to return to the main menu

---

## Built with

- C++17
- [SFML 2.5.x](https://www.sfml-dev.org/) — graphics, window, and input handling

---

## Getting started

### Requirements
- A C++17 (or later) compiler
- SFML 2.5.x installed
- A font file in the same folder as the executable — either:
  - `Roboto-Regular.ttf` (preferred), or
  - `arial.ttf` (fallback)

  Roboto can be downloaded for free from [Google Fonts](https://fonts.google.com/specimen/Roboto).

### Build (macOS/Linux)

```bash
g++ quiz_tictactoe.cpp -o quiz_tictactoe \
    -lsfml-graphics -lsfml-window -lsfml-system
```

### Build (Windows)

```bash
g++ quiz_tictactoe.cpp -o quiz_tictactoe.exe \
    -I"C:/SFML/include" -L"C:/SFML/lib" \
    -lsfml-graphics -lsfml-window -lsfml-system
```

For Code::Blocks or Visual Studio, add SFML to your project's linker settings and copy the SFML DLLs next to the built executable.

### Run

Make sure the font file is in the same folder as the executable, then run it:

```bash
./quiz_tictactoe
```

---

## File structure

```
quiz_tictactoe.cpp      # Main source file (entire game)
Roboto-Regular.ttf      # Font (must be supplied separately)
README.md
```

---

## Credits

Built by [Muskan Sehar](https://github.com/MuskanSehar) — a classmate collaboration, with co-author credits to follow once they're on GitHub.

---

## License

Created for educational purposes. Feel free to fork, modify, and share it.
