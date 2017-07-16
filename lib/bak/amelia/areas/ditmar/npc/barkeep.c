#include <lib.h>
inherit LIB_BARKEEP;
#include "ditmar.h"

int Blah();

static void create() {
   barkeep::create();
   SetTown("Ditmar");
   SetKeyName("Bayke");
   SetShort("Bayke, the bartender");
   SetId( ({ "bartender","bayke" }) );
   SetAdjectives( ({ }) );
   SetLong("Bayke is a large mar with abnormally scraggly fur and squinty eyes.  "
           "He hunches over in a particularly worrisome sort of way, wondering "
           "who is going to make trouble in his bar next.  He has a particular "
           "fear of strangers.");
   SetRace("mar");
   SetClass("merchant");
   SetClass("rogue");
   SetLevel(13);
   SetGender("male");
   SetLocalCurrency("kuique");
   SetMorality(-300);
   SetMenuItems( ([
                    "stalag" : D_OBJ + "/stalag",
                    "stalact" : D_OBJ + "/stalact",
                    "galact" : D_OBJ + "/galact",
               ]) );
   SetEncounter((:Blah:));
   SetCurrency("kuique",32000 + random(500));
   SetInventory( ([
                    D_OBJ + "/robe" : "wear robe",
               ]) );
}

int Blah() {
   object who = this_player();
   object me = this_object();
   if(who->GetReligion() != "Marn" && who->GetRace() != "mar" &&
      who->GetTown() != "Ditmar") {
      me->eventForce("!speak in marin We don't like your kind around here.  Only "
                     "the marn, mar, and ditmarites are allowed inside my bar!  "
                     "So get out!");
      me->eventForce("!bump " + who->GetKeyName());
      return 20;
   }
   else {
      me->eventForce("!speak in marin Welcome, " + who->GetCapName());
   }
   return 0;
}