#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include "../defs.h"

inherit LIB_SENTIENT;

static void create() {
  ::create();
//  sentient::create();
  SetRace("demon");
  SetGender("female");
  SetClass("fighter");
  AddSkill("melee combat",1);
  SetLevel(random(5)+68);
  SetKeyName("Shrieker");
  SetId( ({ "shrieker", "demon", "ferathou"}) );
  SetShort("Ferathou, the shrieker demon");
  SetAdjectives( ({ "demon" }) );
  SetLong(
          "This pale red skinned woman is one of the greater "
          "testaments of high necromancy. No pupils can "
          "be seen just a soft egg shell white. Shiny coal "
          "black hair flows around her gigantic curved horns down "
          "to her lower back. Seeping from her shiny "
          "form is a black fog and makes vision somewhat "
          "darker.");
  SetAction(5, ({
    "!guard kilwrath",
    "!emote stares at you with her blank eyes.",
  }) );
  SetCombatAction(7, ({
    "!guard kilwrath",
    "!disorient",
     "The shrieker screams: WRAAAAAAAAAAAAAAAAAAAAAA!!",
  }) );
  SetEncounter(200);
  SetRadiantLight(-10);
  SetMorality(-250);
  SetStat("charisma", 201, 1);
  SetFriends(({
               TOWER_NPC+"sumskeleton"
               TOWER_NPC+"necromancer"
               TOWER_NPC+"wcorpse"
               TOWER_NPC+"zombie"
  }));
  SetResistance(ACID, "high");
  SetResistance(GAS, "high");
  SetResistance(HUNGER, "high");
  SetResistance(DISEASE, "high");
  SetNoCorpse(1);
  SetDie("The demon energies wane into a wooden ring, which "
         "materialize on the ground in her place.");
 SetFirstCommands( ({
    "guard kilwrath"
    }) );
 
}

 varargs int eventDie(object killer) {
    object wring;
  wring = new(TOWER_OBJ+"wring");
  wring->eventMove(this_object());
  sentient::eventDie(killer);
  }


