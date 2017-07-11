#include <lib.h>
inherit LIB_BARKEEP;
#include "../monastery.h"

static void create() {
   barkeep::create();
   SetTown("Soleil");
   SetProperty("monasterynoleave",1);
   SetKeyName("Kient");
   SetShort("Kient, the Eclatish barkeep");
   SetId( ({ "barkeep","barkeeper","kient" }) );
   SetAdjectives( ({ "eclatish","eclat" }) );
   SetLong("Kient works hard at keeping his tavern clean and "
           "happy.  He smiles joyously, standing behind the counter "
           "and cleaning things off.");
   SetRace("muezzin");
   SetGender("male");
   SetClass("merchant");
   SetSkill("melee combat",1, 2);
   SetLevel(20);
   SetReligion("Eclat","Eclat");

   SetCurrency("cuicui",10 + random(10));
   SetMenuItems( ([
                    "beer" : M_OBJ + "beer2",
                    "meza" : M_OBJ + "meza",
               ]) );
   SetInventory( ([
				M_OBJ + "meza" : 1,
		]) );
   SetMorality(600);
}