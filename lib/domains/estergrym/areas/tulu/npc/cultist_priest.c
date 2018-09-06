// omergawd duuk update your comments
// made by duuk at some point it is not a wandering rogue it is a tulu priest
/*  A wandering rogueish type with pole defense */
#include <lib.h>
#include "../tulu.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("tulu cultist priest");
  SetShort("a crazed cultist priest");
  SetId( ({ "cultist", "priest" }) );
  SetAdjectives( ({ "crazed", "cultist" }) );
  SetRace("nosferatu");
  SetClass("priest");
  SetSkill("pole combat", 1, 1);
  SetSkill("cloth armour", 1, 1);
  SetGender("male");
  SetMorality(-1500);
  SetLong(
    "This black-robed cultist has a maddened look in his eyes as if he cannot be bothered. "
    "Those interfering with his work may find themselves unhappy with the result."
    );

  SetInventory( ([
      TULU_OBJ + "cultist_staff" : "wield staff",
      TULU_OBJ + "cultist_robe"  : "wear robe",
     ]) );
  SetAction(3, ({
    "!yell Ieya Ieya Tulu awaits!",
    "!yell He Dreams!",
    "!yell In ruined Relyah, dead Tulu dreams!",
    "!cast protection of tulu",
    }) );
  SetReligion("Tulu Cult");
  SetLevel(230);
  SetCurrency("bloodgems", 5000);
  SetSpellBook( ([
    "protection of tulu" : 100,
    "holy fury"          : 100,
    "divine wrath"       : 100,
    ]) );
  SetFirstCommands( ({
    "cast protection of tulu",
    "cast protection of tulu",
    "cast protection of tulu",
    "cast protection of tulu",
    "cast protection of tulu",
  }) );
  SetCombatAction(20, ({
    "!cast holy fury",
    "!cast divine wrath",
    "!cast protection of tulu",
  }) );
}

