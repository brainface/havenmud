/*  The greater water Lagoon    
    Thoin@Haven                 
    4/16/07                     
*/                              
// may '10, mahkefel: added armour damage, increased freq.

#include <lib.h>
#include "../lagoon.h"
#include <damage_types.h>
inherit LIB_NPC;         
inherit LIB_FEAR;        

void eventSpecial();

static void create() {
  npc::create();      
  SetKeyName("greater water elemental");
  SetId( ({ "elemental" }) );           
  SetAdjectives( ({ "greater",  "water", }) );
  SetShort("a greater water elemental");      
  SetLong(                                    
    "A greater water elemental is a towering beast formed of pure blue water, whose "
    "very core is translucent.  It is known for its incredibly volatile temper, especially "
    "to those intruding on its domain."
    );
  SetRace("elemental");
  SetClass("fighter");
  SetLevel(160);
  SetFearType("%^BLUE%^cold fear%^RESET%^");
  SetResistLevel(120);
  SetFearLength(15);
    SetCombatAction(10, (: eventSpecial :) );
  SetEncounter(100);
  SetMeleeAttackString("watery spray");
  SetMeleeDamageType(WATER);
  SetResistance(HEAT,"weakness");
  SetResistance(WATER,"immune");
  SetResistance(COLD,"high");
}

void eventSpecial() {
  object who = this_object();
  object target = GetCurrentEnemy();

  if (!who || !target) return;

  send_messages("drown",
      "$agent_name%^BLUE%^ $agent_verb%^RESET%^ $target_name with a huge gush of water!",
      who, target, environment() );
  target->eventReceiveDamage(who, WATER, 
    GetDamage(GetSkillLevel("melee combat"),
    "melee combat", target->GetDefense()) * 5,
    0, target->GetRandomLimb() );

  for(int i =0;i<random(4)+1;i++) {
      object array eq = all_inventory(target);
      if(sizeof(eq)) {
        object thing = (eq[random(sizeof(eq))]);
        send_messages("",
          "The gush of water %^BLUE%^erodes%^RESET%^ $target_possessive_noun " +
          remove_article(thing->GetShort())+"!",
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

