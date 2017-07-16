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
  SetShort("the outer bailey of Targoviste");
  SetLong(
    "A large building stands immediately to the east, a sign "
    "above its entrance depicting a pair of crossed swords. "
    "South of the arched doorway are a set of iron rings, secured "
    "firmly to the stone blocks which form the building. Long "
    "chains attach to these rings before trailing up to a "
    "gatehouse set upon the battlements of the inner wall. To "
    "the north the outer bailey continues, circumnavigating the "
    "inner keep of the stronghold. South of here is the main "
    "conduit of Targoviste."
  );
  SetItems( ([ 


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "The murmer of voices, interspersed with occasional "
    "clangs, comes from the east.",
  ]) );
  SetSmell( ([
    "default" : "There is a faint smell of peat.",
  ]) );
  SetExits( ([ 
    "north" : TARG_ROOM "west_wall5",
    "south" : TARG_ROOM "west_wall3",
    "east" : TARG_ROOM "barracks1",
  ]) );
}
