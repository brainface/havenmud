
#include <lib.h>
#include "../karak.h"
inherit LIB_EQUIPPER;

static void create() {
   ::create();
   SetKeyName("Gnarl");
   SetId( ({ "gnarl" }) );
   SetShort("Gnarl the Giver");   
   SetLong(
     "Gnarl is a frequent visitor to the Karak Armoury. She has an "
     "unhealthy fascination with the material, and spends much of her "
     "time discussing orky techniques with passers-by. She seems to "
     "have a few spare items in her possession that she would likely donate "
     "to someone who couldn't quite afford shop prices."     
   );              
   SetRace("orc");
   SetGender("female");
   SetClass("fighter");
   SetLevel(10);
   SetReligion("Saahagoth", "Saahagoth");      
   SetMorality(-200);
   SetFreeEquipment( ([
     "vest" :   KARAK_OBJ + "oldvest",
     "pants" :  KARAK_OBJ + "oldpants",
     "boots" :  KARAK_OBJ + "oldboots",
     "glove" :  KARAK_OBJ + "oldglove",
     "helmet" : KARAK_OBJ + "oldhelmet",     
     ]) );
   SetLevelLimit(10);   
   SetAction(1, ({ "!say I have a few spare pieces of armour, if you can't "
     "afford what this fool charges." }) );    
}
