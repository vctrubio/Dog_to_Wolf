Cube3d V2.

GOAL
Create a static call for t_game, to be able to call it from any function and move the pos_x pos_y cordinates of t_img (t_game->p) aka player

ACCOMPLISH
special focus on key_hooks and key_loop_hook- read the difference
_game() can now be called from anywhere and returns
can move the red pixel in 1 of 4 dirrections, but can't move in diagonal (2 key pressed at the same time)
K_R will redraw the window to all black

TO LOOK FOWARD TO
When the red pixel moves, leaves to trace behind
V3 will consist of a constant redraw of the window, so the red dot is only drawn when it is, not where it was
