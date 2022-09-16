#include "glut.h"
#include <windows.h> 
#include <iostream>
#include <ctime>
#include "game.h"
#include "snake.h"
#include "food.h"

    Snake snake(1);
    Game game(1);
    Food food;
   
    
    
    bool length_inc = false;
    bool seedflag = false;
    extern int score;
    extern bool game_over;
    
    int rows = 0, columns = 0;
    int sDirection = RIGHT;

   
    

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
                switch (game.level) {
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
        
        for (int i = snake.length - 1; i > 0; i--)
            {
                snake.posx[i] = snake.posx[i - 1];
                snake.posy[i] = snake.posy[i - 1];
            }
        for (int i = 0; i < snake.length; i++)
        {
            glColor3f(1.0, 1.0, 0.0);//цвет тела
            if (i == 0)
            {
                glColor3f(0.0, 0.0, 1.0);//цвет голова
                switch (sDirection)
                {
                case UP:
                    if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
                        snake.posy[i] += 2;
                    }
                    else {
                        snake.posy[i]++;
                    }

                    break;
                case DOWN:
                    if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
                        snake.posy[i] -= 2;
                    }
                    else {
                        snake.posy[i]--;
                    }
                    break;
                case RIGHT:
                    if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
                        snake.posx[i] += 2;
                    }
                    else {
                        snake.posx[i]++;
                    }

                    break;
                case LEFT:
                    if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT)) {
                        snake.posx[i] -= 2;
                    }
                    else {
                        snake.posx[i]--;
                    }
                    break;
                }

            
                if (
                    
                    
                    snake.posx[i] <= 0 ||
                    snake.posx[i] >= columns - 1 ||
                    snake.posy[i] <= 0 ||
                    snake.posy[i] >= rows - 1 &&
                    game.level == 1 ||
                    (snake.posx[i] <= columns - 6 && snake.posx[i] >= columns - 35 && snake.posy[i] == 5) ||
                    (snake.posx[i] <= columns - 6 && snake.posx[i] >= columns - 35 && snake.posy[i] == 15) ||
                    (snake.posx[i] <= columns - 6 && snake.posx[i] >= columns - 35 && snake.posy[i] == 30))//выход за границы
                {
                    game_over = true;
                }
                else if (snake.posx[i] <= 0 ||
                    snake.posx[i] >= columns - 1 ||
                    snake.posy[i] <= 0 ||
                    snake.posy[i] >= rows - 1 &&
                    game.level == 2)
                {
                    game_over = true;
                }
                else if (snake.posx[i] <= 0 ||
                    snake.posx[i] >= columns - 1 ||
                    snake.posy[i] <= 0 ||
                    snake.posy[i] >= rows - 1 &&
                    game.level == 3)
                {
                    game_over = true;
                }
                else if (snake.posx[i] == food.x && snake.posy[i] == food.y)// еда
                {
                    food.flag = false;
                    score++;
                    if (snake.length <= MAX)
                        length_inc = true;
                    if (snake.length == MAX)
                    {
                        game.level++;
                        
                    }

                }
                for (int j = 1; j < snake.length; j++)
                {
                    if (snake.posx[j] == snake.posx[0] && snake.posy[j] == snake.posy[0])
                        game_over = true;
                }
            }
            glBegin(GL_QUADS);
            glVertex2d(snake.posx[i], snake.posy[i]);
            glVertex2d(snake.posx[i] + 1, snake.posy[i]);
            glVertex2d(snake.posx[i] + 1, snake.posy[i] + 1);
            glVertex2d(snake.posx[i], snake.posy[i] + 1);
            glEnd();
        }
        if (length_inc)
        {
            snake.length++;
            length_inc = false;
        }
    }

    void draw_food()//рисунок еды
    {
        if (!food.flag)
        {
            food.x = random(2, columns - 2);
            food.y = random(2, rows - 2);
            std::cout << food.x << " " << food.y << std::endl;
            food.flag = true;
        }
        //рисует квадрат еды
        glBegin(GL_QUADS);
        glVertex2d(food.x, food.y);
        glVertex2d(food.x + 1, food.y);
        glVertex2d(food.x + 1, food.y + 1);
        glVertex2d(food.x, food.y + 1);
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

  
