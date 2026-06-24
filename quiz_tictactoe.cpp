// ============================================================
//  QUIZ TIC-TAC-TOE  —  SFML 3.0 compatible
//  A trivia-based Tic-Tac-Toe game built with SFML
//  Author  : [Your Name]
//  Semester: 1  |  Course: [Your Course]
// ============================================================

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>

using namespace std;
using namespace sf;

// ============================================================
//  1. CONFIGURATION & THEME
// ============================================================

const int SCREEN_W = 900;
const int SCREEN_H = 700;

const Color BG_COLOR          = Color(255, 250, 245);
const Color TEXT_COLOR        = Color( 70,  60,  80);
const Color ACCENT_LILAC      = Color(200, 162, 200);
const Color ACCENT_PINK       = Color(255, 182, 193);
const Color ACCENT_BLUE       = Color(173, 216, 230);
const Color ACCENT_PEACH      = Color(255, 218, 185);
const Color ACCENT_PERIWINKLE = Color(150, 170, 255);
const Color ACCENT_YELLOW     = Color(255, 253, 150);
const Color GRID_COLOR        = Color(160, 140, 150);
const Color HEART_RED         = Color(255, 120, 120);

// ============================================================
//  2. DATA STRUCTURES
// ============================================================

struct Question {
    string prompt;
    string optionA;
    string optionB;
    string optionC;
    char   correctOption;
};

// ============================================================
//  3. GLOBAL STATE
// ============================================================

char   boardLogic[3][3];
char   currentMarker;
int    currentPlayer;
string player1Name;
string player2Name;
bool   isSinglePlayer;
bool   isFunMode;
int    winner;
int    turnCount;

vector<Question> funQuestions;
vector<Question> academicQuestions;
Question         currentQuestion;

// ============================================================
//  4. QUESTION DATA
// ============================================================

void loadQuestions()
{
    funQuestions.clear();
    academicQuestions.clear();

    // ---- ACADEMIC MODE ----
    academicQuestions.push_back({ "What is the SI unit of Force?",            "Joule",      "Newton",       "Watt",           'b' });
    academicQuestions.push_back({ "In C++, what ends a statement?",           "Period (.)", "Colon (:)",    "Semicolon (;)",  'c' });
    academicQuestions.push_back({ "Value of 'g' on Earth?",                   "9.8 m/s^2",  "10.5 m/s^2",  "8.9 m/s^2",     'a' });
    academicQuestions.push_back({ "Kinetic Energy formula?",                  "mv",         "1/2 mv^2",    "mgh",            'b' });
    academicQuestions.push_back({ "Ohm's Law?",                               "V=IR",       "F=ma",         "E=mc^2",         'a' });
    academicQuestions.push_back({ "cout is found in which library?",          "stdio.h",    "iostream",     "conio.h",        'b' });
    academicQuestions.push_back({ "Unit of electric charge?",                 "Ampere",     "Coulomb",      "Volt",           'b' });
    academicQuestions.push_back({ "Density formula?",                         "Mass/Vol",   "Vol/Mass",     "Mass*Vol",       'a' });
    academicQuestions.push_back({ "X-rays were discovered by?",               "Curie",      "Roentgen",     "Newton",         'b' });
    academicQuestions.push_back({ "Constructor name must match?",             "Class",      "Object",       "Main",           'a' });
    academicQuestions.push_back({ "Unit of Power?",                           "Joule",      "Watt",         "Newton",         'b' });
    academicQuestions.push_back({ "Protons carry what charge?",               "Positive",   "Negative",     "Neutral",        'a' });
    academicQuestions.push_back({ "Atomic theory proposed by?",               "Dalton",     "Bohr",         "Rutherford",     'a' });
    academicQuestions.push_back({ "Who invented C++?",                        "Stroustrup", "Gosling",      "Ritchie",        'a' });
    academicQuestions.push_back({ "pH of pure water?",                        "7",          "0",            "14",             'a' });
    academicQuestions.push_back({ "DNA shape is called?",                     "Helix",      "Spiral",       "Circle",         'a' });
    academicQuestions.push_back({ "Area of a circle?",                        "2*pi*r",     "pi*r^2",       "l*w",            'b' });
    academicQuestions.push_back({ "Powerhouse of the cell?",                  "Nucleus",    "Mitochondria", "Ribosome",       'b' });
    academicQuestions.push_back({ "C++ keyword for integer?",                 "int",        "float",        "char",           'a' });
    academicQuestions.push_back({ "Newton's First Law is?",                   "Gravity",    "Inertia",      "Action-Reaction",'b' });
    academicQuestions.push_back({ "Array index starts at?",                   "1",          "0",            "-1",             'b' });
    academicQuestions.push_back({ "Symbol for a pointer?",                    "&",          "*",            "#",              'b' });
    academicQuestions.push_back({ "Speed of sound is fastest in?",            "Air",        "Water",        "Steel",          'c' });
    academicQuestions.push_back({ "C++ single-line comment?",                 "//",         "||",           "--",             'a' });
    academicQuestions.push_back({ "Nature of light?",                         "Wave",       "Particle",     "Both",           'c' });
    academicQuestions.push_back({ "Function for exponentiation in C++?",      "pow()",      "sqrt()",       "abs()",          'a' });
    academicQuestions.push_back({ "Boolean stores?",                          "0 and 1",    "True/False",   "Yes/No",         'b' });
    academicQuestions.push_back({ "Modulus operator in C++?",                 "%",          "/",            "*",              'a' });
    academicQuestions.push_back({ "Size of char in C++?",                     "1 byte",     "2 bytes",      "4 bytes",        'a' });
    academicQuestions.push_back({ "Work is a?",                               "Vector",     "Scalar",       "Tensor",         'b' });
    academicQuestions.push_back({ "Mirrors work on?",                         "Refraction", "Reflection",   "Diffraction",    'b' });
    academicQuestions.push_back({ "Best loop for iterating an array?",        "while",      "do-while",     "for",            'c' });
    academicQuestions.push_back({ "string is a?",                             "Primitive",  "Class",        "Function",       'b' });
    academicQuestions.push_back({ "Universal Gravitational Constant?",        "g",          "G",            "k",              'b' });
    academicQuestions.push_back({ "Math header in C++?",                      "cmath",      "math.h",       "Both work",      'c' });
    academicQuestions.push_back({ "Destructor symbol in C++?",                "~",          "!",            "#",              'a' });
    academicQuestions.push_back({ "SI unit of Pressure?",                     "Pascal",     "Joule",        "Watt",           'a' });
    academicQuestions.push_back({ "break is used to?",                        "Exit a loop","Skip iter",    "Print output",   'a' });
    academicQuestions.push_back({ "Variable type for decimals?",              "int",        "double",       "char",           'b' });
    academicQuestions.push_back({ "Human eye uses which lens?",               "Convex",     "Concave",      "Flat",           'a' });
    academicQuestions.push_back({ "Derived unit example?",                    "Meter",      "Second",       "Newton",         'c' });
    academicQuestions.push_back({ "cin is used for?",                         "Output",     "Input",        "Error",          'b' });
    academicQuestions.push_back({ "Isotopes have same number of?",            "Neutrons",   "Protons",      "Electrons",      'b' });
    academicQuestions.push_back({ "Increment operator in C++?",               "++",         "+=",           "+",              'a' });
    academicQuestions.push_back({ "Refractive index of air?",                 "1.0",        "1.5",          "1.33",           'a' });
    academicQuestions.push_back({ "Private members accessible by?",           "Class only", "Public",       "Global",         'a' });
    academicQuestions.push_back({ "Free-fall acceleration depends on?",       "Mass",       "Shape",        "Neither",        'c' });
    academicQuestions.push_back({ "switch-case checks for?",                  "Equality",   "Range",        "Logic",          'a' });
    academicQuestions.push_back({ "Shortest wavelength radiation?",           "Radio",      "Gamma",        "Micro",          'b' });
    academicQuestions.push_back({ "const keyword means?",                     "Constant",   "Changeable",   "Static",         'a' });
    academicQuestions.push_back({ "Plants absorb which gas?",                 "O2",         "CO2",          "N2",             'b' });
    academicQuestions.push_back({ "Hardest natural substance?",               "Gold",       "Diamond",      "Iron",           'b' });
    academicQuestions.push_back({ "Planet closest to the Sun?",               "Venus",      "Mercury",      "Mars",           'b' });
    academicQuestions.push_back({ "Equality comparison operator?",            "=",          "==",           "===",            'b' });
    academicQuestions.push_back({ "Bits in one byte?",                        "8",          "16",           "32",             'a' });
    academicQuestions.push_back({ "Which is a logic gate?",                   "AND",        "IF",           "LOOP",           'a' });
    academicQuestions.push_back({ "First element on periodic table?",         "H",          "He",           "Li",             'a' });
    academicQuestions.push_back({ "Boiling point of water (Celsius)?",        "100 C",      "90 C",         "110 C",          'a' });
    academicQuestions.push_back({ "Which planet has prominent rings?",        "Saturn",     "Mars",         "Earth",          'a' });
    academicQuestions.push_back({ "Study of fungi is called?",                "Mycology",   "Biology",      "Zoology",        'a' });

    // ---- FUN MODE ----
    funQuestions.push_back({ "What has keys but no locks?",                       "Piano",              "Map",              "Banana",              'a' });
    funQuestions.push_back({ "Desi mother's ultimate weapon?",                    "Logic",              "Chappal",          "Silence",             'b' });
    funQuestions.push_back({ "Gabbar Singh's famous question?",                   "Kitne aadmi the?",   "Khana khaya?",     "Wifi hai?",           'a' });
    funQuestions.push_back({ "A desi cure for every problem?",                    "Water",              "Chai",             "Juice",               'b' });
    funQuestions.push_back({ "National bird of desi parents?",                    "Peacock",            "Sharmaji ka Beta", "Parrot",              'b' });
    funQuestions.push_back({ "Common desi time unit?",                            "1 min",              "2 mins",           "5 mins (= 1 hr)",     'c' });
    funQuestions.push_back({ "Who is Daya's boss?",                               "ACP Pradyuman",      "Jethalal",         "Mogambo",             'a' });
    funQuestions.push_back({ "Famous: 'Jaa Simran...'",                           "Jaa!",               "So ja",            "Jee le apni zindagi", 'c' });
    funQuestions.push_back({ "Jethalal's neighbour/crush?",                       "Daya",               "Babita ji",        "Anjali",              'b' });
    funQuestions.push_back({ "Opposite of 'Desi'?",                               "Videshi",            "City",             "Modern",              'a' });
    funQuestions.push_back({ "A bank that holds no money?",                       "River bank",         "Blood bank",       "Piggy bank",          'a' });
    funQuestions.push_back({ "Gets wetter as it dries?",                          "Towel",              "Sponge",           "Rain",                'a' });
    funQuestions.push_back({ "Catch but not throw?",                              "Cold",               "Ball",             "Rock",                'a' });
    funQuestions.push_back({ "Goes up but never comes down?",                     "Age",                "Elevator",         "Rocket",              'a' });
    funQuestions.push_back({ "Has an eye but cannot see?",                        "Needle",             "Potato",           "Storm",               'a' });
    funQuestions.push_back({ "Has legs but cannot walk?",                         "Table",              "Chair",            "Pants",               'a' });
    funQuestions.push_back({ "Full of holes but holds water?",                    "Sponge",             "Bucket",           "Net",                 'a' });
    funQuestions.push_back({ "Breaks when you say its name?",                     "Silence",            "Glass",            "Plate",               'a' });
    funQuestions.push_back({ "First thing a desi guest asks?",                    "Water",              "Wifi",             "Food",                'b' });
    funQuestions.push_back({ "Has a neck but no head?",                           "Shirt",              "Bottle",           "Giraffe",             'b' });
    funQuestions.push_back({ "Desi fix for broken electronics?",                  "Hit it",             "Repair shop",      "Buy new",             'a' });
    funQuestions.push_back({ "Tall when young, short when old?",                  "Candle",             "Tree",             "Pencil",              'a' });
    funQuestions.push_back({ "Highest mountain before Everest?",                  "Everest",            "K2",               "Alps",                'a' });
    funQuestions.push_back({ "More you take, more you leave behind?",             "Footsteps",          "Money",            "Food",                'a' });
    funQuestions.push_back({ "Runs but never walks?",                             "River",              "Car",              "Nose",                'a' });
    funQuestions.push_back({ "Kangaroo jump higher than a house?",                "Yes",                "No",               "Maybe",               'a' });
    funQuestions.push_back({ "One head, four legs?",                              "Bed",                "Table",            "Chair",               'a' });
    funQuestions.push_back({ "Classic desi greeting?",                            "Aur sunao?",         "Hello",            "Bye",                 'a' });
    funQuestions.push_back({ "White stone in the Red Sea becomes?",               "Wet",                "Red",              "It sinks",            'a' });
    funQuestions.push_back({ "Has teeth but cannot bite?",                        "Comb",               "Saw",              "Zipper",              'a' });
    funQuestions.push_back({ "Always comes down, never goes up?",                 "Rain",               "Snow",             "Leaves",              'a' });
    funQuestions.push_back({ "Why did the skeleton skip the party?",              "No body to go with", "Too scared",       "Too busy",            'a' });
    funQuestions.push_back({ "Jerry's favourite snack?",                          "Cheese",             "Cake",             "Pizza",               'a' });
    funQuestions.push_back({ "Has cities but no houses?",                         "Map",                "Globe",            "Book",                'a' });
    funQuestions.push_back({ "Black when clean, white when dirty?",               "Blackboard",         "Car",              "Shoe",                'a' });
    funQuestions.push_back({ "Movie with 'All is Well'?",                         "3 Idiots",           "PK",               "Dangal",              'a' });
    funQuestions.push_back({ "Travels the world in a corner?",                    "Stamp",              "Bug",              "Dust",                'a' });
    funQuestions.push_back({ "Has words but cannot speak?",                       "Book",               "Phone",            "Radio",               'a' });
    funQuestions.push_back({ "Which month has 28 days?",                          "All of them",        "February",         "January",             'a' });
    funQuestions.push_back({ "Lose it when you stand up?",                        "Lap",                "Balance",          "Seat",                'a' });
    funQuestions.push_back({ "2 company, 3 crowd, 4+5?",                          "9",                  "A party",          "A crowd",             'a' });
    funQuestions.push_back({ "Has towns but nothing moves?",                      "Road",               "River",            "Train",               'a' });
    funQuestions.push_back({ "Classic desi parent dialogue?",                     "Log kya kahenge",    "Good job beta",    "Relax karo",          'a' });
    funQuestions.push_back({ "Cat eats a lemon?",                                 "Sourpuss",           "Sick cat",         "Happy cat",           'a' });
    funQuestions.push_back({ "Letter that sounds like water?",                    "C",                  "W",                "O",                   'a' });
    funQuestions.push_back({ "See through a wall?",                               "Window",             "X-ray",            "Glass",               'a' });
    funQuestions.push_back({ "13 hearts but no organs?",                          "Deck of cards",      "Octopus",          "Love story",          'a' });
    funQuestions.push_back({ "Why don't scientists trust atoms?",                 "Make up everything", "They're small",    "They're smart",       'a' });
    funQuestions.push_back({ "Building with the most stories?",                   "Library",            "Skyscraper",       "House",               'a' });
    funQuestions.push_back({ "Can't use until you break it?",                     "Egg",                "Glow stick",       "Pinata",              'a' });
    funQuestions.push_back({ "Always follows but never copies?",                  "Shadow",             "Ghost",            "Cat",                 'a' });
    funQuestions.push_back({ "Has hands but can't clap?",                         "Clock",              "Doll",             "Robot",               'a' });
    funQuestions.push_back({ "Has only one eye?",                                 "Needle",             "Cyclops",          "Storm",               'a' });
    funQuestions.push_back({ "Letter that is a hot drink?",                       "T",                  "C",                "P",                   'a' });
    funQuestions.push_back({ "Can't talk but always replies?",                    "Echo",               "Phone",            "Mirror",              'a' });
    funQuestions.push_back({ "Runs around yard but never moves?",                 "Fence",              "Dog",              "Hose",                'a' });
    funQuestions.push_back({ "Has a ring but no finger?",                         "Telephone",          "Bell",             "Saturn",              'a' });
    funQuestions.push_back({ "Head and tail but no body?",                        "Coin",               "Snake",            "Worm",                'a' });
    funQuestions.push_back({ "Breakfast & dinner but never lunch?",               "Breakfast",          "A nap",            "A feast",             'a' });
}

// ============================================================
//  5. LOGIC HELPERS
// ============================================================

void resetGame()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            boardLogic[i][j] = (char)('1' + i * 3 + j);
    currentMarker = 'X';
    currentPlayer = 1;
    winner        = 0;
    turnCount     = 0;
}

void getNextQuestion()
{
    vector<Question>* pool = isFunMode ? &funQuestions : &academicQuestions;
    if (pool->empty()) {
        loadQuestions();
        pool = isFunMode ? &funQuestions : &academicQuestions;
    }
    int idx = rand() % pool->size();
    currentQuestion = pool->at(idx);
    pool->erase(pool->begin() + idx);
}

int checkWinCondition()
{
    for (int i = 0; i < 3; i++) {
        if (boardLogic[i][0] == boardLogic[i][1] && boardLogic[i][1] == boardLogic[i][2]) return currentPlayer;
        if (boardLogic[0][i] == boardLogic[1][i] && boardLogic[1][i] == boardLogic[2][i]) return currentPlayer;
    }
    if (boardLogic[0][0] == boardLogic[1][1] && boardLogic[1][1] == boardLogic[2][2]) return currentPlayer;
    if (boardLogic[0][2] == boardLogic[1][1] && boardLogic[1][1] == boardLogic[2][0]) return currentPlayer;
    return 0;
}

// ============================================================
//  6. DECORATIVE GRAPHICS
//  SFML 3.0: setPosition takes Vector2f{x,y} not two floats
// ============================================================

void drawStar(RenderWindow& win, float x, float y, float size, Color c)
{
    ConvexShape star;
    star.setPointCount(10);
    star.setFillColor(c);
    star.setPosition({x, y});
    for (int i = 0; i < 10; i++) {
        float angle  = i * 2.f * 3.14159f / 10.f - 3.14159f / 2.f;
        float radius = (i % 2 == 0) ? size : size / 2.f;
        star.setPoint(i, {cosf(angle) * radius, sinf(angle) * radius});
    }
    win.draw(star);
}

void drawCloud(RenderWindow& win, float x, float y)
{
    Color shadowCol(210, 220, 235);
    CircleShape s1(30), s2(40), s3(25), s4(30);
    s1.setFillColor(shadowCol); s2.setFillColor(shadowCol);
    s3.setFillColor(shadowCol); s4.setFillColor(shadowCol);
    s1.setPosition({x + 4,  y + 14}); s2.setPosition({x + 34, y + 4});
    s3.setPosition({x + 84, y + 14}); s4.setPosition({x + 64, y - 6});
    win.draw(s1); win.draw(s2); win.draw(s3); win.draw(s4);

    Color cloudCol(255, 255, 255);
    CircleShape c1(30), c2(40), c3(25), c4(30);
    c1.setFillColor(cloudCol); c2.setFillColor(cloudCol);
    c3.setFillColor(cloudCol); c4.setFillColor(cloudCol);
    c1.setPosition({x,      y + 10}); c2.setPosition({x + 30, y});
    c3.setPosition({x + 80, y + 10}); c4.setPosition({x + 60, y - 10});
    win.draw(c1); win.draw(c2); win.draw(c3); win.draw(c4);
}

void drawHeart(RenderWindow& win, float x, float y, float size)
{
    CircleShape c1(size / 2), c2(size / 2);
    ConvexShape tri;
    c1.setFillColor(HEART_RED); c2.setFillColor(HEART_RED);
    c1.setPosition({x, y}); c2.setPosition({x + size * 0.9f, y});
    tri.setFillColor(HEART_RED);
    tri.setPointCount(3);
    tri.setPoint(0, {x,                y + size / 2.f});
    tri.setPoint(1, {x + size * 1.9f,  y + size / 2.f});
    tri.setPoint(2, {x + size * 0.95f, y + size * 1.8f});
    win.draw(c1); win.draw(c2); win.draw(tri);
}

void drawBalloon(RenderWindow& win, float x, float y, Color c)
{
    RectangleShape stringLine({2, 50});
    stringLine.setFillColor(Color::Black);
    stringLine.setPosition({x + 24, y + 55});
    win.draw(stringLine);

    CircleShape b(30);
    b.setFillColor(c); b.setPosition({x, y});
    b.setOutlineColor(Color::White); b.setOutlineThickness(2);
    win.draw(b);

    ConvexShape knot;
    knot.setPointCount(3); knot.setFillColor(c);
    knot.setPoint(0, {x + 25, y + 58});
    knot.setPoint(1, {x + 20, y + 65});
    knot.setPoint(2, {x + 30, y + 65});
    win.draw(knot);

    CircleShape shine(6);
    shine.setFillColor(Color(255, 255, 255, 180));
    shine.setPosition({x + 10, y + 10});
    win.draw(shine);
}

void drawPencil(RenderWindow& win, float x, float y)
{
    RectangleShape body({20, 50});
    body.setFillColor(ACCENT_YELLOW);
    body.setPosition({x, y});
    body.setOutlineColor(TEXT_COLOR); body.setOutlineThickness(2);
    win.draw(body);

    ConvexShape tip;
    tip.setPointCount(3); tip.setFillColor(TEXT_COLOR);
    tip.setPoint(0, {x,      y});
    tip.setPoint(1, {x + 20, y});
    tip.setPoint(2, {x + 10, y - 15});
    win.draw(tip);

    RectangleShape eraser({20, 10});
    eraser.setFillColor(ACCENT_PINK);
    eraser.setPosition({x, y + 50});
    eraser.setOutlineColor(TEXT_COLOR); eraser.setOutlineThickness(2);
    win.draw(eraser);
}

void drawFlower(RenderWindow& win, float x, float y, Color petalColor)
{
    for (int i = 0; i < 6; i++) {
        float angle = i * 60.f * 3.14159f / 180.f;
        CircleShape petal(10);
        petal.setFillColor(petalColor);
        petal.setPosition({x + cosf(angle) * 12.f, y + sinf(angle) * 12.f});
        win.draw(petal);
    }
    CircleShape center(8);
    center.setFillColor(ACCENT_YELLOW);
    center.setPosition({x + 2, y + 2});
    win.draw(center);
}

// ============================================================
//  7. CUTEBUTTON CLASS
//  SFML 3.0: Text constructor requires font reference
// ============================================================

class CuteButton {
public:
    RectangleShape shape;
    Text           text;
    Color          baseColor;
    Color          hoverColor;

    // SFML 3.0: Text must be initialized with a font
    CuteButton(float x, float y, float w, float h,
               const string& str, Font& font, Color col)
        : text(font, str, 22)
    {
        baseColor  = col;
        hoverColor = Color(min(255, (int)col.r + 30),
                          min(255, (int)col.g + 30),
                          min(255, (int)col.b + 30));

        shape.setPosition({x, y});
        shape.setSize({w, h});
        shape.setFillColor(baseColor);
        shape.setOutlineColor(Color::White);
        shape.setOutlineThickness(3);

        text.setFillColor(TEXT_COLOR);
        centerText();
    }

    void setText(const string& s) { text.setString(s); centerText(); }

    void update(Vector2i mousePos)
    {
        if (shape.getGlobalBounds().contains({(float)mousePos.x, (float)mousePos.y})) {
            shape.setFillColor(hoverColor);
            shape.setOutlineColor(ACCENT_LILAC);
        } else {
            shape.setFillColor(baseColor);
            shape.setOutlineColor(Color::White);
        }
    }

    bool isClicked(Vector2i mousePos) const
    {
        return shape.getGlobalBounds().contains({(float)mousePos.x, (float)mousePos.y});
    }

    void draw(RenderWindow& win) { win.draw(shape); win.draw(text); }

private:
    void centerText()
    {
        FloatRect r = text.getLocalBounds();
        text.setOrigin({r.position.x + r.size.x / 2.f,
                        r.position.y + r.size.y / 2.f});
        text.setPosition({shape.getPosition().x + shape.getSize().x / 2.f,
                          shape.getPosition().y + shape.getSize().y / 2.f});
    }
};

// ============================================================
//  8. MAIN
// ============================================================

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    loadQuestions();

    RenderWindow window(VideoMode({(unsigned int)SCREEN_W, (unsigned int)SCREEN_H}),
                        "Quiz Tic-Tac-Toe");
    window.setFramerateLimit(60);

    Font font;
    if (!font.openFromFile("Roboto-Regular.ttf"))
        if (!font.openFromFile("arial.ttf"))
            return -1;

    // Buttons
    CuteButton btnOnePlayer(300, 250, 300, 60, "1 Player (vs AI)", font, ACCENT_BLUE);
    CuteButton btnTwoPlayer(300, 330, 300, 60, "2 Players",        font, ACCENT_LILAC);
    CuteButton btnFun      (300, 250, 300, 60, "Fun Mode",         font, ACCENT_PEACH);
    CuteButton btnAcad     (300, 330, 300, 60, "Academic Mode",    font, ACCENT_PERIWINKLE);
    CuteButton btnStart    (300, 450, 300, 60, "Start Game",       font, ACCENT_PINK);
    CuteButton btnOptA     (150, 350, 600, 50, "",                 font, Color::White);
    CuteButton btnOptB     (150, 420, 600, 50, "",                 font, Color::White);
    CuteButton btnOptC     (150, 490, 600, 50, "",                 font, Color::White);
    CuteButton btnReset    (300, 500, 300, 60, "Play Again",       font, ACCENT_LILAC);

    // 0=Menu 1=ModeSelect 2=NameEntry 3=Board 4=QuestionPopup 5=GameOver
    int  state       = 0;
    bool enteringP1  = true;
    int  pendingSlot = -1;

    while (window.isOpen())
    {
        Vector2i mousePos = Mouse::getPosition(window);

        while (auto event = window.pollEvent())
        {
            if (event->is<Event::Closed>())
                window.close();

            // Text input (State 2)
            if (state == 2) {
                if (auto* te = event->getIf<Event::TextEntered>()) {
                    if (te->unicode == '\b') {
                        if ( enteringP1 && !player1Name.empty()) player1Name.pop_back();
                        if (!enteringP1 && !player2Name.empty()) player2Name.pop_back();
                    } else if (te->unicode > 31 && te->unicode < 128) {
                        if ( enteringP1 && player1Name.size() < 12) player1Name += (char)te->unicode;
                        if (!enteringP1 && player2Name.size() < 12) player2Name += (char)te->unicode;
                    }
                }
            }

            // Mouse clicks
            if (auto* mb = event->getIf<Event::MouseButtonPressed>()) {
                if (mb->button == Mouse::Button::Left) {

                    if (state == 0) {
                        if (btnOnePlayer.isClicked(mousePos)) { isSinglePlayer = true;  player2Name = "Computer"; state = 1; }
                        if (btnTwoPlayer.isClicked(mousePos)) { isSinglePlayer = false; state = 1; }
                    }
                    else if (state == 1) {
                        if (btnFun .isClicked(mousePos)) { isFunMode = true;  state = 2; }
                        if (btnAcad.isClicked(mousePos)) { isFunMode = false; state = 2; }
                    }
                    else if (state == 2) {
                        if (btnStart.isClicked(mousePos)) {
                            if (player1Name.empty()) player1Name = "Player 1";
                            if (!isSinglePlayer && player2Name.empty()) player2Name = "Player 2";
                            resetGame(); state = 3;
                        }
                        if (mousePos.y > 200 && mousePos.y < 260) enteringP1 = true;
                        if (mousePos.y > 300 && mousePos.y < 360 && !isSinglePlayer) enteringP1 = false;
                    }
                    else if (state == 3) {
                        if (mousePos.x >= 300 && mousePos.x <= 600 &&
                            mousePos.y >= 150 && mousePos.y <= 450)
                        {
                            int col = (mousePos.x - 300) / 100;
                            int row = (mousePos.y - 150) / 100;
                            if (boardLogic[row][col] != 'X' && boardLogic[row][col] != 'O') {
                                pendingSlot = row * 3 + col;
                                getNextQuestion();
                                btnOptA.setText("A) " + currentQuestion.optionA);
                                btnOptB.setText("B) " + currentQuestion.optionB);
                                btnOptC.setText("C) " + currentQuestion.optionC);
                                state = 4;
                            }
                        }
                    }
                    else if (state == 4) {
                        char ans = ' ';
                        if (btnOptA.isClicked(mousePos)) ans = 'a';
                        if (btnOptB.isClicked(mousePos)) ans = 'b';
                        if (btnOptC.isClicked(mousePos)) ans = 'c';

                        if (ans != ' ') {
                            if (ans == currentQuestion.correctOption) {
                                int r = pendingSlot / 3, c = pendingSlot % 3;
                                boardLogic[r][c] = currentMarker;
                                turnCount++;
                            }
                            winner = checkWinCondition();
                            if (winner != 0 || turnCount == 9) {
                                state = 5;
                            } else {
                                currentPlayer = (currentPlayer == 1) ? 2 : 1;
                                currentMarker = (currentMarker  == 'X') ? 'O' : 'X';
                                state = 3;
                            }

                            // AI move
                            if (state == 3 && isSinglePlayer && currentPlayer == 2) {
                                bool moved = false;
                                while (!moved && turnCount < 9) {
                                    int s = rand() % 9, r = s / 3, c = s % 3;
                                    if (boardLogic[r][c] != 'X' && boardLogic[r][c] != 'O') {
                                        boardLogic[r][c] = 'O'; turnCount++; moved = true;
                                    }
                                }
                                winner = checkWinCondition();
                                if (winner != 0 || turnCount == 9) state = 5;
                                else { currentPlayer = 1; currentMarker = 'X'; }
                            }
                        }
                    }
                    else if (state == 5) {
                        if (btnReset.isClicked(mousePos)) {
                            player1Name = ""; player2Name = "";
                            resetGame(); state = 0;
                        }
                    }
                }
            }
        }

        // Hover updates
        btnOnePlayer.update(mousePos); btnTwoPlayer.update(mousePos);
        btnFun.update(mousePos);       btnAcad.update(mousePos);
        btnStart.update(mousePos);
        btnOptA.update(mousePos); btnOptB.update(mousePos); btnOptC.update(mousePos);
        btnReset.update(mousePos);

        window.clear(BG_COLOR);

        // ---- State 0: Menu ----
        if (state == 0) {
            drawCloud(window, 100, 100); drawCloud(window, 700, 200);
            drawStar (window, 200, 500, 30, ACCENT_PINK);
            drawStar (window, 650, 500, 30, ACCENT_BLUE);
            Text title(font, "QUIZ TIC-TAC-TOE", 60);
            title.setFillColor(ACCENT_LILAC);
            title.setOutlineColor(Color::White); title.setOutlineThickness(4);
            FloatRect tr = title.getLocalBounds();
            title.setOrigin({tr.position.x + tr.size.x / 2.f, tr.position.y + tr.size.y / 2.f});
            title.setPosition({SCREEN_W / 2.f, 150});
            window.draw(title);
            btnOnePlayer.draw(window); btnTwoPlayer.draw(window);
        }

        // ---- State 1: Mode Select ----
        else if (state == 1) {
            drawCloud(window, 50, 50); drawCloud(window, 800, 100);
            drawBalloon(window, 620, 250, ACCENT_PINK);
            drawPencil (window, 250, 330);
            Text t(font, "SELECT MODE", 50);
            t.setFillColor(ACCENT_BLUE);
            t.setOutlineColor(Color::White); t.setOutlineThickness(3);
            FloatRect tr = t.getLocalBounds();
            t.setOrigin({tr.position.x + tr.size.x / 2.f, tr.position.y + tr.size.y / 2.f});
            t.setPosition({SCREEN_W / 2.f, 150});
            window.draw(t);
            btnFun.draw(window); btnAcad.draw(window);
        }

        // ---- State 2: Name Entry ----
        else if (state == 2) {
            drawCloud(window, 100, 50); drawCloud(window, 750, 80);
            drawStar (window, 200, 150, 25, ACCENT_PINK);
            drawStar (window, 700, 350, 25, ACCENT_BLUE);
            drawHeart(window, 580, 465, 20);

            Text t(font, "ENTER NAMES", 50);
            t.setFillColor(TEXT_COLOR); t.setPosition({290, 100}); window.draw(t);

            RectangleShape box1({400, 50}); box1.setPosition({250, 210});
            box1.setFillColor(enteringP1 ? Color::White : Color(240,240,240));
            box1.setOutlineThickness(enteringP1 ? 3 : 1); box1.setOutlineColor(ACCENT_PINK);
            window.draw(box1);
            Text t1(font, player1Name + (enteringP1 ? "|" : ""), 25);
            t1.setFillColor(TEXT_COLOR); t1.setPosition({260, 220}); window.draw(t1);
            Text label1(font, "Player 1:", 20);
            label1.setFillColor(TEXT_COLOR); label1.setPosition({250, 180}); window.draw(label1);

            if (!isSinglePlayer) {
                RectangleShape box2({400, 50}); box2.setPosition({250, 310});
                box2.setFillColor(!enteringP1 ? Color::White : Color(240,240,240));
                box2.setOutlineThickness(!enteringP1 ? 3 : 1); box2.setOutlineColor(ACCENT_PINK);
                window.draw(box2);
                Text t2(font, player2Name + (!enteringP1 ? "|" : ""), 25);
                t2.setFillColor(TEXT_COLOR); t2.setPosition({260, 320}); window.draw(t2);
                Text label2(font, "Player 2:", 20);
                label2.setFillColor(TEXT_COLOR); label2.setPosition({250, 280}); window.draw(label2);
            }
            btnStart.draw(window);
        }

        // ---- States 3 & 4: Board ----
        else if (state == 3 || state == 4) {
            drawCloud (window, 150, 20); drawCloud(window, 700, 20);
            drawFlower(window, 50,            50,            ACCENT_PINK);
            drawFlower(window, SCREEN_W - 50, 50,            ACCENT_BLUE);
            drawFlower(window, 50,            SCREEN_H - 50, ACCENT_LILAC);
            drawFlower(window, SCREEN_W - 50, SCREEN_H - 50, ACCENT_PEACH);

            Text turnTx(font, (currentPlayer == 1 ? player1Name : player2Name) + "'s Turn", 35);
            turnTx.setFillColor(TEXT_COLOR); turnTx.setPosition({100, 50}); window.draw(turnTx);

            RectangleShape v1({6,300}), v2({6,300}), h1({300,6}), h2({300,6});
            v1.setFillColor(GRID_COLOR); v1.setPosition({397,150});
            v2.setFillColor(GRID_COLOR); v2.setPosition({497,150});
            h1.setFillColor(GRID_COLOR); h1.setPosition({300,247});
            h2.setFillColor(GRID_COLOR); h2.setPosition({300,347});
            window.draw(v1); window.draw(v2); window.draw(h1); window.draw(h2);

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (boardLogic[i][j] == 'X' || boardLogic[i][j] == 'O') {
                        Text m(font, string(1, boardLogic[i][j]), 70);
                        m.setOutlineColor(Color::White); m.setOutlineThickness(3);
                        m.setFillColor(boardLogic[i][j] == 'X' ? ACCENT_BLUE : ACCENT_PINK);
                        m.setPosition({330 + j * 100.f, 155 + i * 100.f});
                        window.draw(m);
                    }
                }
            }

            if (state == 4) {
                RectangleShape shadow({700,450}); shadow.setPosition({110,110});
                shadow.setFillColor(Color(0,0,0,50)); window.draw(shadow);
                RectangleShape box({700,450}); box.setPosition({100,100});
                box.setFillColor(Color::White);
                box.setOutlineColor(ACCENT_LILAC); box.setOutlineThickness(4); window.draw(box);

                string prompt = currentQuestion.prompt;
                if (prompt.length() > 50) prompt.insert(50, "\n");
                Text qTx(font, "Q: " + prompt, 24);
                qTx.setFillColor(TEXT_COLOR); qTx.setPosition({130,130}); window.draw(qTx);

                btnOptA.draw(window); btnOptB.draw(window); btnOptC.draw(window);
            }
        }

        // ---- State 5: Game Over ----
        else if (state == 5) {
            drawCloud(window, 100, 100); drawCloud(window, 800, 100);
            drawHeart(window, 200, 150, 30); drawHeart(window, 700, 150, 30);

            Text wTx(font, "", 60);
            wTx.setOutlineColor(Color::White); wTx.setOutlineThickness(4);
            if (winner != 0) {
                wTx.setString((winner == 1 ? player1Name : player2Name) + " WINS!");
                wTx.setFillColor(ACCENT_LILAC);
            } else {
                wTx.setString("IT'S A DRAW!");
                wTx.setFillColor(ACCENT_PEACH);
            }
            FloatRect fr = wTx.getLocalBounds();
            wTx.setOrigin({fr.position.x + fr.size.x / 2.f, fr.position.y + fr.size.y / 2.f});
            wTx.setPosition({SCREEN_W / 2.f, 200}); window.draw(wTx);
            btnReset.draw(window);
        }

        window.display();
    }

    return 0;
}
