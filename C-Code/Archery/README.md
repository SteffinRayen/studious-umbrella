#Archery Game in C

This is a simple balloon shooting game made in C language. In this game, there are number of balloons, a bow and arrows for shooting the balloons. The balloons rise from the lower portion of the screen. The bow is put on left side which can move up and down. 

###Rules of the game
* If you shoot a balloon you will get 20 points. 
* There are total three levels in our game. 
* There are 10 balloons and 6 arrows in first level. 
* If you get a minimum score of 100, you will be eligible for entering in second level. 
* If you not get this minimum score, you are not qualified for second level and game will be over and you are looser. 
* There are 8 balloons and 6 arrows in second level. 
* If you get a minimum score of 180, you will be eligible for entering in third level. 
* In third level there are 6 balloons and 6 arrows. 
* If you completed all the three levels, you will be winner. Yay!

The up and down arrow key are used for positioning the bow. The space key will be used for shooting. 

##Different Functions used in the project:-

####void draw_balloon(int ,int ):
> This function is used for drawing a balloon. In this function we first use setcolor and setfillstyle which set the color red and also filling style. After this we are using fillellipse for drawing the ballon and line for drawing the thread.

#####void draw_burst ( int x, int y ): 
> This function is used for making the image of bursting of balloon. 

#####void draw_bow(int x, int y):
> This function is used for drawing the bow. In this, we are using setcolor, setlinestyle for setting the color and style of the line. After that we are using line and arc functions for drawing the bow.

#####void draw_arrow(int x, int y):
> This function is used for drawing the arrow. In which we are using linerel for drawing the arrow by considering the relative position of each line.

#####void shoot(int *x, int *y):
> In this function we put the image of the arrow on the screen when it desired. After shooting an arrow we decrease the number of arrows. Here we also display the number of remaining arrows. Pointers are used to pass the coordinates by reference.

#####void fly(int *x, int *y):
> This function is used for flying the balloons. The balloons will fly from lower portion of the screen to upper portion. If one balloon crosses the screen or is shot then there is a decrement in number of balloons. We also display the number of remaining balloons in this function.

#####void start():
> This function is used for showing our welcome screen. Here we are using setbkcolor, settextstyle, setcolor, setusercharsize, outtextxy and in last clearviewport for clearing the welcome screen.

#####int testkeys():
> This function is used for getting the ascii code and scan code for the key pressed. 
