/* A minor elemental for xandrian desert
// Blinds as a special
// mahkafel september '10
*/

#include <lib.h>
#include <damage_types.h>
#include <domains.h>
inherit LIB_NPC;

void eventSpecial();

static void create() {
  npc::create();
  SetKeyName("dust devil");
  SetId( ({ "dust devil", "devil" }) );
  SetAdjectives( ({ "dust" }) );
  SetShort("a dust devil");
  SetLong("A dust devil is a vaguely humanoid column of whirling dust and "
    "wind that haunts the desert of Xandria. Though not as dangerous as a "
    "true planar elemental, they can be deadly to the unexpecting traveller "
    "in the desert wastes." );
  SetGender("male");
  SetRace("elemental");
  SetClass("rogue");
  SetLevel(25);
  SetAction(20, ({
    "!emote whirls lazily.",
    "!screech",
  }) );
  SetCombatAction(15, (: eventSpecial :) );
  SetEncounter(50);
  SetFirstCommands( ({"wield khopesh"}) );
  SetInventory(([ XANDRIA_VIRTUAL "desert/glass_khopesh" : 1 ]));
  SetMeleeAttackString("gritty hand");
  SetMeleeDamageType(HEAT);
  SetResistance(WATER|COLD|MAGIC, "weakness");
  SetResistance(HEAT, "immune");
  SetResistance(BLUNT|SLASH|PIERCE|HUNGER|DISEASE, "medium");
  SetStat("charisma",101); // hack to annoy duuk slightly.
}

void eventSpecial() {
  object who = this_object();
  object target = GetCurrentEnemy();
  send_messages("scour",
    "$agent_name%^YELLOW%^ $agent_verb%^RESET%^ $target_name "
    "with an fierce gust of wind and sand!", who, target, environment() );
  target->eventReceiveDamage(who, HEAT|PIERCE, random(100), 0,
    target->GetRandomLimb("head") );
  target->eventBlind(1,2);
  return;
}

void init() {
  npc::init();
}

