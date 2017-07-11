#include <lib.h>
#include "../trog.h"
#include <damage_types.h>
inherit LIB_NPC;

int NastyBite();

static void create() {
  ::create();
  SetKeyName("troglodyte warrior");
  SetRace("troglodyte");
  SetShort("a muscular brownish-green creature");
  SetId( ({ "troglodyte", "warrior", "creature" }) );
  SetAdjectives( ({ "muscular", "troglodyte", "brownish", "green", "brown" }) );
  SetLong(
    "This muscular creature is a troglodyte. It makes its home in the tunnels "
    "under Mount Trog. The creature is a fierce, nasty thing with large "
    "teeth and an oozing drool. This variety is a troglodyte warrior, bred "
    "to be larger and meaner."
    );
  SetClass("fighter");
  SetLevel(5);
  SetMeleeAttackString("teeth");
  SetMeleeDamageType(PIERCE);
  SetAction(5, ({
    "!emote looks around the cave.",
    "!speak We defend the burrow!",
    "!speak Our hive!",
  }) );
  SetCombatAction(3, (: NastyBite :) );
  SetInventory( ([
    TROG_OBJ "club" : "wield club",
    ]) );
  SetFriends( ({ "queen" }) );
  SetMorality(-150);
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