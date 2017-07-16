#include <lib.h>
#include "store.h"
inherit LIB_EQUIPPER;

static void create() {
   ::create();
   SetKeyName("Fimana");
   SetId( ({ "fimana", "tanner"  }) );
   SetShort("Fimana Leatherweaver");   
   SetLong(
     "Fimana, wife to Norin the leather tanner of Glimmerdin, is tall for "
     "a dwarf. She has long brown hair which is braid several times and has a "
     "a short brown beard.  Fimana is very genorous and caring dwarf which "
     "is something Norin is always complaining about. She have a few items "
     "in her possesion that she would likely give to someone who needed a "
     "helping hand."     
     );              
   SetRace("dwarf");
   SetGender("female");
   SetMorality(100);
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
   SetAction(1, ({ 
   	  "!say I have a few spare pieces of armour, if you can't "
      "afford my husband's prices.",
      "!say you need to relax more Norin."
      }) );    
}
