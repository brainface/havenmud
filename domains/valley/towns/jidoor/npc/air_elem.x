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
  
  SetStat("wisdom", 100000, 1);
  SetResistance(WATER, "immune");
  SetResistance(HEAT, "weakness");
  SetResistance(ACID, "low");
  SetResistance(COLD, "immune");
  SetResistance(MAGIC, "medium");
  SetResistance(SHOCK, "immune");
  
  SetResistance(BLUNT, "immune");
  SetResistance(SLASH, "immune");
  SetResistance(PIERCE, "immune");
  SetResistance(HUNGER, "medium");
  SetResistance(DISEASE, "medium");
  SetCombatAction (2, ({
    "!emote waves a limb, sending a blast of cold that chills you "
    "to the bone",
    "!emote pulls the air from your lungs, making it difficult to "
    "breathe.",
    }) );
}

  




