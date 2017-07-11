//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include <std.h>
#include "../../lisht.h"

inherit LIB_ROOM;

static void create() {
   ::create();
   SetShort("a valley of tombs");
   SetLong("This desolate valley is the final resting place for many "
          "Lisht citizens. While the poorer souls get tossed into "
          "shallow, scarcely marked graves, the tombs of the wealthy "
          "are grandiose carved mausoleums. However, one stands out "
          "among the rest: A collosal mastaba of mud brick and stone."
          " Perhaps one could enter it, if one wished to chance "
          "an untimely, gruesome death.");
  SetClimate("arid");
   SetItems( ([
      ({ "grave", "graves" }) : 
         "The graves are simple things. Some have markers. ",
      ({ "tomb","tombs", "mausoleum", "mausoleums" }) : 
         "These tombs are large, partially above ground. They "
         "are closed off for all eternity.",
      ({ "mastaba" }) :
         "The mastaba is enormous. The seal on the door looks "
         "as though it has not quite stood the test of time. ",
   ]) );
   SetItemAdjectives( ([
    "mastaba" : ({ "collosal" }),
    "grave" : ({ "shallow", "scarcely marked" }),
    "tomb" : ({ "grandiose", "carved" }),
   ]) );
   SetListen( ([
      "default" : "The valley is deathly quiet.",
   ]) );
   SetSmell( ([
      "default" : "The air smells of sand and faint decay.",
   ]) );
   SetExits( ([
    "east" : LISHT_ROOM "gnoll/tr3",
   ]) );
   SetEnters( ([
    "mastaba" : XANDRIA_AREAS "mastaba_area/room/mastaba1",
   ]) );
  SetInventory( ([
    STD_OBJ "reztotem" : 1,
  ]) );
}
