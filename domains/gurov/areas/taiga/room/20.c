//Illura@haven
//Room 20
//August 2009
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../taiga.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("arctic");
  SetShort("Near a bridge of ice");
  SetLong(
    "The Gurovian tundra extends in all directions except north, "
    "where in the distance a crystalline bridge of ice extends "
    "across a seemingly bottomless rift in the ground. Here stand "
    "shapeless masses of snow and ice, blanketing everything with "
    "an empty, haunting whiteness."
  );
  SetExits( ([
    "south" : TAIGA_ROOM "17",

    "north" : TAIGA_ROOM "23",
    "east" : TAIGA_ROOM "21",
  ]) );
  SetItems( ([
    "bridge" : "The slender, graceful bridge of ice crystal looks formed neither by the hands of man nor natural means, but seems magic in nature. It crosses to a platform of ancient ice across the giant rift in the flesh of Kailie.",
    "ice" : "The ice which the bridge is made of is cloudy with age, but mostly unmarred. It seems very solid.",
    "rift" : "The abyss extends further than you can see. You would not want to slip and fall here.",
    ({"masses", "snow"}) : "The snow is piled in strange, indistinct shapes.",
  ]) );
  SetItemAdjectives( ([
    "bridge" : "crystalline",
    "rift" : "bottomless",
    "masses" : "shapeless"
  ]) );
  SetInventory( ([
    TAIGA_NPC + "windrider" : 3,
    TAIGA_NPC + "moorwalker" : 1,
  ]) );
  SetListen( ([
    "default" : "Spookily enough, the winds are silent and breathy here.",
  ]) );
  SetSmell( ([
    "default" : "An ancient forboding disturbs your senses.",
  ]) );
}
