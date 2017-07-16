//Illura@haven
//Room 6
//August 2009
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../taiga.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("temperate");
  SetShort("A glacial swamp");
  SetLong(
    "The ground here is boggy and wet, studded with tiny ponds "
    "left in hollowed ground, carved by ancient, slowly receeding "
    "glaciers. The brackish water is dark with dissolved minerals "
    "and strewn with fallen pine needles. The taiga extends in all "
    "directions from here."
  );
  SetExits( ([
    "south" : TAIGA_ROOM "3",
    "east" : TAIGA_ROOM "7",
    "north" : TAIGA_ROOM "9",
    "west" : TAIGA_ROOM "5",
  ]) );
  SetItems( ([
    ({"pond", "ponds", "ground"}) : "The ground is wet and covered with deep puddles.",
    "water" : "The water is dark and brackish.",
    "needles" : "Needles cover the ground and float in the ponds.",
  ]) );
  SetItemAdjectives( ([
    "ponds" : "tiny",
    "ground" : "hollowed",
    "water" : "brackish",
    "needles" : "pine",
  ]) );
  SetInventory( ([
    TAIGA_NPC + "moorfrog" : 3,
  ]) );
  SetListen( ([
    "default" : "Wind ruffles the pine branches and cold water.",
  ]) );
  SetSmell( ([
    "default" : "The fragrance of brackish fog smothers the area.",
  ]) );
}
