int                            isOver();    // 判断是否结束
void gotoprint(int x , int y , char *c);    // 输出字符串到指定位置
char    changeDirection(char direction);    // 获取新的前进方向

void              gotoxy(int x, int y);     //                跳转光标 


void gotoprint(int x , int y , char *c){
    gotoxy(x , y);
    puts(c);
}

char changeDirection(char direction) {
    char new_direction = direction;
    /*  _kbhit() 作为 执行direction = getch() 的前提条件 如果未检到按下按键则不会等待输入 */
    if( _kbhit() && ( new_direction = toupper(getch()) ) );
    if( (new_direction == UP || new_direction == DOWN || new_direction == LEFT || new_direction == RIGHT) 
    && abs(new_direction - direction) != 4 && abs(new_direction - direction) != 3) { direction = new_direction; }
    return direction;
}

int isOver() {
    snake *p = head -> next;
    while (p) {
        if(p -> x == head -> x && p -> y == head -> y) { 
            system("cls");
            return 1; 
        }
        p = p -> next;
    }
    return 0;
}



