#include <lib.h>
inherit LIB_NPC;
#include "../hiker.h"

static void create() {
   npc::create();
   SetProperty("hikernoleave",1);
   switch(random(2)) {
      case 0:
      SetGender("female");
      break;
      case 1:
      SetGender("male");
      break;
   }
   SetKeyName("sleepy camper");
   SetShort("a sleepy camper");
   SetId( ({ "camper" }) );
   SetAdjectives( ({ "sleepy" }) );
   SetMorality(-25);
   SetLong("The camper's eyes are half-closed, and dark circles hang "
           "under them.  " + capitalize(nominative(this_object())) +
           " searches for something to wake " + objective(this_object()) +
           " up, and doesn't seem too successful.  " +
           capitalize(possessive(this_object())) + " back bends over as "
           + nominative(this_object()) + " stumbles, but even so, "
           + nominative(this_object()) + " seems tall.");
   SetInventory( ([
                    H_OBJ + "knife" : "wield knife in left hand",
                    H_OBJ + "pjs"   : "wear pjs",
               ]) );
   switch(random(3)) {
      case 0:
      SetRace("human");
	   SetInventory( ([
      	              H_OBJ + "knife" : "wield knife in left hand",
            	        H_OBJ + "mediumpjs"   : "wear pjs",
              	 ]) );
      switch(random(3)) {
         case 0:
         SetCurrency("senones",80);
         break;
         case 1:
         SetCurrency("nuggets",15);
         break;
         case 2:
         SetCurrency("chits",45);
         break;
      }
      break;
      case 1:
      SetRace("elf");
	   SetInventory( ([
      	              H_OBJ + "knife" : "wield knife in left hand",
            	        H_OBJ + "mediumpjs"   : "wear pjs",
            	   ]) );

      SetCurrency("imperials",40);
      break;
      case 2:
      SetRace("muezzin");
      SetCurrency("cuicui",300);
      break;
   }
   SetClass("valkyr");
   SetSkill("knife attack",1,1);
   SetSkill("knife defense",1,1);
   SetLevel(15+random(2));
   SetStat("speed",15,5);
}
