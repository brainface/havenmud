/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: fire_elem.c
// Author: Matt Moran
// Immortal: moranm@mcmaster.ca
// Creation Date: Unknown
// Abstract: fire elemental
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <damage_types.h>
#include "../jidoor.h"
inherit LIB_NPC;

static void create()    {
    npc::create();

  SetKeyName ("elemental");
  SetId ( ({"elemental"}) );
  SetAdjectives ( ({"fire"}) );
  SetShort ("a fire elemental");
  SetLong (
    "This denizen of fire has been summoned forth by Zaxan to stand guard "
    "over the Tower of Fire.  Composed entirely of flame, the elemental "
    "can harm with a touch of it's fiery limb.  It's eyes glow with a "
    "certain intelligence, warning that it would not be easy to defeat it "
    "in combat.");

  SetRace ("elemental");
  SetGender ("neuter");
  SetClass ("fighter");
  SetSkill ("knife defense", 1,1);
  SetSkill ("slash defense", 1,2);
  SetSkill ("melee defense", 1,2);
  SetSkill ("melee attack", 1,1);
  SetLevel (40);
  SetMeleeDamageType(HEAT);

  SetCombatAction (3, ({
    "!emote waves a limb at you, scorching you with its heat.",
    "!emote intensifies its heat in an attempt to burn you.",
    "!emote lets loose a wave of flame at your head.",
    }) );
}

  





