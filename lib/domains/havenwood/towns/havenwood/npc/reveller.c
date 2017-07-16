#include <lib.h>
#include <std.h>
#include <daemons.h>
#include "../wood.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("Romase");
  SetTown("Havenwood");
  SetShort("Romase the Reveller");
  SetRace("wild-elf");
  SetClass("nightreveller");
  SetReligion("Eclat");
  SetLevel(50);
  SetMorality(400);
  SetCurrency("imperials",random(100) + 1);
  SetLong("Romase is the leader of the Nightrevellers, the "
          "Wild-Elves that lead the nightly dance and the festivities "
          "of the Wood. The nightrevellers are both feared and lusted "
          "after by the mere mortals of the world.");
  SetGender("female");
  SetFreeEquip( ([
    STD_INSTRUMENTS "fife" : 1,
    ]) );
  SetInventory( ([
    STD_INSTRUMENTS "fife" : "wield fife",
    ]) );
  SetPlayerTitles( ([
   "newbie" : "the Night Reveller",
   "mortal" : "the Dreamchaser",
   "hm"     : "the Dancer of the Fae",
   "legend" : "the Harlequin",
   "avatar" : "Reveller $N the Enchanter of Dreams",
    ]) );
  SetSongBook( ([
    "aural shield" : 100,
    "aria of ice"  : 100,
  ]) );
  SetCombatAction(10, ({ 
     "!sing aria of ice", "!sing aria of ice", "!sing aria of ice", "!sing aural shield", "!sing aria of ice"  
   }) );
  SetFirstCommands( ({ "sing aural shield", "sing aural shield", "sing aural shield", "sing aural shield" }) );
}
