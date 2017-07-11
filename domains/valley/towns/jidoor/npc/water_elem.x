/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: water_elem.c
// Author: Matt Moran
// Immortal: moranm@mcmaster.ca
// Creation Date: Unknown
// Abstract: water elemental
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <damage_types.h>
#include "../jidoor.h"
inherit LIB_NPC;

static void create()    {
    npc::create();

  SetKeyName ("elemental");
  SetId ( ({"elemental","jidoor_npc"}) );
  SetAdjectives ( ({"water"}) );
  SetShort ("a water elemental");
  SetLong (
    "This denizen of the water plane has been summoned by his Lord Zaxan "
    "to defend the Tower of Water.  Writhing like a snake, the water "
    "elemental stands about eight feet high.  It has two glowing orbs for eyes, "
    "but no limbs that seem permanent.  It looks as if it could kill an "
    "opponent simply by drowning him or her.");

  SetRace ("elemental");
  SetGender ("neuter");
  SetClass ("fighter");
  SetSkill ("melee combat", 1,1);
  SetLevel (40);
  SetMeleeAttackString("watery tentacles");
  SetMeleeDamageType(WATER);
  
  SetStat("wisdom", 100000, 1);
  SetResistance(WATER, "immune");
  SetResistance(HEAT, "low");
  SetResistance(COLD, "immune");
  SetResistance(ACID, "immune");
  SetResistance(SHOCK, "weakness");
  SetResistance(MAGIC, "medium");

  SetResistance(BLUNT, "immune");
  SetResistance(SLASH, "immune");
  SetResistance(PIERCE, "immune");
  SetResistance(HUNGER, "medium");
  SetResistance(DISEASE, "medium");
  
  SetCombatAction (2, ({
    "!emote wraps its watery tentacles around your face, attempting to "
    "drown you.",
    "!emote snakes out with a watery limb directly for your head.",    
    }) );
}

  




