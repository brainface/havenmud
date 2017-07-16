//  Auralia, the Storekeeper
//  Created by Zaxan@Haven
//  Stolen by Davantalus@Haven
//  Re-Stolen by Alessandra 2009

#include <lib.h>
#include <vendor_types.h>
#include "../mal.h"
inherit LIB_VENDOR;

static void create() {
  vendor::create();
  
  SetKeyName("aurian");
  SetShort("aurian the Storekeeper");
  SetId( ({ "aurian", "storekeeper", "dark-elf", "woman" }) );
  SetAdjectives( ({"pretty"}) );
  SetLong(
     "This pretty woman is the master of gems. She sits here "
     "making sure that all of her beautiful gems stay clean "
     "and pretty. Long ebony hair is piled on top of her head and "
     "her slender fingers delicately work at keeping the gems clean."
     );
  SetRace("dark-elf");
  SetGender("female");
  SetClass("evoker");
  SetSkill( "bargaining", 100 );
  SetLevel(30);
  SetMorality(-50);
  SetLocalCurrency("roni");
  SetMaxItems(50);
  SetMaxSingleItem(10);
  SetVendorType(VT_GEM);
  SetStorageRoom(MAL_ROOMS3 + "gem_stor");
  SetInventory(([ 
     MAL_OBJ + "/clothing/elf_skirt" : "wear skirt",
     MAL_OBJ + "/clothing/elf_blouse" : "wear blouse", 
     ]));
  SetAction(5, ({ 
  	 "!speak May I help you with something?" 
  	 }) );
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

}
