//
// Auralia, the Storekeeper
// Created by Zaxan@Haven
// Stolen by Davantalus@Haven
//

#include <lib.h>
#include <vendor_types.h>
#include "../mal.h"

inherit LIB_VENDOR;

static void create() {
   vendor::create();
   SetKeyName("aurian");
   SetId( ({ "aurian", "storekeeper" }) );
   SetShort("Aurian the Storekeeper");
   
   SetLong("This pretty woman is the master of gems. She sits here "
           "making sure that all of her beautiful gems stay clean "
           "and pretty.");
   
   SetInventory( ([ 
   		MAL_OBJ + "/clothing/elf_skirt"  : "wear skirt",
      MAL_OBJ + "/clothing/elf_blouse" : "wear blouse"
      ]));
   SetRace("dark-elf"); 
   SetGender("female");
   SetTown("Malveillant");
   SetMorality(-200);;
   SetClass("evoker");
   SetSkill( "bargaining", 100 );
   SetLevel(30);
   SetMorality(-550);
   
   SetAction(5, ({ 
   		"!speak May I help you with something?"
   		}) );
   SetLocalCurrency("roni");
   SetStorageRoom(MAL_ROOMS "gemstorage");
   SetMaxSingleItem(15);

   SetSpellBook( ([ 
      "shock"      : 100,
      "lava storm" : 100,
      "sphere"     : 100,
      "fireball"   : 100,
   		]) );
   SetCombatAction(5, ({ 
      "!cast shock",
      "!cast lava storm",
      "!cast sphere",
      "!cast fireball",
   		}) );
   SetMaxItems(50);
   SetVendorType(VT_GEM);
}
