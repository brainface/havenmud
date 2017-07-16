//
// Summary: Fighter leader
// Created by: Rhakz@Haven -- Angel Cazares
// For: Baria
// Date: 10/04/99
//
#include <lib.h>
#include <std.h>
#include "../jungle.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("Krull");
  SetShort("Krull the Smasher of Skulls");
  SetId( ({ "krull", "barbarian","man",""}) );
  SetAdjectives( ({"leader","courageous","fierce","adept",
                   "powerful"}) );
  SetLong("This extremely huge and muscled human is the fighter "
          "leader of Baria. He constantly drools and gnashes his "
          "yellowish, rotten teeth. He looks fierce and could easily "
          "smash even the hardest bones of any creature with a single "
          "blow."
         );
  SetRace("human");
  SetClass("fighter");
  SetLevel(60);
  SetGender("male");
  SetMorality(-300);
  SetTown("Baria");
  RemoveLanguage("Enlan");
  SetLanguage("Barian", 100, 1);
  SetInventory( ([
              ]) );
  SetCurrency( ([
    "chits" : 30 + random(30)
  ]) );
  SetFreeEquip( ([
    STD_WEAPON + "blunt/femur" : 1
  ]) );
  SetInventory( ([
              ]) );
  SetPlayerTitles( ([
    "newbie"  : "the Weakling",
    "mortal"  : "the Barbarian",
    "hm"      : "the Massive Bruiser",
    "legend"  : "the Mangler and Thrasher",
    "avatar"  : "the Crusher of Dragon Bones",
     //"fighter" : "the Gladiator Who Fights Jungle Beasts",
    "ranger"  : "the Nomadic Protector of the Jungle's Nature"
  ]) );
  // I'm fucking around and you can't stopppp me!
  // -mahkefel
  AddUniqueSkills( ([
    "blunt combat" : 1,
    "slash combat" : 0,
    "metal working" : 0,
    "melee combat" : 2,
    "combat rage" : 2,
  ]) );
}

