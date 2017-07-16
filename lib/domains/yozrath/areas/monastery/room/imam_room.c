// Monastery
// Aerelus
// 06/05/2006

#include <lib.h>
#include <domains.h>
#include "../monastery.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(30);
  SetClimate("indoors");
  SetShort("an important looking office");
  SetLong(
    "This small room seems home to an important individual. A large wooden "
    "desk, covered with paper, rests against the southern wall. The "
    "substantial bookshelf against the eastern wall is packed full of "
    "ancient-looking volumes, some of which have started to decay. A "
    "luxurious freshly-made bed in the center of the room looks inviting. "
    "A passage to the west leads to the main worship hall, while another to "
    "the north leads to a dining area."
  );
  SetItems( ([
  ({ "room" }) : (: GetLong :),
  ({ "desk", "paper" }) :
    "The desk is covered with pieces of paper.",
  ({ "bookshelf", "volumes", "books" }) :
    "The substantial bookshelf is full of ancient books.",
  ({ "bed" }) :
    "This looks like a nice place to sleep.",
  ({ "southern wall" }) :
    "There is a desk resting against this wall.",
  ({ "eastern wall" }) :
    "There is a bookshelf filled with ancient-looking volumes against this "
    "wall.",
  ({ "passage", "passages" }) :
    "The western passage leads to the main worship hall, while the "
    "northern passage leads to a dining area.",
  ({ "wall" }) :
    "Do you mean the southern wall, or the eastern wall?",
  ]) );
  SetItemAdjectives( ([
    "bed" : ({ "luxurious", "freshly-made", "inviting" }),
    "desk" : ({ "large", "wooden" }),
    "bookshelf" : ({ "substantial", "ancient", "ancient-looking" }),    
    "room" : ({ "small" }),
  ]) );
  SetInventory( ([
    AREA_NPC "imam" : 1,
    AREA_NPC "guard" : 3,
  ]) );
  SetListen( ([
    "default" : "The sounds of deep chanting can be heard.",
  ]) );
  SetSmell( ([
    "default" : "The smell of freshly baked bread from the north hangs in "
    "the air.",
  ]) );
  SetExits( ([
    "west" : AREA_ROOM "main_hall",
    "north" : AREA_ROOM "kitchen",
  ]) );
}

/** Approved by Laoise at Sun May 21 17:03:05 2006. **/