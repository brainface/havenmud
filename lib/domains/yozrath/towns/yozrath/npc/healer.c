
#include <lib.h>
#include "../yozrath.h"
inherit LIB_HEALER;

static void create() {
  ::create();
  SetRace("human");
  SetBaseLanguage("Padashi");
  SetTown("Yozrath");
  SetLocalCurrency("dinar");
  SetKeyName("muhammed");
  SetLimit(1);
  SetShort("Muhammed the Desert Healer");
  SetId( ({ "muhammed", "healer" }) );
  SetAdjectives( ({ "healer", "desert" }) );
  SetGender("male");
  SetAction(6, ({
    "!speak If you have needs, I could solve them.",
    "!speak If you are wounded, allow me to heal you.",
    "!speak If you have died, I can restore your form.",
    "!speak Under the Light of He Who Judges, the Desert provides.",
    "!cast barrier of faith",
    "!cast barrier of faith",
  }) );
  SetReligion("Kylin");
  SetFees( ([
    "resurrect" : 75,
    "magic"     : 8,
    "stamina"   : 2,
    "health"    : 3,
    "restore"   : 10,
    ]) );
  SetLong("Muhammed is the local healer.  He can <restore> a lost limb "
          "or even <resurrect> someone who has met an untimely end. He "
          "can also <heal> <magic, health, or stamina>."
          );
  SetMorality(1500);
  SetInventory( ([
    YOZRATH_OBJ "thobe" : "wear thobe",
    YOZRATH_OBJ "bisht" : "wear bisht",
    ]) );
  SetClass("imam");
  SetLevel(40); 
  SetCurrency("dinar", 500);
  SetSpellBook( ([
    "sanctify"  : 100,
    "shield of faith" : 100,
    "harm body"  : 100,
    "desert banishment" : 100,

    ]) );
  SetCombatAction(40, ({
     "!yell HELP! I'm being attacked!",
     "!cast desert banishment",
     "!cast desert banishment",
     "!cast shield of faith",
     "!cast shield of faith",
     "!cast harm body",
     "!cast sanctify",
     }) );
}
