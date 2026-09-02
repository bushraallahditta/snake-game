🐍 Snake Game in C++
📌 Project Description

This project is a simple Console-Based Snake Game developed in C++ using basic Programming Fundamentals (PF) concepts.

The player controls the snake using L, R, U, and D keys. The goal is to eat the food, increase the snake's length, and achieve the highest possible score without hitting the wall or the snake's own body.

This project was created to practice concepts such as 2D arrays, 1D arrays, loops, conditional statements, random numbers, and basic game logic.

🎮 Game Controls
Key	Movement
L	Move Left
R	Move Right
U	Move Up
D	Move Down
✨ Features
🐍 Snake movement
🍎 Random food generation
📈 Snake growth after eating food
🏆 Score system
🧱 Wall collision detection
💥 Self-collision detection
🎲 Random food placement
🚫 Prevents food from initially appearing on the snake
🖥️ Console-based game board
🎮 Simple keyboard controls
📋 Game start instructions
🧠 Programming Concepts Used

This project uses several fundamental C++ concepts:

1. 2D Arrays

A 2D character array is used to create the game board:

char board[15][40];

The board contains walls, empty spaces, the snake, and the food.

2. 1D Arrays

Two 1D arrays store the positions of the snake:

int snakeR[100];
int snakeC[100];

snakeR stores row positions and snakeC stores column positions.

3. Loops

for loops are used for:

Creating the board
Displaying the board
Moving the snake's body
Checking self-collision
Checking whether food is on the snake

while loops are used for the main game loop and food-position checking.

4. Conditional Statements

if and else if statements control:

Snake movement
Food detection
Wall collision
Self collision
Direction selection
5. Random Number Generation

The <cstdlib> library and rand() function are used to generate random food positions:

foodR = rand() % (row - 2) + 1;
foodC = rand() % (col - 2) + 1;
6. Boolean Variables

The game uses:

bool gameover = false;

to control when the game ends.

Another Boolean variable is used to check whether food has appeared on the snake.

7. File Handling

The current version does not use file handling. It can be added later to save scores or game history.

🕹️ How the Game Works
Step 1 — Create the Board

A 15 × 40 2D array is used as the game board.

The outer boundary is represented by:

####################
#                  #
#                  #
#                  #
####################

# represents the walls.

Step 2 — Create the Snake

The snake's row and column positions are stored in arrays.

The first element:

snakeR[0]
snakeC[0]

represents the snake's head.

Step 3 — Generate Food

Food is represented by:

!

Its position is generated randomly inside the game area.

Step 4 — Move the Snake

The player enters:

L / R / U / D

The snake's body is moved from the last segment toward the head, and then the head moves according to the selected direction.

Step 5 — Eat Food

When the snake's head reaches the food:

if (snakeR[0] == foodR && snakeC[0] == foodC)

the snake grows and the score increases:

snakelength++;
score++;

A new food position is then generated.

Step 6 — Collision Detection

The game ends if the snake hits the wall:

if (snakeR[0] == 0 ||
    snakeR[0] == row - 1 ||
    snakeC[0] == 0 ||
    snakeC[0] == col - 1)
{
    gameover = true;
}

The game also ends if the head touches the snake's body.

💻 Requirements

To run this project, you need:

C++ compiler
Code::Blocks, Dev-C++, Visual Studio, VS Code, or another C++ IDE
Basic command-line/console support
▶️ How to Run
Download or clone the repository.
Open the .cpp file in a C++ IDE.
Compile the program.
Run the program.
Press any key/input to start.
Use L, R, U, and D to control the snake.
Eat ! to increase your score.
Avoid the walls and your own body.
📷 Sample Gameplay
########################################
#                                      #
#          **                           #
#                                      #
#                    !                 #
#                                      #
#                                      #
########################################

Score: 0
Enter direction (L/R/U/D):
🚀 Future Improvements

The project can be improved by adding:

💾 Save scores using file handling
📜 Game history
🏆 High-score system
⏱️ Increasing snake speed
🎨 Better console interface
🔊 Sound effects
⏸️ Pause functionality
🔄 Restart option
🚫 Prevent food from appearing on the snake every time new food is generated
🎯 Difficulty levels
📚 Learning Outcome

Through this project, I practiced and improved my understanding of:

C++ programming
Arrays
2D arrays
Loops
Conditional statements
Boolean logic
Random number generation
Coordinate-based movement
Collision detection
Basic game development logic
👩‍💻 Author

Bushra Ahmad

A Programming Fundamentals project developed in C++ as a step toward learning game development and problem-solving through programming.

⭐ Conclusion

The Snake Game is a beginner-friendly C++ project that demonstrates how basic Programming Fundamentals concepts can be combined to create an interactive console game.

It provides a practical way to understand arrays, loops, conditions, coordinates, random numbers, and game logic while building a fun project.
