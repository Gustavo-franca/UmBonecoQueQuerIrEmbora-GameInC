

// Define cores
enum {
    COLOR_BLACK,
    COLOR_BLUE,
    COLOR_GREEN,
    COLOR_CYAN,
    COLOR_RED,
    COLOR_MAGENTA,
    COLOR_BROWN,
    COLOR_GREY,
    COLOR_DARKGREY,
    COLOR_LIGHTBLUE,
    COLOR_LIGHTGREEN,
    COLOR_LIGHTCYAN,
    COLOR_LIGHTRED,
    COLOR_LIGHTMAGENTA,
    COLOR_YELLOW,
    COLOR_WHITE
};

// Define coordenadas da janela
void setWindow(int Width, int Height);

// Posiciona cursor em x e y
void gotoxy(int x, int y);

// Define cor de fundo
void setBackgroundColor(int c);

// Define cor do caracter
void setColor(int ForgC);

