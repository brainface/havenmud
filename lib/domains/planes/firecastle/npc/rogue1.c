//
// filename: rogue1
// Thoin@Haven 01-16-06
//

#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include "../firecastle.h"
inherit LIB_NPC;
inherit LIB_FEAR;
int eventCheckPlayer();
void eventSpecial();

static void create() {
  npc::create();
  SetKeyName("elemental rogue");
  SetId( ({ "rogue" }) );
  SetShort("an elemental rogue");
  SetLong(
          "This elemental is completely composed of brightly burning fire. It "
          "is considerably larger then other elementals that exist on the "
          "plane of Fire but like the others its volatile temper is only "
          "matched by its fire."
  );
  SetAdjectives( ({ "elemental", "fire" }) );
  SetRace("elemental");
  SetClass("rogue");
  SetLevel(150);
  AddLimb ("right arm","torso",2,({A_SHIELD,A_BODY_ARMOUR}));
  AddLimb ("left arm","torso",2, ({A_BODY_ARMOUR}));
  AddLimb ("right leg","torso",2, ({A_BODY_ARMOUR}));
  AddLimb ("left leg","torso",2,({A_BODY_ARMOUR}));
  AddLimb ("right hand","right arm",4,({A_BODY_ARMOUR}));
  AddLimb ("left hand","left arm",4, ({A_WEAPON,A_BODY_ARMOUR}));
  AddLimb ("right foot","right leg",4,({A_BODY_ARMOUR}));
  AddLimb ("left foot","left leg",4,({A_BODY_ARMOUR}));
  SetLanguage("Archaic", 100, 1);
  RemoveLanguage("Elementalish");
  SetStat("durability", 300, 1);
  SetStat("strength", 300, 1);
  SetStat("luck", 300, 1);
  SetStat("wisdom", 300, 1);
  SetStat("charisma", 300, 1);
  SetNoCorpse(1);
  SetDie("The elemental dissipates into the air."); 
  SetResistance(WATER, "weakness");
  SetResistance(COLD, "weakness");
  SetResistance(MAGIC, "high");
  SetResistance(HEAT, "immune");
  SetResistance(BLUNT, "immune");
  SetResistance(SLASH, "immune");
  SetResistance(PIERCE, "immune");
  SetResistance(HUNGER, "medium");
  SetResistance(DISEASE, "high");
  SetEncounter( (: eventCheckPlayer :) );
  SetCombatAction(10, (: eventSpecial :) );
  SetFearType("elemental fear");
  SetResistLevel(140);
  SetFearLength(10);
  SetInventory ( ([
    FCASTLE_OBJ "/elem_knife2" : "wield knife",
    ]) );  
    SetCombatStyle("blade dancing");
    SetCombatStyleLevel("blade dancing", 100);
  }
  
void init() {
  npc::init();
  fear::init();

  }

int eventCheckPlayer() {
  object who = this_player();
  if (userp(who)) {
     eventForce("backstab " + who->GetKeyName());
     return 1;
    }
  else return 0;
 }

void eventSpecial() {
  object who = this_object();
  object target = GetCurrentEnemy();
  
  send_messages("immolate",
      "$agent_name%^RED%^ $agent_verb%^RESET%^ $target_name "
      "with a huge pillar of flame!", who, target, environment() );
    target->eventReceiveDamage(who, HEAT, random(500)+200, 0,
            target->GetRandomLimb("head") );
      return;
  }
