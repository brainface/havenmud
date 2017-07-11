//Illura@haven
//ship1
//Nov 2010
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../oil.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetShort("inside the ship");
  SetLong(
    "This ship's cargo hold is dark and stinks of bilge and offal. "
    "Sconces on the walls hold candles that have been burned "
    "down to nubs, and moth eaten pallets line the floors. "
    "All in all, it is dingy and filthy in here. A long corridor "
    "leads west, deeper into the ship, and a way out is here."
  );
  SetExits( ([
    "west" : OIL_ROOM "/ship2",
    "out" : OIL_ROOM "/a4"
  ]) );
  SetItems( ([
    ({"hold"}) : "You are inside the cargo hold of a ship.",
    ({"sconces", "sconce"}) : "The brass sconces hold candles.",
    ({"candles", "candle", "nubs", "nub","wax"}) : 
      "The candles have been burned down to nothing, and wax has "
      "dripped on the floor in a most unappealing way.",
    ({"pallet", "pallets","straw"}) : 
      "The pallets served as beds for the sailors of this ship "
      "to take their rest upon. They are full of moth holes and "
      "the straw within is crushed flat with the pressure of "
      "sleeping bodies.",
    ({"corridor"}) : "The length of the ship extends westward."
  ]) );
  SetItemAdjectives( ([
    "hold" : ({"cargo"}),
    "pallets" : ({"moth eaten"}),
    "corridor" : ({"long"}),
	"sconce" : ({"brass"}),
  ]) );
  SetInventory( ([
    OIL_NPC + "sailor" : 3,
  ]) );
  SetListen( ([
    "default" : "The ship creaks and groans.",
  ]) );
  SetSmell( ([
    "default" : "The stench is pretty powerful.",
  ]) );
}
