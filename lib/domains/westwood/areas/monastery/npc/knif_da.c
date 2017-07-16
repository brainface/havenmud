#include <lib.h>
inherit LIB_TRAINER;
#include "../monastery.h"

static void create() {
   trainer::create();
   SetTown("Soleil");
   SetProperty("monasterynoleave",1);
   SetKeyName("daitum");
   SetShort("Daitum, the knife trainer");
   SetId( ({ "daitum","knife trainer","trainer" }) );
   SetLong("Daitum is tall and wily, especially trained in the use of "
           "knife weapons.  He has spent his entire life training in them, "
           "and now teaches others about them.");
   SetRace("muezzin");
   SetClass("fighter");
   SetSkill("knife combat",1,1);
   SetLevel(55);
   SetGender("male");

   
   SetInventory( ([
                    M_OBJ + "knif_d" : "wield knife in right hand",
               ]) );
   AddTrainingSkills("knife combat");
   SetMorality(500);
   SetCurrency("cuicui",26 + random(25));
}
