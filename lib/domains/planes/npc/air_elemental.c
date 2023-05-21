/* A air elemental for the air plane with a special attack */
#include <lib.h>
#include "../planes.h"
#include <damage_types.h>
inherit LIB_NPC;
inherit LIB_FEAR;

void eventSpecial();

static void create() {
  npc::create();
  SetKeyName("air elemental");
  SetId( ({ "elemental" }) );
  SetAdjectives( ({ "air" }) );
  SetShort("an air elemental");
  SetLong("An air elemental is a wispy creature from the Upper Planes "
          "whose very essence is that of nebulous air.  It is known for its "
          "incredibly volatile temper, especially to those intruding on its "
          "domain.");
  SetGender("male");
  SetRace("elemental");
  SetClass("fighter");
  SetLevel(90);
  SetStat("wisdom", 100000, 1);
  SetFearType("elemental fear");
  SetResistLevel(50);
  SetFearLength(15);
  SetCombatAction(3, (: eventSpecial :) );
  SetEncounter(100);
  SetMeleeAttackString("frigid blast");
  SetResistance(COLD, "immune");
  SetMeleeDamageType(COLD);
  SetMorality(1000);
  SetInventory( ([
    PLANE_OBJ "sickle" : 2,
    PLANE_OBJ "air_rags" : "wear rags",
  ]) );
  SetFirstCommands( ({
    "wield sickles",
  }) );
}

void eventSpecial() {
  object who = this_object();
  object target = GetCurrentEnemy();
  string limb = target->GetRandomLimb();
  send_messages("freeze",
    "$agent_name%^RED%^ $agent_verb%^RESET%^ $target_name with a huge torrent of snow!", 
    who, target, environment() );
  target->eventReceiveDamage(who, COLD, GetDamage(60, "melee combat",
    target->GetDefense()), 0, limb );
  return;
}

void init() {
  npc::init();
  fear::init();
}

