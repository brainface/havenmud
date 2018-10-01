//
// Summary: Fighter leader
// Created by: Rhakz@Haven -- Angel Cazares
// For: Baria
// Date: 10/04/99
//
#include <lib.h>
#include <std.h>
#include "../sarde.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("Ashtang");
  SetShort("Ashtang the Amazon of the Barian Jungle");
  SetId( ({ "ashtang", "fighter", "amazon","draconian",
            "amazon of the jungle","ashtang the amazon of the jungle"}) );
  SetAdjectives( ({"leader","courageous","fierce","adept",
                   "powerful"}) );
  SetLong("This female draconian is the fighter leader of Sarde. She "
          "is well-known for her ferocity and courage during battle. "
          "Her blue scales look polished and shiny. She has a huge scar "
          "in her back, obviously not even her hard scales could stop "
          "that blow. She is very powerful and adept at combat."
         );
  SetRace("draconian");
  SetClass("fighter");
  SetLevel(60);
  SetGender("female");
  SetMorality(-700);
  SetTown("Sarde");
  SetInventory( ([
                  SARDE_OBJ + "bone_sword" : "wield sword"
              ]) );
  SetCurrency( ([
                 "chits" : random(1000)
             ]) );
  SetFreeEquip( ([
                  STD_WEAPON + "slash/shortsword" : 1,
                  STD_ARMOUR + "shield/shield" : 1
              ]) );
  SetPlayerTitles( ([
                     "newbie" : "the Trainee Warrior of Sarde",
                     "mortal" : "the Warrior of the Jungle",
                     "hm" : "the Destroyer Warrior of Sarde",
                     "legend" : "the Leopard Fighter of the Barian Jungle",
                     "avatar" : "the Master Slasher of the Dark Jungle",
                     "barbarian" : "the Smashing Barian Warrior"
                  ]) );
}
