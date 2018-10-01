/* 'ohtar (imm) Make a bathroom!'*/
#include <lib.h>

// mikes includes dir
#include "../mahk.h"

// must be in all rooms
inherit LIB_ROOM;

static void create() {
  // get it started
  room::create();

  SetClimate("indoors");
  SetAmbientLight(20); // I hope this is dark?
  SetShort("a well-used outhouse");
  SetLong(
    "This small shack has obviously been used as an outhouse for years. A wooden "
    "privy sits on the earthern floor opposite the door, and a shelf sits on the "
    "eastern wall. Rays of light dimly illuminate the interior from a small window "
    "on the door."
  ); 

  SetItems( ([
    ({"shack","outhouse"}) :
      (: GetLong :),
    ({"window"}) : 
      "The window in the door has been crudely sawn into a crescent shape. ",
    ({"ray","rays","light","rays of light"}) :
      "Sunmotes dance in the rays "
      "of light",
    ({"wall"}) :
      "The walls are made from coarse planks of lumber. Pieces of bark are "
      "still attached in places.",  
    ({"privy"}) : 
      "The privy is a simple raised wooden seat with an obvious hole in the "
      "center",
    ({"hole"}) : 
      "The hole descends into the bare earth",
    ({"shelf"}) : 
      "A dank cloth and a jar of something that might be soap sit on a wooden "
      "shelf within reach of the privy.",
    ({"cloth"}) :
      "The cloth is moldy and stained from the washing of many hands.",
    ({"jar"}) :
      "The glass jar holds some cloudy green liquid.",
    ({"floor"}) :
      "Years of bootprints have densely packed the earthern floor.",
    ({"bootprints"}) :
      "The bootprints are of various sizes. A couple of hoofprints can also "
      "be made out on the floor.",
    ({"hoofprints"}) :
      "Too small to be a daemon, these were probably left by a kobold.",
  ]) );

  SetItemAdjectives( ([
   "cloth" : ({"moldy","dank"}),
   "jar" : ({"glass","green"}),
   "hole" : ({"privy"}), 
  ]) );

  SetListen( ([
    "default" : "Flies buzz around purposefully.",
  ]) );

  SetSmell( ([
    "default" : "The building smells worse than a parvan crossroads.",
    "jar" : "The jar smells strongly of soap.",
    "hole" : "The stench of humanoid waste is overwhelming",
    "cloth" : "The cloth smells of mildew"
  ]) );

  SetInventory( ([
     MAHK_NPC + "fly" : 3,
     MAHK_OBJ + "almanac" : 1,
  ]) );

  SetExits( ([
    "north" : "../workroom.c",
  ]) );

  SetDoor("north",MAHK_OBJ "outhouseDoor.c");
}

 
