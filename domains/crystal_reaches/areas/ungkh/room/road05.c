//Selket@Haven
//2006
#include <lib.h>
#include "../ungkh.h"
#include <domains.h>
inherit LIB_ROOM;

static void create() {

  room::create();
  SetShort("in front of a low stable");
  SetLong(
    "Here among the various buildings that belong to the citizens "
    "of Ungkh stands a small stable built from large granite blocks, "
    "and even the roof is made of slate, rather than thatching. The "
    "streets are heavily beaten here under the feet of many large "
    "men, as this seems to be the meeting spot for several giants. "
    );
  SetSmell("The foreboding scent of death comes from the stable. ");
  SetListen("A rushing warm wind occasionally comes from the stable.");
  SetItems( ([
    ({ "stable" }) :
       (: GetLong :),
    ({ "buildings" }) :
    "The buildings of the village are shabby structures.",
    ({ "granite", "blocks", "slate", "roof" }) : 
    "The stable is made of stone, for some strange reason.",
    ({ "streets", "street" }) : "The streets are disgusting and "
    "filled with trash of all kinds.",
    ]) );
  SetItemAdjectives( ([
    "stable" : ({ "small", "low" }),
    "streets" : ({ "filthy" }),
    "blocks" : ({ "large" }),
    ]) );
  SetEnters( ([
   "stable" : U_ROOM + "stable",
    ]) );
  SetExits( ([
    "west" : U_ROOM + "road04",
    "east" : U_ROOM + "road06",
    "south" : U_ROOM + "road10",
    ]) );
  SetInventory( ([
    U_NPC "stump" : 1,
    U_NPC "stompy" : 1,
    U_NPC "stonecrusher" : 1,
  ]) );
  }
