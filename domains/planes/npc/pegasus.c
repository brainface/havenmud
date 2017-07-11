#include <lib.h>
#include <damage_types.h>
#include "../planes.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("pegasus");
  SetShort("a white winged pegasus");
  SetMorality(1000);
  SetId( ({ "pegasus" }) );
  SetAdjectives( ({ "white", "winged" }) );
  SetRace("pegasus");
  SetClass("animal");
  SetGender("male");
  SetLevel(50);
  SetLong(
    "This large horse-like creature is a pegasus. It is white and pure "
    "as driven snow, but also features large bird wings protruding from "
    "its torso."
    );
  SetAction(5, ({
    "!emote leaps into the air and prances while gently settling back down.",
    "!emote flaps his wings softly.",
    }) );
  SetCombatAction(6, (: eventBite :) );
  SetWander(2);
  SetLimit(6);
}

int eventBite() {
  object who = GetCurrentEnemy();
  int damage;
  string limb;
  if (!who) return 0;
  
  limb = who->GetRandomLimb();
  damage = GetDamage(40, "melee combat", who->GetDefense());
  send_messages( ({ "rear", "bite" }),
    "$agent_name%^BOLD%^WHITE%^ $agent_verb back his head and $agent_verb%^RESET%^ $target_possessive_noun " + limb + "!",
    this_object(), who, environment() );
  who->eventReceiveDamage(this_object(), PIERCE|MAGIC, damage, 0, limb);
  return 1;
}
  