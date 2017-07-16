/* 'Skeleton'
 * Zeratul@Haven
 */

#include <lib.h>
#include <config.h>
#include "../undead.h"
inherit LIB_SENTIENT;

int CheckAttack(object);

int type = random(3);
static void create() {
  sentient::create();
  SetRace("human");

  if (type == 0) {
  SetClass("fighter");
  SetInventory( ([
     UNDEAD_OBJ + "falchion" : "wield sword",
  ]) );
  SetSkill("slash attack", 105, 1);
  SetSkill("slash defense", 105, 1);
  }

  if (type == 1) {
  SetClass("fighter");
  SetInventory( ([
     UNDEAD_OBJ + "axe" : "wield axe",
  ]) );
  SetSkill("hack attack", 105, 1);
  SetSkill("hack defense", 105, 1);
  }

  if (type == 2) {
  SetClass("fighter");
  SetInventory( ([
     UNDEAD_OBJ + "mace" : "wield mace",
  ]) );
  SetSkill("blunt attack", 105, 1);
  SetSkill("blunt defense", 105, 1);
  }

  if (type == 3) {
  SetClass("fighter");
  SetInventory( ([
  ]) );
  SetSkill("melee attack", 105, 1);
  SetSkill("melee defense", 105, 1);
  }

  SetKeyName("skeleton");
  SetShort("a skeleton creature");
  SetId( ({ "skeleton","skeletal creature","creature","guard_shrine" }) );
  SetAdjectives( ({ "skeletal" }) );
  SetLong(
     "This pile of bones is an undead skeletal creature. The remains of what's left "
     "on the bones rots away as the creature moves with surprising agility. "
     "A strange aura glows faintly around the creature, lighting it in a surreal "
     "fashion as it clunks along scraping its bones together. "
  );
  SetLimit(4);
  SetUndead(1);
  SetFriends( ({
     "guard_shrine"
  }) );
  SetUndeadType("skeleton");
  SetLevel(random(20)+15);
  SetCurrency("ducats", random(150)+200);
  SetAction(1, ({
     "!The skeleton's bones scrape together as it moves.",
     "!emote grins with unseen laughter.",
  }) );
  SetMorality(-200);
  SetEncounter( (:CheckAttack:) );
  }

int CheckAttack(object who) {
if (this_player()->GetLevel() < MAX_NEWBIE_LEVEL) return 0;
if (this_player()->GetClass("necromancer")) return 0;
if (this_player()->id("guard_shrine")) return 0;
     eventForce("attack " + who->GetKeyName());
     return 1;
}

