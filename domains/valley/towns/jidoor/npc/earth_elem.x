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
  
  SetStat("wisdom", 100000, 1);
  SetResistance(WATER, "weakness");
  SetResistance(HEAT, "immune");
  SetResistance(ACID, "immune");
  SetResistance(COLD, "medium");
  SetResistance(MAGIC, "medium");
  SetResistance(SHOCK, "medium");
  
  SetResistance(BLUNT, "immune");
  SetResistance(SLASH, "immune");
  SetResistance(PIERCE, "immune");
  SetResistance(HUNGER, "medium");
  SetResistance(DISEASE, "medium");
  SetCombatAction (2, ({
    "!emote attempts to crush you under its weight.",
    "!emote hurls a clog of stone and dirt in your face, blinding you "
    "momentarily."  
    }) );
}

  





