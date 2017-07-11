#include <lib.h>
#include <damage_types.h>
#include "../outpost.h"

inherit LIB_NPC;

void BearHug();

static void create() {
  npc::create();
  SetKeyName("ice bear");
  SetId( ({ "bear", "ice bear" }) );
  SetAdjectives( ({ "ice" }) );
  SetShort("an ice bear");
  SetLong("This large animal is covered in thick pure white fur which covers "
          "his whole body expect his black nose and black mouth. This bear "
          "looks like it has been breed for war.");
  SetGender("male");
  SetRace("bear");
  SetClass("animal");
  SetLevel(150);
  SetAction(1, ({
    "!growl angrily",
    }) );
  SetCombatAction(10, (: BearHug() :));
  SetInventory( ([
    OP_OBJ + "bear_armour" : "wear plate armour",
    ]) );
}


void BearHug() {
  object target = GetCurrentEnemy();
  
  if(target->GetPosition() < 3)
  if((present(target)) && (target->GetPosition() < 3)) {
    send_messages("squeeze", "%^BOLD%^%^CYAN%^ $agent_name stands up on "
                  "$agent_possessive rear paws $agent_verb $target_name "
                  "nearly crushing $target_objective.%^RESET%^",
                  this_object(), target, environment() ); 
    target->eventCollapse(1);
    target->SetParalyzed(5);
    target->AddRecoveryTime(100);
    target->eventReceiveDamage(this_object(),BLUNT, 500, 1, "torso");
  }
}