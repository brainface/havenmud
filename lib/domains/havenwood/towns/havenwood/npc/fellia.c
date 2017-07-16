#include <lib.h>
#include <std.h>
#include <daemons.h>
#include "../wood.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("fellia");
  SetTown("Havenwood");
  SetShort("Fellia LightWalker");
  SetRace("wild-elf");
  SetClass("ranger");
  SetLevel(48);
  SetMorality(400);
  SetCurrency("imperials",random(100) + 1);
  SetLong("Fellia is a small wild-elf with wild eyes and a certain "
          "flare for the outdoors.  Her manners and actions leave "
          "much to be desired in polite company, but she is well "
          "known and loved in her native town.");
  SetGender("female");
  SetFreeEquip( ([
    STD_PROJECTILE "bow_long_newbie" : 1,
    ]) );
  SetInventory( ([
    STD_PROJECTILE "bola" : "wield bola",
    ]) );
  SetPlayerTitles( ([
   "newbie" : "the Gentle Walker of the Havenwood",
   "mortal" : "the LightFoot of the Havenwood",
   "hm"     : "the Padfoot of the Havenwood",
   "legend" : "the Protector of the Havenwood",
   "avatar" : "the Shadow of the Havenwood",
    ]) );
  SetSpellBook( ([
    "tangle" : 100,
    "plant strike" : 100,
    "vine wall" : 100,
  ]) );
  SetCombatAction(10, ({ 
     "!cast tangle", "!cast plant strike", "!cast tangle", "!cast vine wall", "!cast plant strike"  
   }) );
  SetFirstCommands( ({ "cast vine wall", "cast vine wall", "cast vine wall", "cast vine wall" }) );
}
