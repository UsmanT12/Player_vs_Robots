# Player_vs_Robots
This is a multi-file project that uses the C++ compiler to run the game. The objective is for the player
to shoot at robots and avoid them in order to survive. The player spawns at a random location on a 2D 
(15 x 10) grid, as an '@'. If a robot is ever on the same position as the player, the player loses and 
the game ends. 150 robots also spawn at random locations at the start of the game (This is changeable 
in the main function (rows, col, number of robots)). The robots spawn as the number of robots on each 
position or an 'R' if there is only 1 robot on the position (The max number of robots on one grid 
position is 9). An example 4 robots on a position would display '4' on that positon. Each position on 
the grid in which there are no robots or the player, display '.'. The player is given the controls of 
shooting up, down, left, and right with a 1/3 chance of missing the shot, the controls of moving in any 
of the 4 directions, and a computer generated move. 

To increase the number of rows/columns/robots: enter the values into the game function in main
game (number of rows, number of columns, number of robots)

Shooting controls: 'su', 'sr', 'sd', 'sl' (shoot up, shoot right, shoot down, shoot left)
Moving controls: 'u', 'r', 'd', 'l' (move up, move right, move down, move left)
Computer move: 'c'
