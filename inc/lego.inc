/*
 * A Lego is a piece used in all other objects, everything is made of Lego
 * It has a fixed size of 100 units for x, z and 125 for y
 */
#declare Lego =
union
{
    difference
    {
        union
        {
            box { <0, 0, 0> <100, 100, 100> }
            cylinder { <50, 0, 50> <50, 125, 50>, 25 }
        }

        box { <5, -5, 5> <95, 95, 95> }
    }

    difference
    {
        cylinder { <50,  0, 50> <50, 90, 50>, 28 }
        cylinder { <50, -1, 50> <50, 90, 50>, 25 }
    }
}

/*
 * Creating a pipe made of Lego
 *
 * @rayon  - the radius of the pipe (the larger the radius, the better will be the approximation of the cylinder)
 * @height - height of the pipe
 */
#macro MakePipe(rayon, height)
union
{
    #local i = 0;
    #local a = 0;
    #local X = 0;
    #local Z = 0;
    #local k = 0;

    #while(i <= 360)
        #local a = (i*2*pi) / 360;

        #if (X != ceil(cos(a) * rayon) | Z != ceil(sin(a) * rayon))
            #local X = max(ceil(cos(a) * rayon), -(rayon - 1));                                                   
            #local Z = max(ceil(sin(a) * rayon), -(rayon - 1));

            #while(k < height)
                #if( k > height / 2)  
                    object { Lego translate <X * 100, k * 100, Z * 100> }
                #end

                object
                {
                     Lego translate <max(ceil(cos(a) * (rayon - 1)), -(rayon - 2)) * 100, // x
                                     k * 100,                                             // y
                                     max(ceil(sin(a) * (rayon - 1)), -(rayon - 2)) * 100> // z
                }
                #local k = k + 1;
            #end

            #local k = 0;
          #end
        #local i = i + 1;
    #end
}
#end
                        
/*
 * Creating a plate made of Lego
 *
 * @sizeX - number of Lego for x
 * @sizeZ - number of Lego for z
 * @rot   - rotation
 */
#macro Plate(sizeX, sizeZ, rot)
union
{
    #local Xp = 0;

    #while (Xp < sizeX)
        #local Zp = 0;
        #while (Zp < sizeZ)
            object { Lego rotate x*rot translate <Xp*100, 0, Zp*100>  }
            #local Zp = Zp + 1;
        #end
        #local Xp = Xp + 1;
    #end
}
#end

/*
 * Creating a brick made of plates
 *
 * @sizeX - size of the brick for x (1 for 1 Lego)
 * @sizeY - size of the brick for y (1 for 1 Lego)
 * @sizeZ - size of the brick for z (1 for 1 Lego)
 * @tex   - texture applied to all faces of the brick
 */
#macro Brick(sizeX, sizeY, sizeZ, tex)
union
{
    // top
    object
    {
        Plate(sizeX, sizeZ, 0)
        translate <0, (sizeY * 100) - 100, 0>     
        texture { tex rotate 90*x }
    }

    // bottom       
    object
    {
        Plate(sizeX, sizeZ, 0)
        translate <0, 0, 0>                     
        texture { tex rotate 90*x }
    }

    // front                     
    object
    {
        Plate(sizeX, sizeY, 90)
        rotate -90*x translate <0, 0, -1>        
        texture { tex }
    }

    // back                  
    object
    {
        Plate(sizeX, sizeY, 90)
        rotate -90*x translate <0, 0, (sizeZ * 100) - 100>
        texture { tex }
    }

    // left    
    object
    {
        Plate(sizeZ, sizeY, 90)
        rotate <-90, 90, 0>
        translate <-1, 0, sizeZ * 100>
        texture { tex rotate -90*y }
    }

    // right
    object
    {
        Plate(sizeZ, sizeY, 90)
        rotate <-90, 90, 0>
        translate <(sizeX * 100) - 99, 0, sizeZ * 100>
        texture { tex rotate -90*y }
    }                   
}         
#end

/*
 * Creating a log made of bricks
 *
 * @length - size of the main part of the log
 */
#macro Log(length)
union
{
    object { Brick(9,  9,  1, texture { textureLog scale 900 }) translate <50,  50,  -100> }
    object { Brick(7,  7,  1, texture { textureLog scale 700 }) translate <150, 150, -200> }
    object { Brick(5,  5,  1, texture { textureLog scale 500 }) translate <250, 250, -300> }
    object { Brick(10, 10, length * 10, texture { textureTrunk  scale 1000}) }
}
#end

/*
 * Creating a bush
 *
 * @n - number of bushes
 * @w - width of a bush
 */
#macro Bush(n, w)
union
{
    #local j = 0;

    #while (j < n)
        object { GenObject(bush,w) translate <2000 * j, 0, 0> }
        #local j = j + 1;
    #end
}
#end      