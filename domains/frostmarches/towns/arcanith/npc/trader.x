#include <lib.h>
#include <vendor_types.h>
#include "../ruins.h"    
inherit LIB_NEWVENDOR;   

static void create() {
  ::create();         
  SetKeyName("presmyr");
  SetId( ({ "presmyr", "arcanith_wander", "trader" }) );
  SetShort("Presmyr the Trader");                       
  SetRace("goden");                                     
  SetBaseLanguage("Koblich");                           
  SetClass("rogue");                                    
  SetLevel(15);                                         
  SetMorality(-100);
  SetStorageRoom("/domains/frostmarches/towns/arcanith/room/storage/store_store");
  SetLocalCurrency("senones");
  SetLong("Presmyr is a goden merchant from Keryth that has settled into "
          "the ruins of Arcanith with the kobolds.  No one is quite sure "
          "as to why someone would do this."
  );
  SetLimit(1);
  SetWander(20);
  SetGender("male");
  SetTown("Keryth");
  SetFirstCommands(({ "lead mule", "lead lotai" }) );
  SetAction(10, ({
    "!say Sell it to me, Kobolds!",
    "!say I'll take whatever you find.",
    "!smirk",
    "The trader gets a sudden crazed look in his eye.",
    "!giggle crazily",
    "!grin stupidly",
    "!smirk fiendishly",
  }) );
  SetVendorType(VT_ALL);
  SetFriends( ({ "lotai", "arcanith_pack_mule" }) );
  SetCombatAction(5, ({
    "!guard lotai"
  }) );
}

