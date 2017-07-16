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
  SetId ( ({"elemental"}) );
  SetAdjectives ( ({"water"}) );
  SetShort ("a water elemental");
  SetLong (
    "This denizen of the water plane has been summoned by his Lord Zaxan "
    "to defend the Tower of Water.  Writhing like a snake, the water "
    "elemental stands about 8 feet high.  It has two glowing orbs for eyes, "
    "but no limbs that seem permanent.  It looks as if it could kill an "
    "opponent simply by drowning him or her.");

  SetRace ("elemental");
  SetGender ("neuter");
  SetClass ("fighter");
  SetSkill ("knife defense", 1,1);
  SetSkill ("slash defense", 1,2);
  SetSkill ("projectile defense", 1,1);
  SetSkill ("melee attack", 1,1);
  SetLevel (40);
  SetMeleeDamageType(WATER);

  SetCombatAction (2, ({
    "!emote wraps its watery tentacles around your face, attempting to "
    "drown you.",
    "!emote snakes out with a watery limb directly for your head.",    
    }) );
}

  




