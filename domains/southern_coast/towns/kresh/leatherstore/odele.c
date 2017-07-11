#include <lib.h>
#include "store.h"
inherit LIB_EQUIPPER;

static void create() {
   ::create();
   SetKeyName("Ogdai");
   SetId( ({ "ogdai", "tanner"  }) );
   SetShort("Ogdai the Tanner");   
   SetLong(
     "Ogdai is a core part of the leather trade in Kresh. He has a "
     "great skill with the material, and spends much of his time "
     "discussing various maintainance techniques Temu. He seems to "
     "have a few spare items in his possesion that he would likely donate "
     "to someone who couldn't quite afford Temu's prices."     
   );              
   SetRace("goblin");
   SetGender("male");
   SetMorality(-100);
   SetClass("fighter");
   SetLevel(10);      
   SetFreeEquipment( ([
     "vest" : STORE_DIR + "oldvest",
     "pants" : STORE_DIR + "oldpants",
     "boots" : STORE_DIR + "oldboots",
     "glove" : STORE_DIR + "oldglove",
     "helmet" : STORE_DIR + "oldhelmet",     
   ]) );
   SetLevelLimit(10);   
   SetAction(1, ({ "!say I have a few spare pieces of armour, if you can't "
     "afford what this fool charges." }) );    
}
