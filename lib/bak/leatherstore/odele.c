#include <lib.h>
#include "store.h"
inherit LIB_EQUIPPER;

static void create() {
   ::create();
   SetKeyName("Gnarl");
   SetId( ({ "gnarl" }) );
   SetShort("Gnarl the Giver");   
   SetLong(
     "Gnarl is a frequent visitor in the Leather Boyz place. She has an "
     "unhealthy fascination with the material, and spends much of her time "
     "discussing orky techniques with Gurk. She seems to "
     "have a few spare items in her possesion that she would likely donate "
     "to someone who couldn't quite afford Gurk's prices."     
   );              
   SetRace("orc");
   SetGender("female");
   SetMorality(-200);
   SetClass("warrior");
   SetLevel(10);      
   SetFreeEquipment( ([
     "vest" :   STORE_DIR + "oldvest",
     "pants" :  STORE_DIR + "oldpants",
     "boots" :  STORE_DIR + "oldboots",
     "glove" :  STORE_DIR + "oldglove",
     "helmet" : STORE_DIR + "oldhelmet",     
   ]) );
   SetLevelLimit(10);   
   SetAction(1, ({ "!say I have a few spare pieces of armour, if you can't "
     "afford what this fool charges." }) );    
}
