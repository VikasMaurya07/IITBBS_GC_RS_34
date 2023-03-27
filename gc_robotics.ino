#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
Adafruit_PCD8544 display=Adafruit_PCD8544(8,9,10,11,12);
TileMap gameTilemap;
#define still_player 0;
#define move_player 1;
#define jump_player 2;
#define dead_player 4;
#define Game_intro 100'
#define Game_tittle 101;
#define Game_credits 102;
#define Game_Level 103;
#define Game_play 104;
#define Game_over 105;
float hspd=0;
unsigned int gamestate=Game_intro;
long Timer_prev=0;
unsigned long Timer_current=0;
int player_state=still_player;
int player_direction=1;
int last_direction=1;
long player_timer=0;
long player_timer_prev=0;

//intro
void sceneIntro(){
  display.clearDisplay();
  float sizex=13*6;
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor((display.width()-sizex)/2,display.height()/2-12);
  display.display();
  Timer_current=mills();
  if (Timer_current-Timer_prev>2500){
    Timer_prev=Timer_current;
    display.clearDisplay();
    gamestate=Game_tittle;
  }
}
void playerLogic(boolean move_esq,boolean move_dir,boolean jump ){
  //Horizontal movement
  if(player_state!=dead_player){
    hspd=0;
    boolean moving=false;
    if (move_esq==true && move_dir==false){
      player_direction=1;
      moving=true;
    }else if(move_dir==true && move_esq==false){
      player_direction=-1;
      moving=true;
    }
  }

}




















