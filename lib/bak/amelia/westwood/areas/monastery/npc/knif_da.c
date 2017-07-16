#include <lib.h>
inherit LIB_TRAINER;
#include "../monastery.h"

static void create() {
   trainer::create();
   SetProperty("monasterynoleave",1);
   SetKeyName("Daitum");
   SetShort("Daitum, the pierce trainer");
   SetId( ({ "daitum","pierce trainer","trainer" }) );
   SetLong("Daitum is tall and wily, especially trained in the use of "
           "pierce weapons.  He has spent his entire life training in them, "
           "and now teaches others about them.");
   SetClass("valkyr");
   SetSkill("pierce attack",75,1);
   SetSkill("pierce defense",75,1);
   SetLevel(55);
   SetGender("male");
   SetRace("muezzin");
   SetInventory( ([
                    M_OBJ + "knif_d" : "wield knife in right hand",
               ]) );
   AddTrainingSkills("pierce attack");
   AddTrainingSkills("pierce defense");
   SetMorality(500);
   SetCurrency("cuicui",10000);
}
