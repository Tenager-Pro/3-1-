#include "glew.h"
#include "glut.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h> 
#include "game.h"
#include "player.h"

#define ROWS 40.0 //кол-во строк
#define COLUMNS 40.0 //кол-во колонок
    Player game;
    std::ofstream ofile;
    std::ifstream ifile;
  
    bool game_over = false; // игра
    extern int sDirection;
    int score = 0; // очки
    std::string authorithation();
    void init();
    void display_callback();
    void input_callback(int, int, int);
    void reshape_callback(int, int);
    void timer_callback(int);
    void menu(std::string);




    int main(int argc, char** argv)
    {

        setlocale(LC_ALL, "Russian");
        std::string name;

        int num = 0;
        name = authorithation();
        game.setName(name);
        while (num != 3) {
            menu(name);
            std::cin >> num;
            switch (num) {
            case 1:
                glutInit(&argc, argv);
                std::cout << game_over;
                glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
                glutInitWindowPosition(10, 10);
                glutInitWindowSize(800, 800); // размер окна
                glutCreateWindow("Змейка"); // название окна


                glutDisplayFunc(display_callback);
                glutReshapeFunc(reshape_callback);
                glutSpecialFunc(input_callback);
                glutTimerFunc(100, timer_callback, 0);
                init();
                glutMainLoop();



                break;
            case 2:
                system("cls");
                std::cout << "Список лидеров!\n";
                printPlayer(playerOutDocument());
                system("pause");
                break;
            case 3:

                return 0;
                break;
            default:
                std::cout << "Повторить ввод";
                system("pause");
                break;
            }
        }

    }
    // Изачальная инициализация
    void init()
    {
        glClearColor(0.0, 0.0, 0.0, 0.0);
        initGrid(COLUMNS, ROWS);
    }
    void menu(std::string name) {
        system("cls");
        std::cout << name << std::endl;
        std::cout << "Ваш рекорд: \n\n";
        std::cout << "1. Новая игра\n";
        std::cout << "2. Список лидеров\n";
        std::cout << "3. Выйти\n";
        std::cout << "Введите номер: ";

    }
    std::string authorithation() {
        std::string name;
        std::cout << "Добро пожаловать!\nВведите свой ник: ";
        std::cin >> name;
        return name;
    }
    //очки игры!
    //Callbacks
    void display_callback()
    {
        if (game_over) {
            game.setPoints(score);
            //sortPlayers(game);
            glutDestroyWindow(glutGetWindow());
        }
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();
        draw_grid();
        draw_food();
        draw_snake();
        glutSwapBuffers();
    }




    void reshape_callback(int w, int h)
    {
        glViewport(0, 0, (GLfloat)w, GLfloat(h));
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }




    void timer_callback(int)
    {
        glutPostRedisplay();
        glutTimerFunc(100, timer_callback, 0);
    }


    void input_callback(int key, int x, int y)
    {
        switch (key)
        {
        case GLUT_KEY_UP:
            if (sDirection != DOWN)
                sDirection = UP;
            break;
        case GLUT_KEY_DOWN:
            if (sDirection != UP)
                sDirection = DOWN;
            break;
        case GLUT_KEY_RIGHT:
            if (sDirection != LEFT)
                sDirection = RIGHT;
            break;
        case GLUT_KEY_LEFT:
            if (sDirection != RIGHT)
                sDirection = LEFT;
            break;
        }
    }
