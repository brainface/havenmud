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
   SetId( ({ "auralia", "storekeeper" }) );
   SetShort("Auralia the Storekeeper");
   SetLong("This pretty woman is the master of gems. She sits here "
           "making sure that all of her beautiful gems stay clean "
           "and pretty.");
   SetLevel(30);
   SetRace("sprite");
   SetClass("evoker");
   SetGender("female");
   SetMorality(50);
   SetSkill( "bargaining", 100 );
   SetAction(5, ({ "!speak May I help you with something?" }) );
   SetLocalCurrency("rupies");
   SetStorageRoom(JID_ROOM "/misc_buildings/gemstorage");
   SetSpellBook( ([ 
      "bolt" : 100,
      "missile" : 100,
      "terra" : 100,
   ]) );
   SetCombatAction(5, ({ 
      "!cast missile",
      "!cast bolt",
      "!cast terra",
   }) );
   SetMaxItems(50);
   SetMaxSingleItem(10);
   SetVendorType(VT_GEM);
}
