/*  Goblin Shaman Leader */

#include <lib.h>
#include "../goblins.h"

inherit LIB_LEADER;
inherit LIB_FEAR;

static void create() {
  ::create();
  SetKeyName("burkeg");
  SetTown("Kresh");
  SetRace("goblin");
  SetShort("Burkeg the Evil");
  SetId( ({ "burkeg", "shaman", "goblin" }) );
  SetAdjectives( ({ "evil" }) );
  SetLong(
    "Burkeg the Evil is a shaman of Kuthar. "
    "His evil surrounds him like a cloak, and "
    "the fear that he inspires is legendary."
  );
  SetMorality(-1000);
  SetClass("shaman");
  SetGender("male");
  SetLevel(60);
  SetReligion("Kuthar");
  SetFriends( ({ "goblin" }) );
  SetInventory( ([
      ]) );
  SetSpellBook( ([
    "veil from beyond" : 100,
    "wither"           : 100,
    "chain lightning"  : 100,
    "drain soul"       : 100,
    "disintegrate"     : 100,
    ]) );
  SetFearType("evil aura");
  SetResistLevel(10);
  SetFearLength(5);
  SetCombatAction(85, ({ 
    "!cast veil from beyond",
    "!cast wither",
    "!cast chain lightning",
    "!cast drain soul",
    "!cast disintegrate",
  }) );
  SetPlayerTitles( ([
    "newbie" : "the Seeker of Spirits",
    "mortal" : "the Shaman of the Horde",
    "hm"     : "the Ancestral Spirit Walker",
    "legend" : "the Blood of the Spirits",
    "avatar" : "the Rider of the Winds",
    ]) );
}

void init() {
  leader::init();
  fear::init();
}

varargs int CheckResistFear(object who, int level, string t) {
  if (who->GetRace() == "goblin") return 0;
  return ::CheckResistFear(who, level, t);
}

