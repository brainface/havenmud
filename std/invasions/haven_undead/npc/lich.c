// Undead invasion of Haven
// Duuk
// Edited: Laoise, 2005

#include <lib.h>
inherit LIB_INVADER;
inherit LIB_FEAR;

static void create() {
  invader::create();
  SetKeyName("lich");
  SetShort("a tall undead fiend with a devilish look");
  SetId( ({ "lich", "fiend", "undead_inv" }) );
  SetAdjectives( ({ "tall", "undead", "devilish" }) );
  SetLong(
    "This fiend of the afterlife is a lithe brute which belies his "
    "raw power."
  );
  SetRace("human");
  SetGender("male");
  SetClass("evoker");
  SetLevel(74);
  SetEnemyTown("Haven");  
  SetUndead(1); SetNoCorpse(1);
  SetMorality(-500);
  SetProperty("no paralyze",1);
  SetProperty("no chain lightning",1);
  SetFearType("chill darkness");
  SetResistLevel(24);
  SetFearLength(15);
  SetCurrency("imperials", 5000);
  SetCombatAction(3, ({
    "!cast bolt",
    "!cast chain lightning",
    "!cast disintegrate",
    "!cast aura",
    "!cast buffer",
    "!cast fireball",
    "!cast missile",
  }) );
  SetSpellBook( ([
    "fireball" : 100,
    "missile" : 100,
    "buffer" : 100,
    "aura" : 100,
    "bolt" : 100,
    "chain lightning" : 100,
    "disintegrate" : 100,
  ]) );
  SetFriends( ({ "undead_inv" }) );
  SetWanderSpeed(5);
  SetWanderPath( ({
    "go east", "go east", "go south", "go south", "go south",
    "go east", "go east", "enter shop", "attack taylor",
  }) );
}

int CheckResistFear(object who, int level, string type) {
  if (who->GetUndead()) return 0;
  else return ::CheckResistFear(who, level, type);
}

void init() {
  invader::init();
  fear::init();
}
