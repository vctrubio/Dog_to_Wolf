Cube3d V4.

Added a char variable to the s_map struct to identify the character used to define the player and the position (Added it to the map struct in so it would not demand more inicializations on the map parsing functions)

In parse.c added a map_verify function to verify the borders of the map. I'ts still under construction, it already works for the upper, right side and down side.



GOAL
To parse a map, with player at position p
Raycast into a 3D world
move around

ACCOMPLISH
-minimap showing player position
-TODO: raycast the map

TO LOOK FOWARD TO
-minimap that shows rays
-enemies
