/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: earth_elem.c
// Author: Matt Moran
// Immortal: moranm@mcmaster.ca
// Creation Date: Unknown
// Abstract: earth elemental
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <damage_types.h>
#include "../jidoor.h"
inherit LIB_NPC;

void eventSpecial();

static void create()    {
    npc::create();

  SetKeyName ("elemental");
  SetId ( ({"elemental","jidoor_npc",}) );
  SetAdjectives (({"earth"}) );
  SetShort ("an earth elemental");
  SetLong (
    "At first glance, this denizen of earth appears to be nothing more "
    "than a mound of earth.  However, its shifting form speaks "
    "otherwise.  Standing a good 10 feet tall, this elemental has "
    "been charged by Zaxan himself to defend the Tower of Earth.  Its "
    "body is composed of clay, stone and roots, while two blue orbs "
    "mark its eyes.  It looks like it could crush an opponent with "
    "one solid blow.");

  SetRace ("elemental");
  SetGender ("neuter");
  SetClass ("fighter");
  SetSkill ("melee combat", 1,1);
  SetLevel (40);

  SetMeleeAttackString("stone fist");
  SetMeleeDamageType(ACID);
  SetInventory(([
    JID_OBJ "/staff_earth" : "wield staff",
  ]));

  // earth elemental resists
  SetResistance(ACID|BLUNT, "immune");
  SetResistance(HEAT|SLASH|COLD, "high");
  // um, lightning strike, pickaxes,
  // and flash floods hurt? iunno.
  SetResistance(PIERCE|SHOCK|WATER, "low");  

  // elemental feeds not.
  SetResistance(HUNGER, "medium");
  SetResistance(DISEASE, "medium");

  /*SetCombatAction (2, ({
    "!emote attempts to crush you under its weight.",
    "!emote hurls a clog of stone and dirt in your face, blinding you "
    "momentarily."
    }) );*/

  SetCombatAction(15, (: eventSpecial :) );
}

void eventSpecial() {
  object who = this_object();
  object target = GetCurrentEnemy();
  string limb = target->GetRandomLimb();
  send_messages("stomp",
    "$agent_name%^BOLD%^YELLOW%^ $agent_verb%^RESET%^ $target_name the ground "
    "with a huge foot, shaking the ground next to $target_name!",
    who, target, environment() );
  target->eventReceiveDamage(who, BLUNT, GetDamage(60, "melee combat",
    target->GetDefense()), 0, limb );
  // shold be a skill check, but fukkit.
  if (!random(10)) {
    target->eventCollapse();
  }
  return;
}
