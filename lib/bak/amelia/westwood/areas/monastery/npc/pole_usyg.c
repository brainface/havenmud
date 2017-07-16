#include <lib.h>
inherit LIB_TRAINER;
#include "../monastery.h"

static void create() {
   trainer::create();
   SetProperty("monasterynoleave",1);
   SetKeyName("Usyg");
   SetShort("Usyg, the pole trainer");
   SetId( ({ "usyg","pole trainer","trainer" }) );
   SetLong("Usyg is tall and strong, especially trained in the use of "
           "pole weapons.  He has spent his entire life training in them, "
           "and now teaches others about them.");
   SetClass("valkyr");
   SetSkill("pole attack",75,1);
   SetSkill("pole defense",75,1);
   SetLevel(55);
   SetGender("male");
   SetRace("muezzin");
   SetInventory( ([
                    M_OBJ + "pole_u" : "wield pole in right hand",
               ]) );
   AddTrainingSkills("pole attack");
   AddTrainingSkills("pole defense");
   SetMorality(700);
}