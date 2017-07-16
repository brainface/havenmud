#include <lib.h>
#include "../trog.h"
#include <damage_types.h>
inherit LIB_NPC;

int NastyBite();

static void create() {
  ::create();
  SetKeyName("troglodyte child");
  SetRace("troglodyte");
  SetShort("a small brownish-green creature");
  SetId( ({ "troglodyte", "child", "creature" }) );
  SetAdjectives( ({ "small", "troglodyte", "brownish", "green", "brown" }) );
  SetLong(
    "This small creature is a troglodyte. It makes its home in the tunnels "
    "under Mount Trog. The creature is a fierce, nasty thing with large "
    "teeth and an oozing drool. This small creature is a troglodyte child."
    );
  SetClass("fighter");
  SetLevel(2);
  SetMeleeAttackString("teeth");
  SetMeleeDamageType(PIERCE);
  SetAction(5, ({
    "!emote looks around the cave.",
    "!emote shuffles around quietly.",
    "!emote quickly snaps its jaws shut on a small gnat.",
    "!speak Hello Hello Nasty Daylanders",
  }) );
  SetCombatAction(3, (: NastyBite :) );
  SetMorality(-100);
}

int NastyBite() {
  object who = GetCurrentEnemy();
  object flu = new(TROG_OBJ "trog_flu");
  string limb = who->GetRandomLimb(who->GetTorso());
  
  send_messages( ({ "snap" }),
    "$agent_name quickly $agent_verb its %^BOLD%^GREEN%^foul jaws%^RESET%^ down "
    "on $target_possessive_noun " + limb + "!",
    this_object(), who, environment());
  who->eventReceiveDamage(this_object(), PIERCE, random(50) + 10, 0, limb);
  if (flu) flu->eventInfect(who);
  return 1;
}