#ifndef GLOBAL_H
#define GLOBAL_H
#include<QPointF>
#include "character.h"
#define ROTATION 5
#define CARD_ANI_DURATION 400
#define CARD_ZOOM_SCALE 1.5
#define CARD_0_OFFSET -160
#define CARD_WIDTH 150
#define CARD_HEIGHT 260
#define CARD_HOVER_OFFSET 100

#define CARD_X_INTERVAL 120
#define CARD_Y_INTERVAL 5
//int FIGHT_SCREEN_WIDTH=1080;
//int FIGHT_SCREEN_HEIGHT=720;

#define FIGURE_WIDTH 200
#define FIGURE_HEIGHT 200

#define FIGURE_X_INTERVAL 100
#define FIGURE_Y_INTERVAL 100


#define ENEMY_WIDTH 200
#define ENEMY_HEIGHT 200
#define ENEMY_X_INTERVAL 100
#define ENEMY_Y_INTERVAL 100


static QSize screenSize=QSize();
static int totalCardsNum=4;

#define EFFECT_PATH QString("D:/ccrepository/ccGame/CcCard/effect/")
#endif // GLOBAL_H
