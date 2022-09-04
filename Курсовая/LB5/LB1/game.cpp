#include "glut.h"
#include <windows.h> 
#include <iostream>
#include <ctime>
#include "game.h"

    void levelOne(int, int);
    void levelTwo(int, int);
    void levelThree(int, int);
    int random(int, int);
    int level = 1;
    bool length_inc = false;
    bool seedflag = false;
    extern int score;
    extern bool game_over;
    bool food = false;
    int rows = 0, columns = 0;
    int sDirection = RIGHT;
    int foodx, foody;
    int posx[MAX + 1] = { 4,3,2,1,0,-1,-1 };
    int posy[MAX + 1] = { 10,10,10,10,10,10,10 };
    int length = 7;// длина змеи

    void initGrid(int x, int y)
    {
        columns = x;
        rows = y;
    }

    void draw_grid()//сетка
    {
        for (int i = 0; i < columns; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                switch (level) {
                case 1:
                    levelOne(i, j);
                    break;
                case 2:
                    levelTwo(i, j);
                    break;
                case 3:
                    levelThree(i, j);
                    break;

                }

            }
        }
    }

    void draw_snake()//рисуем змею
    {
        for (int i = length - 1; i > 0; i--)
        {
            posx[i] = posx[i - 1];
            posy[i] = posy[i - 1];
        }
        for (int i = 0; i < length; i++)
        {
            glColor3f(1.0, 1.0, 0.0);//цвет тела
            if (i == 0)
            {
                glColor3f(0.0, 0.0, 1.0);//цвет голова
                switch (sDirection)
                {
                case UP:
                    if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
                        posy[i] += 2;
                    }
                    else {
                        posy[i]++;
                    }

                    break;
                case DOWN:
                    if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
                        posy[i] -= 2;
                    }
                    else {
                        posy[i]--;
                    }
                    break;
                case RIGHT:
                    if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
                        posx[i] += 2;
                    }
                    else {
                        posx[i]++;
                    }

                    break;
                case LEFT:
                    if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
                        posx[i] -= 2;
                    }
                    else {
                        posx[i]--;
                    }
                    break;
                }


                if (posx[i] <= 0 ||
                    posx[i] >= columns - 1 ||
                    posy[i] <= 0 ||
                    posy[i] >= rows - 1 &&
                    level == 1 ||
                    (posx[i] <= columns - 6 && posx[i] >= columns - 35 && posy[i] == 5) ||
                    (posx[i] <= columns - 6 && posx[i] >= columns - 35 && posy[i] == 15) ||
                    (posx[i] <= columns - 6 && posx[i] >= columns - 35 && posy[i] == 30))//выход за границы
                {
                    game_over = true;
                }
                else if (posx[i] <= 0 ||
                    posx[i] >= columns - 1 ||
                    posy[i] <= 0 ||
                    posy[i] >= rows - 1 &&
                    level == 2) 
                {
                    game_over = true;
                }
                else if (posx[i] <= 0 ||
                    posx[i] >= columns - 1 ||
                    posy[i] <= 0 ||
                    posy[i] >= rows - 1 &&
                    level == 3) 
                {
                    game_over = true;
                }
                else if (posx[i] == foodx && posy[i] == foody)// еда
                {
                    food = false;
                    score++;
                    if (length <= MAX)
                        length_inc = true;
                    if (length == MAX)
                    {
                        level++;
                        displayResourceMessageBox(0, score);
                    }

                }
                for (int j = 1; j < length; j++)
                {
                    if (posx[j] == posx[0] && posy[j] == posy[0])
                        game_over = true;
                }
            }
            glBegin(GL_QUADS);
            glVertex2d(posx[i], posy[i]);
            glVertex2d(posx[i] + 1, posy[i]);
            glVertex2d(posx[i] + 1, posy[i] + 1);
            glVertex2d(posx[i], posy[i] + 1);
            glEnd();
        }
        if (length_inc)
        {
            length++;
            length_inc = false;
        }
    }

    void draw_food()//рисунок еды
    {
        if (!food)
        {
            foodx = random(2, columns - 2);
            foody = random(2, rows - 2);
            std::cout << foodx << " " << foody << std::endl;
            food = true;
        }
        //рисует квадрат еды
        glBegin(GL_QUADS);
        glVertex2d(foodx, foody);
        glVertex2d(foodx + 1, foody);
        glVertex2d(foodx + 1, foody + 1);
        glVertex2d(foodx, foody + 1);
        glEnd();
    }

    void levelOne(int x, int y)//рисунок поля
    {
        glLoadIdentity();
        if (x == 0 || x == columns - 1 || y == 0 || y == rows - 1)
        {
            glLineWidth(4.0);
            glColor3f(1.0, 0.0, 0.0);
        }
        else
        {
            if (
                (x <= columns - 6 && x >= columns - 35 && y == 5) ||
                (x <= columns - 6 && x >= columns - 35 && y == 15)||
                (x <= columns - 6 && x >= columns - 35 && y == 30)
                ) {
                glLineWidth(4.0);
                glColor3f(1.0, 0.0, 0.0);
            }
            else {
                glColor3f(1.0, 1.0, 1.0);
                glLineWidth(1.0);
            }
        }
        glBegin(GL_LINES);
        glVertex2d(x, y); glVertex2d(x + 1, y);
        glVertex2d(x + 1, y); glVertex2d(x + 1, y + 1);
        glVertex2d(x + 1, y + 1); glVertex2d(x, y + 1);
        glVertex2d(x, y + 1); glVertex2d(x, y);
        glEnd();
    }


    void levelTwo(int x, int y)//рисунок поля 2
    {
        glLoadIdentity();
        if (x == 0 || x == columns - 1 || y == 0 || y == rows - 1)
        {
            glLineWidth(4.0);
            glColor3f(1.0, 0.0, 0.0);
        }
        else
        {
            if (x <= columns - 5 && x >= columns - 8 && y == 5) {
                glLineWidth(4.0);
                glColor3f(1.0, 0.0, 0.0);
            }
            else {
                glColor3f(1.0, 1.0, 1.0);
                glLineWidth(1.0);
            }
        }
        glBegin(GL_LINES);
        glVertex2d(x, y); glVertex2d(x + 1, y);
        glVertex2d(x + 1, y); glVertex2d(x + 1, y + 1);
        glVertex2d(x + 1, y + 1); glVertex2d(x, y + 1);
        glVertex2d(x, y + 1); glVertex2d(x, y);
        glEnd();
    }



    void levelThree(int x, int y)//рисунок поля 3
    {
        glLoadIdentity();
        if (x == 0 || x == columns - 1 || y == 0 || y == rows - 1)
        {
            glLineWidth(4.0);
            glColor3f(1.0, 0.0, 0.0);
        }
        else
        {
            if (x <= columns - 5 && x >= columns - 8 && y == 5) {
                glLineWidth(4.0);
                glColor3f(1.0, 0.0, 0.0);
            }
            else {
                glColor3f(1.0, 1.0, 1.0);
                glLineWidth(1.0);
            }
        }
        glBegin(GL_LINES);
        glVertex2d(x, y); glVertex2d(x + 1, y);
        glVertex2d(x + 1, y); glVertex2d(x + 1, y + 1);
        glVertex2d(x + 1, y + 1); glVertex2d(x, y + 1);
        glVertex2d(x, y + 1); glVertex2d(x, y);
        glEnd();
    }




    int random(int _min, int _max)
    {
        if (!seedflag)
        {
            srand(time(NULL));
            seedflag = true;
        }
        else
            seedflag = false;
        return _min + rand() % (_max - _min);
    }

    void displayResourceMessageBox(int numMesage, int score) {
        std::cout << "\nScore: " << score;
        char text[50] = "Score: ";

        int msgboxID = MessageBox(NULL,
            (LPCWSTR)score,
            (LPCTSTR)L"Game over",
            MB_YESNO | MB_OKCANCEL | MB_ICONQUESTION);
        switch (msgboxID)
        {
        case IDTRYAGAIN:
            break;
        case IDCANCEL:
            break;
        default:
            break;
        }

    }
