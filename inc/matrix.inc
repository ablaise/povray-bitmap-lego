/*
 * Color palette used in 3d model tables
 */
#declare palette = array[8]
{
    color Magenta,          // 0 (transparence)
    color White,            // 1
    color Red,              // 2
    color Green,            // 3
    color Black,            // 4
    color Yellow,           // 5
    color rgb <0.9,0.6,0.3> // 6 (skin color)
    color Brown             // 7

}

/*
 * Creating a "bitmap" object
 * The result will be a 2d rendering effect
 *
 * @obj - 2d array of the object to be created
 *        each id of the array must be an id of the color palette
 * @w   - thickness
 */
#macro GenObject(obj, w)
union
{
    #local i = 0;
    #local j = 0;
    #local k = 0; // used for thickness
    #local height = dimension_size(obj, 1) - 1; // maximum height

    // creating the object based on its data
    #while (i < dimension_size(obj, 1))
        #while (j < dimension_size(obj, 2))

            // the block is created if it's not transparent
            #if (obj[i][j] != 0)

                // displaying with thickness
                #while (k < w)
                    object { Lego translate <j*100, height*100 - i*100, k*100> pigment { color palette[obj[i][j]] } }
                    #local k = k + 1;
                #end
            #end

            #local j = j + 1;
            #local k = 0;
        #end
        #local i = i + 1;
        #local j = 0;
    #end
}
#end

/*
 * Displays text stored in an array
 *
 * @txt - array
 * @w   - thickness
 */
#macro DrawText(txt, w)
union
{
    #local i = 0;
    #local idx = 0;

    // loop through all letters
    #while (i < dimension_size(txt, 1))

        #local add = true;

        // get the current letter
        #switch (0)
            #case (strcmp(strupr(txt[i])," "))
                #declare char = GenObject(empty, w);
            #break
            #case (strcmp(strupr(txt[i]),"A"))
                #declare char = GenObject(A, w);
            #break
            #case (strcmp(strupr(txt[i]),"B"))
                #declare char = GenObject(B, w);
            #break
            #case (strcmp(strupr(txt[i]),"C"))
                #declare char = GenObject(C, w);
            #break
            #case (strcmp(strupr(txt[i]),"D"))
                #declare char = GenObject(D, w);
            #break
            #case (strcmp(strupr(txt[i]),"E"))
                #declare char = GenObject(E, w);
            #break
            #case (strcmp(strupr(txt[i]),"F"))
                #declare char = GenObject(F, w);
            #break
            #case (strcmp(strupr(txt[i]),"G"))
                #declare char = GenObject(G, w);
            #break
            #case (strcmp(strupr(txt[i]),"H"))
                #declare char = GenObject(H, w);
            #break
            #case (strcmp(strupr(txt[i]),"I"))
                #declare char = GenObject(I, w);
            #break
            #case (strcmp(strupr(txt[i]),"J"))
                #declare char = GenObject(J, w);
            #break
            #case (strcmp(strupr(txt[i]),"K"))
                #declare char = GenObject(K, w);
            #break
            #case (strcmp(strupr(txt[i]),"L"))
                #declare char = GenObject(L, w);
            #break
            #case (strcmp(strupr(txt[i]),"M"))
                #declare char = GenObject(M, w);
            #break
            #case (strcmp(strupr(txt[i]),"N"))
                #declare char = GenObject(N, w);
            #break
            #case (strcmp(strupr(txt[i]),"O"))
                #declare char = GenObject(O, w);
            #break
            #case (strcmp(strupr(txt[i]),"P"))
                #declare char = GenObject(P, w);
            #break
            #case (strcmp(strupr(txt[i]),"Q"))
                #declare char = GenObject(Q, w);
            #break
            #case (strcmp(strupr(txt[i]),"R"))
                #declare char = GenObject(R, w);
            #break
            #case (strcmp(strupr(txt[i]),"S"))
                #declare char = GenObject(S, w);
            #break
            #case (strcmp(strupr(txt[i]),"T"))
                #declare char = GenObject(T, w);
            #break
            #case (strcmp(strupr(txt[i]),"U"))
                #declare char = GenObject(U, w);
            #break
            #case (strcmp(strupr(txt[i]),"V"))
                #declare char = GenObject(V, w);
            #break
            #case (strcmp(strupr(txt[i]),"W"))
                #declare char = GenObject(W, w);
            #break
            #case (strcmp(strupr(txt[i]),"X"))
                #declare char = GenObject(X, w);
            #break
            #case (strcmp(strupr(txt[i]),"Y"))
                #declare char = GenObject(Y, w);
            #break
            #case (strcmp(strupr(txt[i]),"Z"))
                #declare char = GenObject(Z, w);
            #break
            #case (strcmp(strupr(txt[i]),"0"))
                #declare char = GenObject(n0, w);
            #break
            #case (strcmp(strupr(txt[i]),"1"))
                #declare char = GenObject(n1, w);
            #break
            #case (strcmp(strupr(txt[i]),"2"))
                #declare char = GenObject(n2, w);
            #break
            #case (strcmp(strupr(txt[i]),"3"))
                #declare char = GenObject(n3, w);
            #break
            #case (strcmp(strupr(txt[i]),"4"))
                #declare char = GenObject(n4, w);
            #break
            #case (strcmp(strupr(txt[i]),"5"))
                #declare char = GenObject(n5, w);
            #break
            #case (strcmp(strupr(txt[i]),"6"))
                #declare char = GenObject(n6, w);
            #break
            #case (strcmp(strupr(txt[i]),"7"))
                #declare char = GenObject(n7, w);
            #break
            #case (strcmp(strupr(txt[i]),"8"))
                #declare char = GenObject(n8, w);
            #break
            #case (strcmp(strupr(txt[i]),"9"))
                #declare char = GenObject(n9, w);
            #break
            #case (strcmp(strupr(txt[i]),"-"))
                #declare char = GenObject(dash, w);
            #break

        // if the character is unknown, do not add it
        #else
            #local add = false;
        #end

        #if (add)
            object { char translate <idx * 1000, 0, 0> }
            #local idx = idx + 1;
        #end

        #local i = i + 1;
    #end
}
#end