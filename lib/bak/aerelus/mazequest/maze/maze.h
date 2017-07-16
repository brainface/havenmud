#define MAZE "/domains/planes/virtual/maze/"
#define START MAZE + "6,0"
#define END MAZE + "37,-18"
#define LIB_MAZE "lib_maze.c"
#define MAZE_NPC MAZE + "npc/"
#define MAZE_OBJ MAZE + "obj/"


string *Longs = ({
"The ground is very damp, and even rocky in places.",
"Various trees grow throughout the maze, allowing very little light to penetrate the canopy.",
"The view of the sky from here is blocked by the towering hedges and tall trees.",
"The hedges seem to move ever so slightly, despite the lack of wind.",
"A sparse green mist drifts over the ground here.",
"There some rocks here, near the path through the maze.",
}) ;

string *Smells = ({
"The scent of decaying wood hangs in the air.",
"The air is damp.",
"There is no wind here, only a moist smell of decay.",
});

string *Listens = ({
"Rustling can be heard from the hedges.",
"The maze seems deathly quiet.",
"The maze seems to abound with the sounds of life.",
"The quiet on the air is disturbing.",
"The faint sound of giggling can be heard to the southeast.",
"The faint sound of giggling can be heard to the southwest.",
"The faint sound of giggling can be heard to the northeast.",
"The faint sound of giggling can be heard to the northwest.",
});
