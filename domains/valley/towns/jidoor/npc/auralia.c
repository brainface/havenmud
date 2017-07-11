//
// Auralia, the Storekeeper
// Created by Zaxan@Haven
//

#include <lib.h>
#include <vendor_types.h>
#include "../jidoor.h"

inherit LIB_VENDOR;

static void create() {
   vendor::create();
   SetKeyName("auralia");
   SetId( ({ "auralia", "storekeeper","jidoor_npc", }) );
   SetShort("Auralia the Storekeeper");
   SetLong("This pretty woman is the master of gems. She sits here "
           "making sure that all of her beautiful gems stay clean "
           "and pretty.");
   
   SetRace("sprite");
   SetClass("evoker");
   SetSkill("bargaining",100,1);
   SetLevel(30);
   
  
   SetGender("female");
   SetMorality(50);
  
   SetAction(5, ({ "!speak May I help you with something?" }) );
   SetLocalCurrency("rupies");
   SetStorageRoom(JID_ROOM "/misc_buildings/gemstorage");
   SetSpellBook( ([ 
      "fireball"  : 100,
      "sphere"    : 100,
      "paralysis" : 100,
   ]) );
   SetCombatAction(75, ({ 
      "!cast fireball",
      "!cast sphere",
      "!cast paralysis",
   }) );
   SetMaxItems(50);
   SetMaxSingleItem(10);
   SetVendorType(VT_GEM);
}
