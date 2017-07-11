#include <lib.h>
inherit LIB_NPC;
#include "../hospital.h"

static void create() {
   npc::create();
   SetProperty("noleavehospital",1);
   SetKeyName("receptionist");
   SetShort("the hospital receptionist");
   SetMorality(300);
   SetId( ({ "muezzin","receptionist" }) );
   SetAdjectives( ({ "hospital","muezzin","eclat" }) );
   SetLong("Quick and efficient, the receptionist organizes files and "
           "directs doctors around if they ask questions.  He "
           "looks to have been trained as a fighter, but has probably "
           "had experience with healing, as well, since he works at a "
           "hospital.  He doesn't look to be overall experienced at "
           "any of his skills, however, which is probably why he got the "
           "desk job.");
   SetReligion("Eclat","Eclat");
   SetClass("fighter");
   SetSkill("melee combat",1,2);
   SetLevel(15);
   SetGender("male");
   SetRace("muezzin");
   SetFriends( ({ "doctor","Zoa","patient","receptionist" }) );
}

