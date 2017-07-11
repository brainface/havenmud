#include <lib.h>
#include <size.h>
#include <position.h>
#include "../trog.h"
#include <damage_types.h>
inherit LIB_NPC;

int NastyBite();

static void create() {
  ::create();
  SetKeyName("troglodyte queen");
  SetRace("troglodyte");
  SetShort("a large brownish-green creature");
  SetId( ({ "troglodyte", "queen", "creature" }) );
  SetAdjectives( ({ "large", "troglodyte", "brownish", "green", "brown" }) );
  SetLong(
    "This large creature is a troglodyte queen. It makes its home in the tunnels "
    "under Mount Trog. The creature is a fierce, nasty thing with large "
    "teeth and an oozing drool.  Her status makes her a fierce force to be "
    "reckoned with."
    );
  SetClass("fighter");
  SetLevel(6);
  SetMeleeAttackString("teeth");
  SetMeleeDamageType(PIERCE);
  SetAction(5, ({
    "!emote looks around the cave haughtily.",
    "!speak We are the Queen.",
    "!emote quickly snaps its jaws shut on a small gnat."
  }) );
  SetCombatAction(3, (: NastyBite :) );
  SetPosition(POSITION_SITTING);
  SetFriends( ({ "troglodyte" }) );
  SetMorality(-250);
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