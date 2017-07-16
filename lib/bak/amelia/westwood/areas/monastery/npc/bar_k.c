#include <lib.h>
inherit LIB_BARKEEP;
#include "../monastery.h"

static void create() {
   barkeep::create();
   SetProperty("monasterynoleave",1);
   SetKeyName("Kient");
   SetShort("Kient, the Eclatish barkeep");
   SetId( ({ "barkeep","barkeeper","kient" }) );
   SetAdjectives( ({ "eclatish","eclat" }) );
   SetLong("Kient works hard at keeping his tavern clean and "
           "happy.  He smiles joyously, standing behind the counter "
           "and cleaning things off.");
   SetClass("valkyr");
   SetLevel(20);
   SetSkill("bargaining",3);
   SetReligion("Eclat","Eclatish");
   SetGender("male");
   SetRace("muezzin");
   SetCurrency("cuicui",10500+random(300));
   SetMenuItems( ([
                    "beer" : M_OBJ + "beer2",
                    "meza" : M_OBJ + "meza",
               ]) );
   SetInventory( ([
				M_OBJ + "meza" : 1,
		]) );
   SetMorality(600);
}