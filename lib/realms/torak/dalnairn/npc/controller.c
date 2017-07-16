//
// Dalnairn Total Recode
// Torak@Haven 2014-2017
//

#include <lib.h>
#include <domains.h>
#include "../dalnairn.h"

inherit LIB_CONTROLLER;

static void create() {
  ::create();
  SetKeyName("throdrior");
  SetId( ({ 
    "chef", "throdrior" 
  }) );
  SetAdjectives( ({ "head" }) );
  SetShort("Throdrior the Head Chef");
  SetLong(
    "Throdrior is a stout dark-dwarf. " 
    "Those in need of a quest should <ask throdrior for quests>."
    );
  SetClass("merchant");
  SetLevel(50);
  SetRace("dark-dwarf");
  SetGender("male");
  SetBaseLanguage("Runic");
  SetTown("Dalnairn");
  SetInventory( ([
    DAL_ARM + "pants": "wear pants",
    DAL_ARM + "shirt" : "wear shirt",
    DAL_ARM + "shoes" : "wear shoes",
    DAL_WPN "kitchen_knife" : "wield knife",
  ]) );
}

void eventGreet(object who) {
  ::eventGreet(who);
  SetAction(15, ({
    "!speak You could ask me for a quest.",
    "!speak You could request quests from me.",
  }) );
}
