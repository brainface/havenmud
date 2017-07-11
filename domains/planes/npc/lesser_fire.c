#include <lib.h>
#include "../planes.h"
#include <damage_types.h>
inherit LIB_NPC;

void eventSpecial();

static void create() {
  mapping inventory;
  npc::create();
  SetKeyName("lesser elemental");
  SetId( ({ "fire elemental", "elemental" }) );
  SetAdjectives( ({ "lesser" }) );
  SetShort("a lesser fire elemental");
  SetLong("This is a four foot tall child-shaped creature made entirely of "
          "fire.  Small flames jump up and down from his body as he moves. ");

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
  SetInventory(inventory);

  SetRace("elemental");
  SetGender("male");
  SetClass("rogue");
  SetLevel(101); // Torak 8/26/13
  SetCombatAction(6, (: eventSpecial :) );
  SetEncounter(30);
  SetFirstCommands("wield axes");
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
    "$agent_name%^RED%^ $agent_verb%^RESET%^ $target_name with a small ball of flame spit from $agent_possessive mouth.", 
    who, target, environment() );
  target->eventReceiveDamage(who, HEAT, random(150), 1, target->GetRandomLimb("head") );
  return;
}
