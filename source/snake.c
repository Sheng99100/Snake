
/*  因为蛇移动时大部分位置不会变，所以不需要将蛇逐个移动，只需要
    用空格覆盖蛇尾 ， 并根据方向将原蛇尾设置为新的蛇头 , 再打印新蛇头来实现蛇的移动 */

#define UP 'W'
#define DOWN 'S'
#define LEFT 'A'
#define RIGHT 'D'          //  根据方向设置新蛇头的位置


void       CreateSnake();  //  初始化蛇
void        printSnake();  //  打印蛇头
void            append();  //  增加蛇的长度
void moveSnake(char way);  //  将蛇尾用空格或边框覆盖 , 移并动蛇尾将其作为新的蛇头 


typedef struct Snake {
    int x;
    int y;
    struct Snake *next;
}snake; 
snake *head;


void CreateSnake(){
    head = (snake*)malloc(sizeof(snake));
    head -> x =  35;
    head -> y =  15;
    head -> next = NULL;
    append(head);
    head -> next -> x = 34;
    head -> next -> y = 15;
    snake *p = head;
    while (p)
    {
        gotoprint(p -> x , p -> y , "o");
        p = p -> next;
    }

}

void printSnake() {
    gotoprint( head -> x , head -> y , "o");
}

void append() {
    snake *p = head;
    snake *newBody = (snake*)malloc(sizeof(snake));
    while (p -> next  != NULL) 
    {
        p = p -> next;
    }
    p -> next = newBody;
    newBody -> next = NULL;
    
}

void moveSnake(char way) {
    
    way = toupper(way);
    snake *p = head;
    
    /* 蛇尾用空格或边框覆盖 */
    while( (p -> next) -> next != NULL) 
    {   
        p = p -> next;
    }
    gotoprint(p -> next -> x , p -> next -> y , " ");
    if(p -> next -> x == POSX || p -> next -> y == POSY || p -> next -> x == POSX + WIDTH || p -> next -> y == POSY + HEIGHT ) {
        gotoprint(p -> next -> x , p -> next -> y , "+");
    }  

    if(way == UP) { 
        p -> next -> x = head -> x;
        p -> next -> y = head -> y - 1;
        if(p -> next -> y <= POSY) { p -> next -> y = POSY + HEIGHT-1; }
    }
    if(way == RIGHT) { 
        p -> next -> x = ( head -> x + 1 ) % ( WIDTH + POSX );
        p -> next -> y = head -> y;
    }
    if(way == LEFT) { 
        p -> next -> x = head -> x - 1 ;
        p -> next -> y = head -> y;
        if(p -> next -> x <= POSX) { p -> next -> x = WIDTH + POSX - 1; }
    }
    if(way == DOWN) { 
        p -> next -> x = head -> x;
        p -> next -> y = (head -> y + 1 ) % (HEIGHT + POSY);
    }

    if( p -> next -> x == 0) { p -> next -> x = POSX+1; }
    if( p -> next -> y == 0) { p -> next -> y = POSY+1; }

    p -> next -> next = head;
    head = p -> next;
    p -> next = NULL;
}