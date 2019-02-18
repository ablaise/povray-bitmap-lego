#version 3.6;
global_settings { assumed_gamma 2.3 }
#default { finish { ambient 0.2 diffuse 1 } }

#include "colors.inc"
#include "textures.inc"
#include "math.inc"
#include "woods.inc"
#include "inc/textures.inc"
#include "inc/Lego.inc"
#include "inc/matrix.inc"
#include "inc/alphanumeric.inc"
#include "inc/models.inc"

light_source { <5000, 16000, -8000> color White }
sky_sphere { pigment { color rgb <0.4, 0.7, 1.0> } }

// basic camera
#declare Camera_0 =
camera
{
    angle 42
    location <-5000, 17000,-20000>
    look_at  <8000, 6000, 4000>
}

// left side camera
#declare Camera_1 =
camera
{
    angle 42
    location <-22000, 10000, 4000>
    look_at  <10000, 7000, 4000>
}

// assign a camera
camera { Camera_0 }

// text display (score, time, etc.)
#declare txt    = array[22] { "M","A","R","I", "O", " ", " ", " ", " ", " ", " ", "W", "O", "R", "L", "D", " ", " ", "T", "I", "M", "E" }
#declare bottom = array[22] { "0","7","5","1", "9", " ", " ", "X", "4", "2", " ", " ", "2", "-", "1", " ", " ", " ", "3", "6", "0", " " }
object { DrawText(txt, 2)    translate <1000, 11600, 12000> }
object { DrawText(bottom, 2) translate <1000, 10600, 12000> }
object { GenObject(coin, 2)  translate <6900, 10500, 12000> }

// ground
object { Brick(600, 100, 80, textureBrick2) translate <-4000, -8000,0>  }

// floating bricks
object { Brick(30, 10, 10, textureBrick2) translate <1000,  5000, 6000> }
object { Brick(10, 10, 10, textureBrick2) translate <8000,  5000, 6000> }
object { Brick(10, 10, 10, textureBrick3) translate <9000,  5000, 6000> }
object { Brick(10, 10, 10, textureBrick2) translate <10000, 5000, 6000> }
object { Brick(10, 10, 10, textureBrick3) translate <11000, 5000, 6000> }
object { Brick(10, 10, 10, textureBrick2) translate <12000, 5000, 6000> }
object { Brick(10, 10, 10, textureBrick)  translate <10000, 8000, 6000> }

// wooden logs
object { Log(6) translate <13000, 2000, 1300> }
object { Log(6) translate <14000, 2000, 1300> }
object { Log(6) translate <15000, 2000, 1300> }
object { Log(6) translate <16000, 2000, 1300> }
object { Log(6) translate <17000, 2000, 1300> }
object { Log(6) translate <14000, 3000, 1300> }
object { Log(6) translate <15000, 3000, 1300> }
object { Log(6) translate <16000, 3000, 1300> }
object { Log(6) translate <15000, 4000, 1300> }

// Mario
object
{
    GenObject(mario, 2)
    translate <8000, 6000, 6300>
}

// Goomba monster
object
{
    GenObject(goomba, 2)
    translate <9000, 2000, 4000>
}

// Boo monster
object
{
    GenObject(boo, 2)
    rotate 180*y
    translate <3300, 6000, 6500>
}

// Fire Flower
object
{
    GenObject(flower, 2)
    translate <9700, 9000, 6300>
}

// Mushroom
object
{
    GenObject(mushroom, 2)
    translate <11600, 6000, 6300>
}

// Super Star
object
{
    GenObject(star, 2)
    translate <14000, 6000, 4000>
}

// smiling cloud
object
{
    GenObject(cloud, 2)
    translate <5000, 9000, 6500>
}

// clouds
object { GenObject(cloud2, 2) translate <-1000, 7800, 8000> }
object { GenObject(cloud2, 2) translate <18000, 7000, 8000> }

// bushes
object { Bush(2, 10) translate <0,     2000, 7000> }
object { Bush(2, 10) translate <22000, 2000, 7000> }

// coins
object { GenObject(coin, 2) translate <-2000, 3000, 4000> }
object { GenObject(coin, 2) translate <0,     3000, 4000> }
object { GenObject(coin, 2) translate <2000,  3000, 4000> }
object { GenObject(coin, 2) translate <5500,  7000, 6500> }
object { GenObject(coin, 2) translate <20000, 3000, 4000> }
object { GenObject(coin, 2) translate <22000, 3000, 4000> }

// Piranha Plant in his pipe
#local xPipe = 5100;
#local yPipe = 2000;
#local zPipe = 4000;
object { MakePipe(10, 20) pigment { color Green } translate <xPipe, yPipe, zPipe> }
object { GenObject(plant, 2) translate <xPipe - 700, yPipe + 1000, zPipe > }