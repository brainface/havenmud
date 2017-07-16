// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include "../karak.h"
inherit LIB_TOWNGUARD;

static void create() {
  ::create();
  SetKeyName("horde member");
  SetId( ({ "orc", "horde", "member", "karak_wander" }) );
  SetAdjectives( ({ "orc", "ravening", "horde", "member" }) );
  SetShort("a member of the Ravening Horde");
  SetLong(
    "This medium sized orc's body ripples with muscles and anger. "
    "A cold intelligence flares in his eyes, and two enormous, sharp fangs "
    "protrude from his lower jaw. A large, turned-up nose with flared nostrils "
    "sits on his face. It is the pure number of these soldiers, and their "
    "truly viscious dispositions, which account for the incredible power "
    "of the orcish Hordes."
  );
  SetRace("orc");
  SetTown("Karak");
  SetGender("male");
  SetClass("fighter");
  SetLevel(random(50) + 10);
  SetInventory( ([
    KARAK_OBJ + "helm." : "wear helm",
    KARAK_OBJ + "mace"  : "wield mace in left hand",
    KARAK_OBJ + "axe"   : "wield axe in right hand",
  ]) );
  SetAction(5, ({
    "!say I hear we may be planning further invasions....",
  }) );
  SetReligion("Saahagoth", "Saahagoth");
  SetMorality(-150);
}
