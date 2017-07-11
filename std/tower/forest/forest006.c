#include <mudlib.h>
#include "../rooms.h"
inherit ARCTIC;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_terrain(TER_FOREST);
  set_cold(1);
  set_short("a forest");
  set_long("\
The forest is getting dense here, and as you wander, you \n\
notice the trees getting thicker.  Further off to the west,\n\
you see that eventually the forest closes off the path that \n\
you are now walking on.  Here however, you can still make your\n\
way through with only minimal difficulty.  The animals of the\n\
forest are frolicking around the forest floor, apparantly \n\
oblivious to the cold.  The snow is very thin here, getting\n\
blocked by the trees and swept clear by the wind.\n");
  add_look("trees","These are normal pines and evergreens.\n");
  add_look("snow","\
The snow is lightly covering the ground, and the \n\
tracks of animals are numerous here.\n");
  add_look("tracks","Wolf tracks seem most predominant, but there are\n\
odd, humanlike prints also.\n");
  add_look("animals","Winter foxes and small white floofy rabbits are playing here.\n");
  set_light(1);
  add_exit("west", FOREST + "/forest011");
  add_exit("east", FOREST + "/forest001");
  add_exit("north", FOREST + "/forest007");
  replace_program(ROOM);
}

