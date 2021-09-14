#include "Data.h"

//width of border line screen
const float WB = 10;

//size of All screen
//const int W = 650 + int(WB) * 3;
const int W = 750 + int(WB) * 3;
const int H = 800 + int(WB) * 2;//HEIGHT game screen 800px
//const int H = 600 + int(WB) * 2;//HEIGHT game screen 600px

//size of main left rect
const float WML = 500;
const float HML = H - WB*2;

//size of main right rect
const float WMR = W - WML - WB * 3;
const float HMR = H - WB*2;

bool FL = false;//Figure Live

float SPEED_FDOWN = .05f;//Speed of falling down figure, value increasung in FloorArray::DEL_LINES by increasing Scores

int LINES_FOR_DEL = 0;//Global var count of removing lines, needs for create new arr lower size

float DEL_Y_ARR[4] = { 10, 10, 10, 10 };//arr for temporary storage Y coords of removing lines, it will sort in future, array members must not be zeros!!!

int SCORES = 0;