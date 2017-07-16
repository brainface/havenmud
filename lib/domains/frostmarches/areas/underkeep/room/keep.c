//
// Outside the throne room
// by Ranquest@Haven
//
#include <lib.h>
#include "main.h"
  inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("entrance to the throne room");
  SetLong("A forbidding obsidian door lies ahead to the south,"
          " set in an ornately carved wooden frame. The wood has"
          " flaked off in places though, showing the solid iron"
          " beneath. The floor is carved from stone and inset with"
          " pictures of battles long forgotten. To the east and west,"
          " rubble prevents passage to other parts of the keep.");
  SetClimate("underground");
  SetAmbientLight(1);
  SetExits( ([
    "north" : RNQ_RM + "bailey.c",
    "south" : RNQ_RM + "throne.c",
    ]) );
  SetItems( ([
    ({"frame","wood"}) : "The wooden frame has carvings of battle "
      "scenes of long ago.",
    "iron" : "This iron has not rusted like the rest around here.",
    ({"floor","stone",}) : "The stone floor would appear to be made"
      " of granite.",
    ({"pictures carved on the door","pictures","picture"}) : 
      "One of the more striking pictures shows"
      " a warlord ordering the pillage of the enemy castle.",
    "rubble" : "The rubble is fairly tightly packed here.",
    ({"carving","carvings"}) : "The carving is of superior quality,"
      " obviously done by an expert, and has been laminated to preserve"
      " it so well down the centuries.",
    ]) );
  SetItemAdjectives( ([
    "floor" : "stone",
    "frame" : ({"wood","wooden","ornately","carved"}),
    "pictures" : "carvings",
    ]) );
  SetSmell( ([
    "default" : "The smell of the decay of the tomb is prevalent.",
    ]) );
  SetInventory( ([
    RNQ_NPC + "deathknight" : 1,
    ]) );
  SetDoor("south", RNQ_OBJ + "door2");
}
