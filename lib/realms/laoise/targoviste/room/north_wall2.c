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
  SetDomain("Estergrym");
  SetTown("Targoviste");
  SetShort("within the outer bailey of Targoviste");
  SetLong(
    "A building connects to the bailey from the south, its "
    "entrance surmounted by a sign depicting a pair of crossed "
    "swords. To the east of the entrance, iron rings are set in to "
    "the blocks which form the building. Chains run from these rings, "
    "trailing up the inner wall of the stronghold, to a gatehouse "
    "which is set atop the inner wall. East and west of here the "
    "bailey continues, its obsidian stone of a black color that is "
    "polished to a faint gloss. Dark red flecks appear intermittently, "
    "appearing to float just beneath the surface of the marble."
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "The murmer of voices, interspersed with occasional "
    "clangs, comes from the south.",
  ]) );
  SetSmell( ([
    "default" : "A mild touch of peat tinges the air.",
  ]) );
  SetExits( ([ 
    "south" : TARG_ROOM "barracks3",
    "east" : TARG_ROOM "north_wall3",
    "west" : TARG_ROOM "north_wall1",

  ]) );
}
