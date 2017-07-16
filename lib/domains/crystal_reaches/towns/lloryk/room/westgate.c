#include <lib.h>
#include <daemons.h>
#include <std.h>
#include "../path.h"
inherit LIB_ROOM;

int CheckGuard(string dir);

static void create() {
  room::create();
  SetShort("the western gate of the Shire");
  SetLong("To the west, the Gwonish Swamp lies full of foreboding evil. "
          "The western gate is an impressive structure of stone and wood, "
          "and looks quite capable of keeping the lizardmen of the swamp "
          "from overrunning the Shire. To the east, the road opens up as "
          "it gets closer to the heart of the Shire.  Off to the northeast "
          "and southeast, the rolling hills of the Shire look warm and "
          "inviting."
    );
  SetItems( ([ 
    "gate" : "The western gate of the Shire is made of stone and wood "
             "and is a stout, defensive design.",
    "swamp" : "The Gwonish Swamp is a place of ancient evil.",
    ({ "hill", "hills" }) : "The hills of the Shire make excellent farmland.",
    ]) );
  SetItemAdjectives( ([
    "swamp" : ({ "evil", "gwonish" }),
    "gate"  : ({ "western", "west" }),
    ]) );         
  SetInventory( ([ 
    LLORYK + "npc/guard": 1,
    ]) );
  SetListen( ([
    "default" : "The occasional rustle of the trees is all that can be heard "
                "from the swamp.",
    ]) );
  SetSmell( ([
    "default" : "Smells of rotting trees and death come from the swamp.",
    ]) );
  SetExits( ([
    "east" : LLORYK + "room/hb1",
    ]) );
  AddExit("west", GWONISH + "room/path1", 0, (: CheckGuard :) );
}

int CheckGuard(string dir) {
  object guard, player;
  player = this_player();
  if (guard = present("guard")) {
    if (player->GetInvis() == 0) 
    guard->eventForce("yell " 
      "Use caution, " + player->GetCapName() + ". The Lizardmen "
      "have been restless of late."
      );
    if (!random(500)) 
      INVASION_D->eventRegisterInvasion(new(STD_INVASIONS "shire_lizardmen/lmil_inv"), this_player());
    return 1;
    }
  return 1;
}
