/*  The Ice Lagoon    
    Thoin@Haven       
    4/16/07           
*/                    
// mahkefel '10 may: added equipment damage.

#include <lib.h>
#include "../lagoon.h"
#include <damage_types.h>
inherit LIB_NPC;         
inherit LIB_FEAR;        

void eventSpecial();

static void create() {
  npc::create();      
  SetKeyName("lesser water elemental");
  SetId( ({ "elemental" }) );          
  SetAdjectives( ({ "lesser", "greater" }) );
  SetShort("a lesser water elemental");      
  SetLong("A water elemental is a towering beast formed of bubbling water "
          "whose limbs are nothing but jutting watery jets.  It is known for its "
          "incredibly volatile temper, especially to those intruding on its "     
          "domain.");                                                             
  SetRace("elemental");
  SetClass("fighter");
  SetLevel(120);
  SetFearType("%^BLUE%^squishy fear%^RESET%^");
  SetResistLevel(80);
  SetFearLength(15);
  SetCombatAction(5, (: eventSpecial :) );
  SetEncounter(100);
  SetMeleeAttackString("watery hand");
  SetMeleeDamageType(WATER);
}

void eventSpecial() {
  object who = this_object();
  object target = GetCurrentEnemy();

  if (!who || !target) return;

  send_messages("drown",
      "$agent_name%^BLUE%^ $agent_verb%^RESET%^ $target_name with a huge column of water!",
      who, target, environment() );
  target->eventReceiveDamage(who, WATER, GetDamage(GetSkillLevel("melee combat"),
    "melee combat", target->GetDefense()) * 3, 0,  target->GetRandomLimb() );

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

void init() {
  npc::init();
  fear::init();
}

