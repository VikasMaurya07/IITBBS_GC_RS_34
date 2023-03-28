#include <SPI.h>
#include <Adafruit_GFX.h>
#include <TFT_ILI9163C.h>

#define __CS 10
#define __DC 9
#define __RST 12
TFT_ILI9163C tft = TFT_ILI9163C(__CS, __DC,__RST);

// Color definitions
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0  
#define WHITE   0xFFFF

#define still_player 0
#define move_player 1
#define jump_player 2
#define dead_player 4
#define Game_intro 100
#define Game_tittle 101
#define Game_credits 102
#define Game_Level 103
#define Game_play 104
#define Game_over 105

float hspd=0;
float hspd_speed=3;
unsigned int gamestate = Game_intro;
long Timer_prev=0;
unsigned long Timer_current=0;
int player_state=still_player;
int player_direction=1;
int last_direction=1;
long player_timer=0;
long player_timer_prev=0;

float sign(float x){
  if(x>0) return 1;
  else if(x<0) return -1;
  return 0;
}

//intro
void sceneIntro(){
  float sizex=13*6;
  tft.setTextSize(1);
  tft.setTextColor(BLACK);
  tft.setCursor((tft.width()-sizex)/2,tft.height()/2-12);
  tft.display(true);
  Timer_current=millis();
  if (Timer_current-Timer_prev>2500){
    Timer_prev=Timer_current;
    tft.fillScreen(RED);
    gamestate=Game_tittle;
    tft.println("Super shakti");
  }
}
void playerLogic(boolean move_esq,boolean move_dir,boolean jump){
  //Horizontal movement
  if (player_state != dead_player){
    hspd=0;
    boolean moving=false;
    if (move_esq==true && move_dir==false){
      player_direction=1;
      moving=true;
    }else if(move_dir==true && move_esq==false){
      player_direction=-1;
      moving=true;
    }
    if(moving)
    hspd=hspd_speed*(float)player_direction;

  }

}

void setup(){
  tft.begin();
}

void loop(void){
  switch(gamestate){
    case Game_intro: {
      sceneIntro(); 
      break;
      }
  }

}
