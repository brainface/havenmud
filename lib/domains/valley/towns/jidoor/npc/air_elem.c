/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: air_elem.c
// Author: Matt Moran
// Immortal: moranm@mcmaster.ca
// Creation Date: Unknown
// Abstract: air elemental
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <damage_types.h>
#include "../jidoor.h"
inherit LIB_NPC;

void eventSpecial();

static void create()    {
    npc::create();

  SetKeyName ("elemental");
  SetId ( ({"elemental","jidoor_npc"}));
  SetAdjectives ( ({"air"}) );
  SetShort ("an air elemental");
  SetLong (
    "The hint of a humanoid form amidst the mist indicates that a "
    "denizen of air is present.  Once free to roam the elemental "
    "plane of air, it has now been commanded by Zaxan to keep watch "
    "over the tower.  It has the power to suck the very breath from "
    "an opponent, or to use its mist to freeze blood solid.");

  SetRace ("elemental");
  SetGender ("neuter");
  SetClass ("fighter");
  SetSkill ("melee combat", 1,1);
  SetLevel (40);

  SetMeleeAttackString("blast of air");
  SetMeleeDamageType(COLD);
  SetInventory(([
    JID_OBJ "/staff_air" : "wield staff",
  ]));

  // air elemental
  SetResistance(COLD|SHOCK, "immune");
  SetResistance(HEAT|ACID, "weakness");

  // elemental resistance
  SetResistance(BLUNT|SLASH|PIERCE, "immune");
  SetResistance(HUNGER|DISEASE, "medium");
  /*SetCombatAction (2, ({
    "!emote waves a limb, sending a blast of cold that chills you "
    "to the bone",
    "!emote pulls the air from your lungs, making it difficult to "
    "breathe.",
    }) );*/
  SetCombatAction( 15, (: eventSpecial :) );
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

