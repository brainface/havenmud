#include <lib.h>
#include "store.h"
inherit LIB_EQUIPPER;

static void create() {
   ::create();
   SetKeyName("Yannia");
   SetId( ({ "yannia" }) );
   SetShort("Yannia the Generous");   
   SetLong(
     "Yannia is a frequent visitor in the tannery. She has a "
     "curious fascination with the material, and spends much of her time "
     "discussing various maintainance techniques with the tanner. She seems to "
     "have a few spare items in her possesion that she would likely donate "
     "to someone who couldn't quite afford the tanner's prices."     
   );              
   SetRace("wild-elf");
   SetGender("female");
   SetMorality(900);
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
   SetAction(10, ({ 
    "!say I have a few spare pieces of armour, if you can't afford to pay for the best."
     }) );    
}
