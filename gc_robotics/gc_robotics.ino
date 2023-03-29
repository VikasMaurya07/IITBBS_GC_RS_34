#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>


#define __CS 10
#define __DC 9
#define __RST 12
Adafruit_ST7735 tft = Adafruit_ST7735(__CS, __DC,__RST);
// Color definitions
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0  
#define WHITE   0xFFFF
const int buttonPin = 7;
int buttonState = 0;

const int charwi = 10;
const int charhi = 10;
const int platwi = 240;
const int plathi = 40;
const int platY = 110;
const int minobs = 20;
const int maxobs = 80;
const int obswi= 20;
const int obspace = 80;
const int obscount = 3;
const int obspeed = 3;
const int humphi = 50;
int charX = 20;
int charY = 95;
int charYSpeed = 0;
int platX = 0;
int platSpeed = 4;
int obstacleX[obscount];
int obstacleY[obscount];

void setup()
{
    tft.initR(INITR_BLACKTAB);
  tft.fillScreen(BLACK);
    tft.setRotation(3);
    

    for (int i = 0; i < obscount; i++)
    {
        obstacleX[i] = platwi + i * obspace;
        obstacleY[i] = platY - random(minobs, maxobs);
    }

    
}

void loop()
{

    //tft.fillRect(charX, charY, charwi, charhi,BLACK);
    for (int i = 0; i < obscount; i++)
    {
        tft.fillRect(obstacleX[i], obstacleY[i], obswi, platY - obstacleY[i],BLACK);
    }

    platX += platSpeed;
    if (platX < 0 || platX + platwi > tft.width())
    {
        platSpeed = -platSpeed;
    }

    for (int i = 0; i < obscount; i++)
    {
        obstacleX[i] -= obspeed;
        if (obstacleX[i] + obswi< 0)
        {
            obstacleX[i] = tft.width() + obspace;
            obstacleY[i] = platY - random(minobs, maxobs);
        }
    }

    
    /*if (charY == platY - charhi)
    {
        charYSpeed = -humphi;
    }
    charY += charYSpeed;
    charYSpeed++;*/

    if (charY + charhi > tft.height())
    {
        charY = tft.height() - charhi;
        charYSpeed = 0;
    }
    /*if (charY > platY)
    {
        charY = platY - 20;
        charYSpeed = 0;
    }*/
    tft.fillRect(platX,105,platwi,5,GREEN);
    tft.fillRect(platX, platY, platwi, plathi,BLUE);

    for (int i = 0; i < obscount; i++)
    {
        tft.fillRect(obstacleX[i], obstacleY[i], obswi, platY - obstacleY[i],RED);
    }

tft.fillRect(charX, charY, charwi, charhi,MAGENTA);
  

    delay(10);
}
