#include <lib.h>
#include "../planes.h"
#include <damage_types.h>
inherit LIB_NPC;

void eventSpecial();

static void create() {
  npc::create();
  SetKeyName("lesser elemental");
  SetId( ({ "fire elemental", "elemental" }) );
  SetAdjectives( ({ "lesser" }) );
  SetShort("a lesser fire elemental");
  SetLong("This is a four foot tall child-shaped creature made entirely of "
          "fire.  Small flames jump up and down from his body as he moves. ");
  SetRace("elemental");
  SetGender("male");
  SetClass("rogue");
  SetLevel(60);
  SetCombatAction(6, (: eventSpecial :) );
  SetEncounter(30);
  SetMeleeAttackString("flaming hand");
  SetMeleeDamageType(HEAT);
  SetStat("wisdom", 100000, 1);
  SetResistance(WATER, "weakness");
  SetResistance(COLD, "weakness");
  SetResistance(HEAT, "immune");
  SetResistance(MAGIC, "medium");
  SetResistance(BLUNT, "immune");
  SetResistance(SLASH, "immune");
  SetResistance(PIERCE, "immune");
  SetResistance(HUNGER, "medium");
  SetResistance(DISEASE, "medium");
}

void eventSpecial() {
  object who = this_object();
  object target = GetCurrentEnemy();

  if (!target) return;
  send_messages("burn",
    "$agent_name%^RED%^ $agent_verb%^RESET%^ $target_name with a small ball of flame spit from $target_possessive mouth.", 
    who, target, environment() );
  target->eventReceiveDamage(who, HEAT, random(150), 1, target->GetRandomLimb("head") );
  return;
}
