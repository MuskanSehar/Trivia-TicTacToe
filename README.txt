================================================================
  QUIZ TIC-TAC-TOE
  A trivia-based Tic-Tac-Toe game built with SFML (C++)
================================================================

DESCRIPTION
-----------
Quiz Tic-Tac-Toe is a two-mode, graphical Tic-Tac-Toe game
where players must answer a trivia question correctly before
they can place their mark (X or O) on the board. Answer wrong
and your turn is skipped — giving your opponent the edge!

The game features a pastel "cute" aesthetic with animated
clouds, flowers, stars, balloons, and hearts drawn entirely
with SFML shapes (no external images needed).


FEATURES
--------
  - 1 Player mode    : Play against a computer AI
  - 2 Player mode    : Play against a friend on the same PC
  - Fun Mode         : 60 riddles and Desi humour questions
  - Academic Mode    : 60 Physics / C++ / General Science Qs
  - No-repeat Qs     : Questions are removed after use; the
                       pool reloads only when exhausted
  - Custom names     : Enter names up to 12 characters each
  - Pastel UI        : Cute decorative graphics on every screen
  - Hover effects    : Buttons highlight on mouse-over
  - Clean reset      : "Play Again" returns to the main menu


GAME STATES
-----------
  0 - Main Menu        (choose 1 or 2 player)
  1 - Mode Select      (Fun or Academic)
  2 - Name Entry       (type custom player names)
  3 - Game Board       (click a cell to trigger a question)
  4 - Question Popup   (answer A / B / C)
  5 - Game Over        (winner or draw announced)


HOW TO PLAY
-----------
  1. Launch the game.
  2. Choose 1 Player (vs AI) or 2 Players.
  3. Select Fun Mode or Academic Mode.
  4. Enter player name(s) and press Start Game.
  5. Click any empty cell on the board.
  6. A trivia question pops up — pick the right answer.
     - Correct  → your marker (X or O) is placed.
     - Wrong    → turn passes to the other player.
  7. First to get 3 in a row wins. Fill all 9 cells = Draw.
  8. Press "Play Again" to return to the main menu.


REQUIREMENTS
------------
  - C++17 (or later) compiler
  - SFML 2.5.x  (Simple and Fast Multimedia Library)
  - A font file in the same folder as the executable:
      • Roboto-Regular.ttf   (preferred)
      • arial.ttf            (fallback)


BUILDING THE PROJECT
--------------------
Make sure SFML is installed and visible to your compiler.

  g++ quiz_tictactoe.cpp -o quiz_tictactoe \
      -lsfml-graphics -lsfml-window -lsfml-system

  OR with full SFML path (Windows example):
  g++ quiz_tictactoe.cpp -o quiz_tictactoe.exe \
      -I"C:/SFML/include" -L"C:/SFML/lib" \
      -lsfml-graphics -lsfml-window -lsfml-system

For Code::Blocks / Visual Studio, add SFML to your project
linker settings and copy the SFML DLLs next to the .exe.


FONT SETUP
----------
The game tries to load "Roboto-Regular.ttf" first, then
"arial.ttf". Place either file in the same directory as
the compiled executable.

Download Roboto for free from:
  https://fonts.google.com/specimen/Roboto


FILE STRUCTURE
--------------
  quiz_tictactoe.cpp      Main source file (entire game)
  Roboto-Regular.ttf      Font (you must supply this)
  README.txt              This file


PROJECT INFO
------------
  Course    : [Your Course Name]
  Semester  : 1
  Author    : [Your Name]
  Institute : [Your Institute]
  Year      : [Year]


LICENSE
-------
This project was created for educational purposes.
Feel free to fork, modify, and share it.

================================================================
