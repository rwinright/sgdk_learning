#include "genesis.h"

void myJoyHandler(u16 joy, u16 changed, u16 state)
{
    if(joy == JOY_1){
        if(state & BUTTON_START){
            //Pressed
            VDP_clearTextLine(13);
            VDP_drawText("Start button pressed", 13, 13);
        }
        else if(changed & BUTTON_START){
            //Released
            VDP_clearTextLine(13);
            VDP_drawText("Start button depressed", 13, 13);
        }
    }
}

int main()
{
    JOY_init();
    JOY_setEventHandler(&myJoyHandler);
    while(1)
    {
        //read input
        //move sprite
        //update score
        //draw current screen (logo, start screen, settings, game, gameover, credits...)
        VDP_waitVSync(); //Wait for the screen to update -- Required to run at **only** 60fps
    }
    return (0);
}
