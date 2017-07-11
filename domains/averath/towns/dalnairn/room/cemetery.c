#include <lib.h>
#include <std.h>
#include "../dalnairn.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("the Dalnairn cemetery");
   SetExits( ([
      "out" : DAL_ROOM "road9",
   ]) );
   SetLong("The Dalnairn cemetery is quiet and peaceful. Hundreds of small "
     "stones mark the names of those buried beneath, some more impressive "
     "than others. The gate to the south leads to the city.");   
   SetNightLight(20);
   SetItems( ([
      ({ "cemetary" }) : (: GetLong :),
      ({ "stones", "names" }) : "These stones each mark the resting place of "
        "those who have died in or around Dalnairn.",
      ({ "gate" }) : "The gate to the south leads to the city.",      
   ]) );
   SetItemAdjectives( ([
         "cemetary" : ({ "dalnairn"}),
         "stones" : ({ "small" }),         
   ]) );
   SetListen( ([
      "default" : "The graveyard has the stillness of death.",
   ]) );
   SetSmell( ([
      "default" : "The smell of freshly dug earth wafts the air.",
   ]) );   
   SetProperty("no attack",1);
  SetInventory( ([
    STD_OBJ "reztotem" : 1,
  ]) );
}
