#include <lib.h>
inherit LIB_TRAINER;
#include "../monastery.h"

static void create() {
   trainer::create();
   SetTown("Soleil");
   SetProperty("monasterynoleave",1);
   SetKeyName("Usyg");
   SetShort("Usyg, the pole trainer");
   SetId( ({ "usyg","pole trainer","trainer" }) );
   SetLong("Usyg is tall and strong, especially trained in the use of "
           "pole weapons.  He has spent his entire life training in them, "
           "and now teaches others about them.");
   SetRace("muezzin");
   SetClass("fighter");
   
   SetLevel(55);
   SetGender("male");
 
   SetInventory( ([
            M_OBJ + "pole_u" : "wield pole in right hand",
               ]) );
   AddTrainingSkills("pole combat");
   SetMorality(700);
}