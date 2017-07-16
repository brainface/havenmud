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

void eventSpecial();

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
  SetInventory( ([
    JID_OBJ "/staff_water" : "wield staff",
  ]) );


  // WATER ELEMENTAL
  SetResistance(ACID|WATER, "immune");
  SetResistance(HEAT|SHOCK, "weakness");

  SetResistance(BLUNT, "immune");
  SetResistance(SLASH, "immune");
  SetResistance(PIERCE, "immune");
  SetResistance(HUNGER, "medium");
  SetResistance(DISEASE, "medium");

  /*SetCombatAction (2, ({
    "!emote wraps its watery tentacles around your face, attempting to "
    "drown you.",
    "!emote snakes out with a watery limb directly for your head.",
    }) );*/
  SetCombatAction( 15, (: eventSpecial :) );
}


void eventSpecial() {
  object who = this_object();
  object target = GetCurrentEnemy();

  if (!who || !target) return;

  send_messages("drown",
      "$agent_name%^BLUE%^ $agent_verb%^RESET%^ $target_name with a huge column of water!",
      who, target, environment() );
  target->eventReceiveDamage(who, WATER, GetDamage(GetSkillLevel("melee combat"),
    "melee combat", target->GetDefense()) * 1, 0,  target->GetRandomLimb() );

  if(sizeof(all_inventory(target))) {
    object thing = (all_inventory(target)[random(sizeof(all_inventory(target)))]);
      if(thing->GetMealType()) {
         send_messages("wash",
           "$agent_name%^BLUE%^ $agent_verb%^RESET%^ away $target_possessive_noun "
            + remove_article(thing->GetShort())
            + " with $agent_possessive gush of water!",
            who, target, environment(who));
            thing->eventDestruct();
       } else {
         send_messages("erode",
           "$agent_name%^BLUE%^ $agent_verb%^RESET%^ $target_possessive_noun "
            + remove_article(thing->GetShort())
            + " with $agent_possessive gush of water!",
            who, target, environment(who));
         thing->eventDeteriorate(WATER);
       }
    }
  return;
}

