#include <lib.h>
#include <domains.h>
#include "../karak.h"
inherit LIB_ROOM;
int DomainCheck();

static void create() {
  room::create();
  SetShort("Ahriman's Passage");
  SetExits( ([
    "west"  : K_ROOM + "/rd2",    
    ]) );
  AddExit("north", SOUTHERN_COAST_VIRTUAL "havenroad/-36,0", (: DomainCheck :) );
  SetDayLong("The massive and heavily fortified gate of Karak Varn "
             "looms at the edge of the city. Everything around seems "
             "to be solidly "
             "constructed from massive blocks of a dark grey granite, "
             "reinforced by almost superfluous butresses and pillars of "
             "brass and iron. To the north is a great iron portcullis "
             "easily fifteen meters high, beyond which is the foothills "
             "of the Crystal Reaches. To the west is the mighty "
             "fortress of Karak Varn. A small armoury is sitting to the side of the road.");
  SetNightLong("This huge gatehouse would be completely shrouded in the "
               "dark shroud of night if not for the handful of torches "
               "burning in nearby parapets.  To the north lie the foothills "
               "of the Crystal Reaches, and to the west is the city of "
             "Karak Varn. A small armoury is sitting to the side of the road.");
   SetItems( ([
    "armoury" : "It is a small armoury sitting next to the road, it most likely sells all types of armour.",
    ]) );
  SetEnters( ([
    "armoury" : "/domains/crystal_reaches/areas/platemailstore/kelansstore",
    ]) );

}

int DomainCheck() {
  if (!OPEN_SOUTHERN_COAST)
    this_player()->eventPrint("Further travel in that direction is not allowed right now.");
  return OPEN_SOUTHERN_COAST;  
}
