#include <lib.h>
#include <std.h>
#include "../trog.h"
#include <damage_types.h>
inherit LIB_NPC;

int NastyBite();

static void create() {
  ::create();
  SetKeyName("troglodyte worker");
  SetRace("troglodyte");
  SetShort("a weak brownish-green creature");
  SetId( ({ "troglodyte", "worker", "creature" }) );
  SetAdjectives( ({ "weak", "troglodyte", "brownish", "green", "brown" }) );
  SetLong(
    "This small creature is a troglodyte. It makes its home in the tunnels "
    "under Mount Trog. The creature is a fierce, nasty thing with large "
    "teeth and an oozing drool. This weak creature is a troglodyte worker."
    );
  SetClass("merchant");
  SetLevel(4);
  SetMeleeAttackString("teeth");
  SetMeleeDamageType(PIERCE);
  SetAction(5, ({
    "!emote looks around the cave.",
    "!emote busily gnaws at the tunnel walls.",
    "!emote quickly snaps its jaws shut on a small gnat."
  }) );
  SetCombatAction(3, (: NastyBite :) );
  SetInventory( ([
    STD_LIGHT "torch" : "wield torch",
    ]) );
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