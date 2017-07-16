#include <lib.h>
#include "store.h"
inherit LIB_EQUIPPER;

static void create() {
   ::create();
   SetKeyName("Odele");
   SetId( ({ "odele" }) );
   SetShort("Odele the Generous");   
   SetLong(
     "Odele is a frequent visitor in Tornys' leather store. She has a "
     "curious fascination with the material, and spends much of her time "
     "discussing various maintainance techniques with Tornys. She seems to "
     "have a few spare items in her possesion that she would likely donate "
     "to someone who couldn't quite afford Tornys' prices."     
   );              
   SetRace("human");
   SetGender("female");
   SetBaseLanguage("Eltherian");      
   SetMorality(900);
   SetClass("warrior");
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
