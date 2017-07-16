#include <lib.h>
inherit LIB_NPC;
#include "ditmar.h"

int Blah();

static void create() {
   npc::create();
   SetTown("Ditmar");
   SetKeyName("gatekeeper");
   SetShort("a mar gatekeeper");
   SetId( ({ "mar","gatekeeper","gatekeep","keeper" }) );
   SetAdjectives( ({ "mar","old" }) );
   SetLong("The old gatekeeper glares at all non-mar beings with "
           "suspicion, as if anyone else is unworthy.  He seems "
           "to back off if one shows that they belong to the local "
           "religion or are a citizen of the town, however.");
   SetRace("mar");
   SetSkill("melee attack",1,1);
   SetSkill("melee defense",1,1);
   SetSkill("faith",1,1);
   SetSkill("evokation",1,1);
   SetLevel(10);
   SetGender("male");
   SetEncounter( (: Blah :) );
   SetInventory( ([
                    D_OBJ + "/robe" : "wear robe",
               ]) );
}

int Blah() {
   object guy = this_player();
   if(guy->GetInvis() == 1) return 0;
   if( (guy->GetRace() == "mar") || (guy->GetReligion() == "Marn") ||
       (guy->GetTown() == "Ditmar") ) {
      object *blah = deep_inventory(guy);
      int x = 0;
      foreach(object gr in blah) {
         foreach(string hrm in gr->GetId()) {
            if(hrm == "ditmar_gate_key") x = 1;
         }
      }
      if(!x) {
         object wibble = new(D_OBJ + "/key");
         wibble->eventMove(guy);
      }
   }
   else {
      eventForce("!glare " + guy->GetKeyName());
   }
   return 0;
}