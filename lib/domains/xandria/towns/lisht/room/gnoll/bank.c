//Selket@Haven
//2006

#include <lib.h>
#include "../../lisht.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(50);
   SetTown("Lisht");
   SetShort("Bank of Lisht");
   SetObviousExits("out");
   SetProperty("no bump",1);
   SetExits( ([
      "out" : LISHT_ROOM "gnoll/tr1",
   ]) );
   SetLong("The Bank of Lisht is a small building open at all hours, "
           "where one can perform various transactions. The windows "
           "here are small and round, and made of an amber glass that "
           "filters the light into the room with an almost golden "
           "glint.");
   SetItems( ([
      ({ "bank of lisht", "bank" }) : 
         (: GetLong :),
      ({ "window", "windows", "light" }) :
         "The windows let in light from outdoors while changing it "
         "into a sparkling golden hue, reminding one of money. ",
   ]) );
   SetItemAdjectives( ([
      "bank" : ({ "lisht" }),
      "window" : ({ "small", "round", "amber", "glass" }),
   ]) );
   SetInventory( ([
      LISHT_NPC "sahure" : 1,
   ]) );
}
