/* A fire elemental for the fire plane with a special attack */
// mahkafel april '10: added armour & weapons
#include <lib.h>
#include "../planes.h"
#include <damage_types.h>
inherit LIB_NPC;
inherit LIB_FEAR;

void eventSpecial();

static void create() {
  mapping inventory;

  npc::create();
  SetKeyName("fire elemental");
  SetId( ({ "fire elemental", "elemental" }) );
  SetAdjectives( ({ "fire" }) );
  SetShort("a fire elemental");
  SetLong("A fire elemental is a towering beast from the plane of Fire "
          "whose very essence is that of flame.  It is known for its "
          "incredibly volatile temper, especially to those intruding on its "
          "domain.");
  SetGender("male");
  SetRace("elemental");
  SetClass("rogue");
  SetLevel(120); // Torak 8/26/13

  // give random weapons
  switch(random(2)) {
    case 0:
      inventory = ([
        PLANE_OBJ "fire_scimitar" : "wield scimitar",
      ]);
    break;
    case 1:
      inventory = ([
        PLANE_OBJ "fire_axe" : 2
      ]);
  }
  // give armour
  inventory[PLANE_OBJ "obsidian_armour"] = "wear breastplate";

  SetFearLength(15);
  SetFearType("elemental fear");
  SetCombatAction(3, (: eventSpecial :) );
  SetEncounter(100);
  SetFirstCommands( ({"wield axes"}) );// doesn't matter if this fires when he has no axes
  SetInventory(inventory);
  SetMeleeAttackString("flaming hand");
  SetMeleeDamageType(HEAT);
  SetResistance(WATER, "weakness");
  SetResistance(COLD, "weakness");
  SetResistance(MAGIC, "high");
  SetResistance(HEAT, "immune");
  SetResistance(BLUNT, "immune");
  SetResistance(SLASH, "immune");
  SetResistance(PIERCE, "immune");
  SetResistance(HUNGER, "medium");
  SetResistance(DISEASE, "high");
  SetResistLevel(60);
  SetStat("wisdom", 100000, 1);

}

void eventSpecial() {
  object who = this_object();
  object target = GetCurrentEnemy();
  
  send_messages("immolate",
    "$agent_name%^RED%^ $agent_verb%^RESET%^ $target_name "
    "with a huge pillar of flame!", who, target, environment() );
  target->eventReceiveDamage(who, HEAT, random(500), 0,
    target->GetRandomLimb("head") );
  return;
}

void init() {
  npc::init();
  fear::init();

}

