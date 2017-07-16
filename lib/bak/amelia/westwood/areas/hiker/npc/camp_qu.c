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
   SetKeyName("quiet camper");
   SetShort("a quiet camper");
   SetId( ({ "camper" }) );
   SetAdjectives( ({ "quiet" }) );
   SetMorality(-5+random(11));
   SetLong("The camper broods silently, wondering about the world around "
           + possessive(this_object()) + ", and pondering the camping days "
           "both ahead and behind.  " +
           capitalize(nominative(this_object())) + " has been out a "
           "long time, based on the general disheveled appearance "
           + nominative(this_object()) + " has developed.  However, "
           "something about " + possessive(this_object()) + " shows a "
           "resilience and durability not found in most people.");
   switch(random(5)) {
      case 0:
      SetRace("muezzin");
      SetCurrency("cuicui",350);
      break;
      case 1:
      SetRace("elf");
      SetCurrency("imperials",50);
      break;
      case 2:
      SetRace("gelfling");
      SetCurrency("imperials",50);
      break;
      case 3:
      SetRace("dwarf");
      SetCurrency("nuggets",30);
      break;
      case 4:
      SetRace("human");
      SetCurrency("senones",40);
      break;
   }
   SetClass("valkyr");
   SetLevel(29+random(3));
   SetInventory( ([
                    H_OBJ + "tentset" : 1,
               ]) );
}
