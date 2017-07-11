/*  A wandering rogueish type with pole defense */
#include <lib.h>
#include "../tulu.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("tulu cultist fighter");
  SetShort("a crazed cultist fighter");
  SetId( ({ "cultist", "fighter" }) );
  SetAdjectives( ({ "crazed", "cultist" }) );
  SetRace("nosferatu");
  SetClass("fighter");
  SetMorality(-500);
  SetSkill("pole combat", 1, 1);
  SetSkill("cloth armour", 1, 1);
  SetLevel(200);
  SetGender("male");
  SetLong(
    "This black-robed cultist has a maddened look in his eyes as if he cannot be bothered. "
    "Those interfering with his work may find themselves unhappy with the result."
    );
  SetCurrency("bloodgems", 5000);
  SetInventory( ([
      TULU_OBJ + "cultist_staff" : "wield staff",
    TULU_OBJ + "cultist_robe" : "wear robe on left arm and left leg and torso and right arm and right leg",
     ]) );
  SetAction(3, ({
    "!yell Ieya Ieya Tulu awaits!",
    "!yell He Dreams!",
    "!yell In ruined Relyah, dead Tulu dreams!",
    }) );
}
