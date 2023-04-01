/* 游戏运行 */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>        //        需要设置控制台颜色,光标跳转
#include <conio.h>          //                       无缓冲输入
#include <ctype.h>          //                       大小写转换
#include "init.c"           //           游戏界面 光标绘制初始化
#include "snake.c"          //                 蛇的结构体和操作
#include "Food.c"           //            食物的结构体和相关操作
#include "control.c"        //             获取输入信息,打印字符
char direction = RIGHT;     //                     初始前进方向

void startGame() {
    map();
    scoreBoard();
    CreateSnake();
    initFood();

    while ( !isOver() )
    {    
        direction = changeDirection(direction);
        moveSnake(direction);
        printSnake();  
        eatFood();
        Sleep(100);
    }
    changeRecord();
}
