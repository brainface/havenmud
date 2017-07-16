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
  SetId ( ({"elemental"}));
  SetAdjectives ( ({"air"}) );
  SetEncounter(50);
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
  SetSkill ("knife defense", 1,1);
  SetSkill ("slash defense", 1,1);
  SetSkill ("projectile defense", 1,1);
  SetSkill ("melee attack", 1,1);
  SetLevel (40);
  SetMeleeDamageType(COLD);

  SetCombatAction (2, ({
    "!emote waves a limb, sending a blast of cold that chills you "
    "to the bone",
    "!emote pulls the air from your lungs, making it difficult to "
    "breathe.",
    }) );
}

  




