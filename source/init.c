#define WIDTH 50
#define HEIGHT 25
#define POSX 25
#define POSY 5
int Score = 0;                              //                     得分


void                             map();     //             绘制游戏地图
int                         gameManu();     //             游戏初始菜单
int                         gameInfo();     //             显示游戏信息 
void                        mainManu();     //           游戏菜单间循环
void                        overInfo();     //             游戏结束菜单
void                      scoreBoard();     //               绘制得分板
int                      getTopScore();     //             获取最高纪录
void              gotoxy(int x, int y);     //                跳转光标 
extern void gotoprint(int ,int ,char*);     //   跳转到指定位置输出字符




void gotoxy(int x, int y) { 
    COORD pos = {x,y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);  // 获取标准输出设备句柄
    SetConsoleCursorPosition(hOut, pos);            //两个参数分别是指定哪个窗体，具体位置

    /*   隐藏光标   */
    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize = sizeof(cursor);
    cursor.bVisible = FALSE;
    SetConsoleCursorInfo(hOut, &cursor);
}

void map() { 
    system("cls");
    int x = POSX , y = POSY;
    for(x ; x < POSX + WIDTH  ; x++) {
        gotoxy(x,y);
        putchar('+');
    }
    for(y ; y < POSY + HEIGHT ; y++) {
        gotoxy(x,y);
        putchar('+');
    }
    for(x ; x >= POSX ; x--) {
        gotoxy(x,y);
        putchar('+');
    }
    x++;
    for(y ; y >= POSY ; y--) {
        gotoxy(x,y);
        putchar('+');
    }
}

void scoreBoard() { 
    int posx = POSX + WIDTH + 10;
    int posy = POSY;
    int width = posx + 30;
    int height = posy + 10;
    int x , y;
    for(x = posx ; x < width ; x++ ) {
        gotoprint(x , posy ,"-");
    }
    for(y = posy ; y < height ; y++ ) {
        gotoprint(x , y ,"-");
    }
    for(x  ; x >= posx ; x-- ) {
        gotoprint(x , y , "-");
    }
    x++;
    for(y ; y >= posy ; y-- ) {
        gotoprint(x , y ,"-");
    }
    gotoxy( POSX + WIDTH + 21  , POSY + 3);
    printf("Score: %d" , Score);
    gotoxy( POSX + WIDTH + 17  , POSY + 4);
    printf("Top Score: %d", getTopScore() );
}

int gameManu() {
    char c;
    map();
    gotoprint(WIDTH - 10 , POSY+7 ,       "       Snake       "         );
    gotoprint(WIDTH - 17 , POSY+9 , "A.START GAME  B.GAME INSTRUCTIONS" );
    gotoprint(WIDTH - 17 , POSY+11 , "            Q). QUIT         "    );
    while(1) {
        c = toupper( getch() ) ;
        switch (c) {
        case 'A':
            return 1;
            break;
        case 'B':
            return 0;
            break;
        case 'Q':
            exit(1);
        default:
            break;
        }
    }
}

void overInfo() {
    system("cls");
    int posx = 50;
    int posy = POSY;
    int width = posx + 30;
    int height = posy + 10;
    int x , y;
    for(x = posx ; x < width ; x++ ) {
        gotoprint(x , posy ,"-");
    }
    for(y = posy ; y < height ; y++ ) {
        gotoprint(x , y ,"-");
    }
    for(x  ; x >= posx ; x-- ) {
        gotoprint(x , y , "-");
    }
    x++;
    for(y ; y >= posy ; y-- ) {
        gotoprint(x , y ,"-");
    }
    gotoxy( 53 , POSY + 3);
    printf("Game over!  Score: %d \n " , Score);
    gotoxy( 53  , POSY + 4);
    printf("Top Score: %d", getTopScore());
    gotoxy( 53  , POSY + 5);
    printf("Hit any key to continue...");
   
    Score = 0;
    while(1) {
        if( _kbhit() && getch() ) { break; }
    }
}

void changeRecord() {
    int record;
    record = getTopScore();
    FILE *fp;
    fp = fopen(".\\GameExe\\record.bin","wb");
    if( record  < Score) { 
        fwrite(&Score , sizeof(record) , 1 ,fp);
    }
    fclose(fp);
}

int getTopScore() {
    int record;
    FILE *fp;
    fp = fopen(".\\GameExe\\record.bin","rb");
    rewind(fp);
    fread(&record , sizeof(record) , 1 , fp);
    fclose(fp);
    return record;
}

int gameInfo() {
    map();
    gotoprint((POSX + WIDTH)/2 , POSY+3 ,   "----- W A S D TO CONTROL"          );
    gotoprint((POSX + WIDTH)/2 , POSY+5 ,   "----- @ Sheng"                     );
    gotoprint((POSX + WIDTH)/2 , POSY+7 ,   "----- Email: <y202239365@163.com>" );
    gotoprint((POSX + WIDTH)/2 , POSY+9 ,   "----- DATE: 2021.1.26"             );
    gotoprint((POSX + WIDTH)/2 , POSY+11 ,  "----- Q). BACK"                    );
    while(1) {
        if( _kbhit() && toupper(getch()) == 'Q' ) { break; }
    }
}

void mainManu() {
    while(1) {
        if ( gameManu() ) { break; }
        gameInfo();
    }
}