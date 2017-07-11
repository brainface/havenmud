#include <lib.h>
inherit LIB_NPC;
#include "../castle.h"

static void create() {
   npc::create();
   SetKeyName("calm diner");
   SetShort("a calm diner");
   SetId( ({ "diner" }) );
   SetAdjectives( ({ "calm" }) );
   SetLong("A calm, interestly-bored look covers the diner's face, "
           "much like those normally seen during long, boring, "
           "official dinners.");
   switch(random(2)){
      case 0:
      SetGender("male");
      break;
      case 1:
      SetGender("female");
      break;
   }
   SetRace("dwarf");
   SetClass("rogue");
   SetLevel(10+random(2));
   SetInventory( ([
                    VC_OBJ + "/yam" : 1,
               ]) );
   SetCurrency("nuggets",random(20)+50);
   SetMorality(100);
}