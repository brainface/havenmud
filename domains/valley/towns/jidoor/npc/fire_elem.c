/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: fire_elem.c
// Author: Matt Moran
// Immortal: moranm@mcmaster.ca
// Creation Date: Unknown
// Abstract: fire elemental
/* ----------------------------------------------------------------------- */

// mahkefel 2012: normalized resistances, gave attack like other fire elementals.
// i don't know wtf LOLWISDOM is for, but they no longer are wiser than buddha.

#include <lib.h>
#include <damage_types.h>
#include "../jidoor.h"
inherit LIB_NPC;

void eventSpecial();

static void create()    {
    npc::create();

  SetKeyName ("elemental");
  SetId ( ({"elemental","jidoor_npc",}) );
  SetAdjectives ( ({"fire"}) );
  SetShort ("a fire elemental");
  SetLong (
    "This denizen of fire has been summoned forth by Zaxan to stand guard "
    "over the Tower of Fire.  Composed entirely of flame, the elemental "
    "can harm with a touch of its fiery limb.  Its eyes glow with a "
    "certain intelligence, warning that it would not be easy to defeat it "
    "in combat.");

  SetRace("elemental");
  SetGender("neuter");
  SetClass("fighter");
  SetSkill("melee combat", 1,1);
  SetLevel (40);

  SetMeleeAttackString("flaming fist");
  SetMeleeDamageType(HEAT);
  SetInventory( ([
    JID_OBJ "/staff_fire" : "wield staff"
  ]) );


  // wtf? SetStat("wisdom", 100000, 1);
  // fire creature
  SetResistance(COLD|WATER, "weakness");
  SetResistance(SHOCK, "medium");
  SetResistance(HEAT, "immune");

  // and elemental
  SetResistance(BLUNT|PIERCE|SLASH, "immune");
  SetResistance(HUNGER|DISEASE, "medium");
  /*
  SetCombatAction (3, ({
    "!emote waves a limb at you, scorching you with its heat.",
    "!emote intensifies its heat in an attempt to burn you.",
    "!emote lets loose a wave of flame at your head.",
    }) );*/
  SetCombatAction(15, (: eventSpecial :) );
}

void eventSpecial() {
  object who = this_object();
  object target = GetCurrentEnemy();

  if (!target) return;
  send_messages("immolate",
      "$agent_name%^RED%^ $agent_verb%^RESET%^ $target_name with a huge pillar of flame!",
      who, target, environment() );
  target->eventReceiveDamage(who, HEAT, random(500), 0, target->GetRandomLimb("head") );
  return;
}

