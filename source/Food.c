void initFood(); //       初始化食物结构体
void  putFood(); //   根据食物位置显示食物
void  eatFood(); // 检测蛇头和食物是否碰撞

typedef struct Foods
{
    int x1;
    int y1;
    int eated;   //  是否被吃
}foods;
foods *food;

void initFood() {
    food = (foods*)malloc( sizeof(foods) );
    food -> x1 = rand() % ( WIDTH  - 2 ) + POSX + 1;
    food -> y1 = rand() % ( HEIGHT - 2 ) + POSY + 1;
    food -> eated = 1;
    putFood();
}

void putFood() {
    if(food -> eated){
        int x1 , y1;
        x1 =  rand() % ( WIDTH  - 2 ) + POSX + 1;
        y1 =  rand() % ( HEIGHT - 2 ) + POSY + 1;
        food -> x1 = x1;
        food -> y1 = y1;
        food -> eated = 0;
    }
    gotoprint(food -> x1 , food -> y1 , "*");
}

void eatFood() {
    if( ( head -> x ) == ( food -> x1 )  &&  ( head -> y ) == ( food -> y1 ) ) {
        food -> eated = 1;
        Score += 1;
        gotoxy( POSX + WIDTH + 20  , POSY + 3);
        printf("Score: %d " , Score);
        append();
    }
    putFood();
}
