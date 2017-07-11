#include <lib.h>
#include <std.h>
#include "../averath.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("the Averath cemetery");
   SetExits( ([
      "out" : AVERATH_ROOM "road2",
   ]) );
   SetLong("The Averath cemetery is a peaceful place, covered with grass. "
     "Various sized tombstones mark the final resting place of some of the "
     "cities more important citizens. A small metal gate to the north leads "
     "back to the city.");   
   SetNightLight(20);
   SetItems( ([
      ({ "cemetary" }) : (: GetLong :),
      ({ "tombstones" }) : "These stones each mark the resting place of "
        "those who have died in or around Averath.",
      ({ "gate" }) : "The gate to the north leads to the city.",      
   ]) );
   SetItemAdjectives( ([
         "cemetary" : ({ "averath"}),
         "tombstones" : ({ "various", "sized" }),
         "gate" : ({ "small", "metal" }),
   ]) );
   SetListen( ([
      "default" : "The graveyard has the stillness of death.",
   ]) );
   SetSmell( ([
      "default" : "The smell of freshly dug earth wafts the air.",
   ]) );   
   SetInventory( ([
     STD_OBJ "reztotem" : 1,
   ]) );
}
