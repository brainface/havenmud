#include <lib.h>
#include <std.h>
#include "../parva.h"
#include <vendor_types.h>
inherit LIB_VENDOR;

static void create() {
   vendor::create();
   SetKeyName("Pons");
   SetShort("Pons the Shopkeep");
   SetId( ({ "pons", "shopkeep" }) );
   SetLong("Pons is a short, fat halfling who has a constant "
           "cold. His nose is always running and "
           "red, as a result of his constant attempts to "
           "keep it clean. His eyes are quick and bright, "
           "however, and his fingers nimble and swift.");
   SetGender("male");
   SetRace("halfling");
   SetBaseLanguage("Enlan");
   SetClass("rogue");
   SetSkill("bargaining",1,1);
   SetLevel(20);
   SetVendorType(VT_ALL);
   SetLocalCurrency("oros");
   SetStorageRoom(PARVA_ROOM "str_shop");
   SetMaxSingleItem(15);
   SetMorality(-10);
   SetInventory( ([
     STD_GERMS "cold" : 1,
     ]) );
   SetAction(5, ({ 
    "!speak I'll buy your loot!",
    "!speak Come here and browse my wares!",
    "!emote pants with exertion.",
    "!speak Buy some fishing poles!  Get more than one!  You can never "
           "have too many!  You never know when one will break!",
    }) );
   SetCombatAction(10, ({ 
    "!yell Help!  Help me!",
    "!yell Help me! I'm being attacked!",
    "!yell Help!",
    "!cry", "!whimper",
    "!speak I never should have left the Shire for this awful pit of land on the coast!",
    "!grovel",
     }) );
   SetFriends( ({ "Snop" }) );
}

void heart_beat() {
  ::heart_beat();
  if (!present("cold", this_object())) {
    new(STD_GERMS "cold")->eventInfect(this_object());
  }
}