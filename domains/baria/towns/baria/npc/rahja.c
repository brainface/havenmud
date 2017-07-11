//
//  Rahja the potion seller
//  Created by: Rhakz@Haven -- Angel Cazares
//  For: Baria
//  Date: 06/04/99
//
#include <lib.h>
#include "../jungle.h"
#include <vendor_types.h>
inherit LIB_VENDOR;
  
static void create() {
  vendor::create();
  SetKeyName("Rahja");
  SetShort("Rahja the Alchemist and Potion Seller");
  SetId( ({"rahja", "draconian", "alchemist","seller","potion seller"}) );
  SetGender("female");
  SetAdjectives( ({ "skinny"}) );
  SetMorality(-300);
  SetLong("This skinny draconian has spent most of her life creating potions "
          "and elixirs for many purposes. Her blue scales have a dark rusty "
          "tint due to the materials she is constantly in contact with. " 
          "She dwells in Baria, selling her potions and elixirs to make a living."
         );
  SetRace("draconian");
  SetClass("merchant");
  SetSkill("melee combat",1,3);
  SetLevel(45);
  SetTown("Baria");
  SetLocalCurrency("chits");
  SetFriends( ({"Naj"}) );
  SetStorageRoom(BARIA_ROOM + "potion_str");
  SetMaxSingleItem(15);
  SetLanguage("Dragonish", 100, 0);
  SetLanguage("Barian", 100, 1);
}
