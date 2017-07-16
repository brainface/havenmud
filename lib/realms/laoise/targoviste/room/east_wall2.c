// Targoviste
// Laoise
// August 2004

#include <lib.h>
#include <domains.h>
#include "../targoviste.h"
inherit LIB_ROOM;

static void create() 
{
  room::create();
  SetDayLight(-20);
  SetTown("Targoviste");
  SetShort("the outer bailey of Targoviste");
  SetLong(
    "A building sits to the west, a curl of smoke rising from "
    "its chimney. Set flush against the inner wall of the keep, "
    "this building is curved to the northwest, following the line "
    "of the wall. Above its door is a plaque carved with the "
    "symbol of a beer stein and a plate piled high with food. "
    "The main passage through the city lies to the south, while "
    "the outer bailey continues to the north. The formidable "
    "Estergrym Mountains surround Targoviste on all sides, "
    "dwarfing even the massive walls of this fortress."
  );
  SetItems( ([ 
    ({ "building", "tavern", "bar", "pub" }) : "The local.",


  ]));
  SetItemAdjectives( ([
    "building" : ({ "west", "western", "nearby" }),


  ]) );
  SetListen( ([ 
    "default" : "A rumble of voices comes from the building to the "
    "west.",
  ]) );
  SetSmell( ([
    "default" : "The smell of cooking wafts through the air.",
  ]) );
  SetExits( ([ 
    "north" : TARG_ROOM "east_wall1",
    "south" : TARG_ROOM "east_wall3",
  ]) );
  SetEnters( ([
    "bar" : TARG_ROOM "bar1",
  ]) );
}
