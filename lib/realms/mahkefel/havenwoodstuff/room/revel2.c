/*
  Below the nightreveller tree
*/
#include <lib.h>

#include "../wood.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetDomain("Havenwood");
  SetShort("a twisting nest of branches");
  SetLong("The branches growing from the trunk arc above and below here, "
    "forming something for all the world like a giant bird's nest. Blankets "
    "are sprawled haphazardly across the lower branches, with the occasional "
    "mismatched pillow even, along with a network of hammocks strung out "
    "in a less than necessarily safe fashion from the upper limbs. A spiral "
    "ripple in the central trunk forms enough of a staircase to count.");
  /*SetDayLong(
  );
  SetNightLong(
  );*/
  SetItems( ([ /*
    ({"tree","cypress"}) :
      "A truly ancient cypress, the crown spreads forty paces wide, "
      "enveloping the surrounding forest.",
    ({"floor","ground"}) :
      "A thick layer of old pine needles blankets the forest floor here, "
      "the occasional bit of underbrush trying to poke through.",
    ({"underbrush", "thorns", "wildflowers"}) :
      "Twisting thorns and blooming wildflowers have sprung up here and there.",
    ({"forest", "trees", "woods" }) :
      "Towering old woods dominate this section of the Havenwood. To the "
      "north, however, you can make out a large clearing.",
    ({"clearing"}) :
      "A large and verdant clearing lies to the north",
    ({"foxfires"}) :
      "Tiny green wisps seem to dart in and out of the twisting branches.",
    ({"limbs", "canopy"}) :
      "The limbs of the cypress are gnarled and twisted together, almost "
      "weaved. Occasionally they jostle and jerk, seemingly in time with "
      "music emanating from somewhere further up the tree.",
    ({"leaves", "needles"}):
      "Short evergreen needles, somewhat sharp really. Occasionally a slight "
      "drizzle of them rains down to join the others blanketing the ground, in "
      "time with some more violent lurching in the branches above.",
    ({"detritus", "plates","mugs","fork",}):
      "Wooden plates, mugs, forks, the occasional undergarment, some almost "
      "buried in the layer of needles.",
    ({"staircase"}):
      "The staircase seems formed entirely from the roots of the tree itself, "
      "and more than a little weathered from constant use. Tiny twigs sprout "
      "out here and there and odd angles from it.",
    ({"masks","candles", "wax"}) :
      "Horned wooden masks set into the bark of the tree seem to leer out at "
      "you. The mouths have enough space to hold small candles, their wax "
      "dripping out looking unfortunately a bit too much like drool.",
    ({"trunk"}):
      "The trunk of this old cypress is wider than some houses, and seems "
      "undeterred and unmoved by whatever calamity occurs above.",
    ({"tables"}):
      "A few wooden tables sit beneath the canopy of the cypress, offering "
      "a bit of refuge for those unwilling to brave the calamity above. "
      "Painted scenes of beasts and glens are mostly scuffed and faded.",
    ({"doorway","cavity","roots"}):
      "The gnarled roots of the old cypress snake this way and that. An "
      "opening shaped into them leads into some cavity beneath the tree.",*/
  ]) );
  SetItemAdjectives( ([
    /*"building" : ({"small"}),
    "bushes" : ({"hardy"}),
    "cabin" : ({"log"}),
    "evergreens" : ({"small","stunted","small","stunted","pine","dense"}),
    "hoofprints" : ({"small"}),
    "mountain" : ({"large","rising"}),
    "space": ({"large","open","snow","filled"}),
    "stumps" : ({"rotting"}),
    "trail" : ({"main"}),*/
  ]) );
  SetListen( ([
    "default" : "An astounding chorus of music and merriment pounds through "
      "the branches above.",
    //"default" : "A raccous racket of revelry reverberates through the air.",
  ]) );
  SetSmell( ([
    "default" : "The scent of wine and fir intermingle in the air.",
  ]) );
  SetInventory( ([
    //FENCE_NPC "brash_student.c" : 1,
  ]) );
  SetExits( ([
    "down" : HWD_ROOM "/revel1",
    "up" : HWD_ROOM "/revel3",
  ]) );

}

