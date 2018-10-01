#include <lib.h>
inherit LIB_SENTIENT;
#include "../master.h"

static void create() {
   string WEAPON_IS;
   sentient::create();
   SetKeyName("Vale Castle soldier");
   SetShort("a soldier of Vale Castle");
   SetId( ({ "soldier","soldier of vale castle","dwarf" }) );
   SetAdjectives( ({ "male" }) );
   SetLong("The image of a soldier, this man has military drills "
           "forming up half of his personality.  He is stiff and straight "
           "and ready for anything--anything taught in books and classes, "
           "at least.");
   
   SetGender("male");
   SetRace("dwarf");
   SetClass("fighter");
	 SetLevel(24+random(5));
	 
   switch(random(4)) {

      case 0:
      WEAPON_IS = "axe";
      SetSkill("hack combat",GetLevel()+random(8));
      break;

      case 1:
      WEAPON_IS = "pole";
      SetSkill("pole combat",GetLevel()+random(8));
      break;

      case 2:
      WEAPON_IS = "spear";
      SetSkill("pole combat",GetLevel()+random(8));
      break;    

      case 3:
      WEAPON_IS = "sword";
      SetSkill("slash combat",GetLevel()+random(8));
      break;
   }

   SetInventory( ([
                    MASTER_OBJ + "/" + WEAPON_IS : "wield " + WEAPON_IS,
                    "/std/armour/helm_open" : "wear helmet",
               ]) );
   SetCurrency("nuggets",random(10)+11);
   SetMorality(random(100)+20);
}