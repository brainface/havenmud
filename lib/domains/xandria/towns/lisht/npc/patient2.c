//Selket@Haven
//2006
#include <lib.h>
#include <damage_types.h>
#include <std.h>
#include "../lisht.h"
inherit LIB_NPC;

static void create() {
   npc::create();
   SetMorality(-100);
   switch(random(2)) {
      case 0:
      SetGender("female");
      break;
      case 1:
      SetGender("male");
      break;
   }
   SetKeyName("patient");
   SetShort("a patient of the wasting sickness");
   SetId( ({ "patient", "sickness" }) );
   SetAdjectives( ({ "of","the","wasting" }) );
   SetLong("This patient has been quarantined here to recover "
           "from a deadly sickness. Only the most skilled of doctors "
           "can hope to rid the gnoll of the spreadable disease. "
   );
   SetRace("gnoll");
  SetBaseLanguage("Rehshai");
   SetClass("rogue");
   SetSkill("melee combat",1,1);
   SetSkill("melee combat",1,1);
   SetLevel(4+random(4));
   AddHealthPoints(-(GetHealthPoints()/3));
   SetInventory( ([
                    STD_GERMS + "/waste_sick" : 1,
                    LISHT_OBJ "shenti" : "wear shenti",
               ]) );
}
