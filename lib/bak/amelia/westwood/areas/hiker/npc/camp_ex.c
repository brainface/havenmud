#include <lib.h>
inherit LIB_NPC;
#include "../hiker.h"

static void create() {
   npc::create();
   SetProperty("hikernoleave",1);
   switch(random(2)) {
      case 0:
      SetGender("male");
      break;
      case 1:
      SetGender("female");
      break;
   }
   SetKeyName("excited camper");
   SetShort("an excited camper");
   SetId( ({ "camper" }) );
   SetAdjectives( ({ "excited","hyper" }) );
   SetMorality(10);

   SetInventory( ([
                    H_OBJ + "backpack" : "wear backpack",
                    H_OBJ + "kit" : "put kit in backpack",
                    H_OBJ + "coffee" : 1,
               ]) );
   SetLong("The camper is all but bouncing around with excitement as "
           + nominative(this_object()) + " considers the wonderful "
           "prospect of sleeping under the stars, or in the protection "
           "of something as flimsy as a tent.  Something sparkles in " 
           + possessive(this_object()) + " eyes, topping the jangly "
           "energy in " + possessive(this_object()) + " strong limbs "
           "and hyper body.");
   switch(random(4)) {
      case 0:
      SetRace("elf");
    SetInventory( ([ H_OBJ + "mediumbackpack" : "wear backpack",
                  H_OBJ + "kit" : "put kit in backpack",
                 H_OBJ + "coffee" : 1,
         ]) );
      SetCurrency("imperials",30);
      break;
      case 1:
      SetRace("muezzin");
      SetCurrency("cuicui",210);
      break;
      case 2:
      SetRace("gelfling");
      SetCurrency("imperials",27);
      break;
      case 3:
      SetRace("human");

      SetInventory( ([ H_OBJ + "mediumbackpack" : "wear backpack",
                  H_OBJ + "kit" : "put kit in backpack",
                 H_OBJ + "coffee" : 1,
         ]) );
      switch(random(2)) {
         case 0:
         SetCurrency("senones",30);
         break;
         case 1:
         SetCurrency("dinar",25);
      }
      break;
   }
   SetClass("valkyr");
   SetSkill("melee attack",1,1);
   SetSkill("melee defense",1,1);
   SetLevel(31+random(4));
   SetAction(1, ({ "!emote dances around wildly.","!emote laughs and "
                   "starts cheering.","!emote bounces around the "
                   "camp.","!emote jumps high into the air, grabbing "
                   "hold of a distant branch and hanging for a few "
                   "moments.","!emote grins at the world." }) );
   AddCaffeine(30);
}
