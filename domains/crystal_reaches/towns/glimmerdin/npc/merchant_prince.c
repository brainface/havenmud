#include <lib.h>
#include "../path.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("minas");
  SetShort("Minas the Merchant Prince");
  SetId( ({ "minas", "merchant", "prince", "dwarf"}) );
  SetAdjectives( ({ "merchant", }) );
  SetRace("dwarf");
  SetClass("fighter");
  SetSkill("chain armour",1,2);
  SetSkill("dodge",1,2);
  SetSkill("combat rage",1,1);
  SetSkill("accuracy",1,2);
  SetSkill("parry",1,2);
  
  
  AddTrainingSkill("mining");
  AddTrainingSkill("bargaining");
  AddTrainingSkill("fishing");
  AddTrainingSkills("metal working");
  AddTrainingSkills("wood working");
  AddTrainingSkills("mithril working");
  AddTrainingSkills("leather working");
  AddTrainingSkills("textile working");
  AddTrainingSkills("natural working");
  AddTrainingSkills("armour smithing");
  AddTrainingSkills("weapon smithing");
  AddTrainingSkill("farming");
  AddTrainingSkill("hack combat");
  AddTrainingSkill("melee combat");
  AddTrainingSkill("slash combat");
  AddTrainingSkill("blunt combat");
  AddTrainingSkill("pole combat");
  AddTrainingSkill("knife combat");
  AddTrainingSkill("projectile combat");
  SetLong(
    "Minas is a Merchant Prince, someone who has much experience "
    "in all things that are important to trading in Kailie. He "
    "is more than willing to teach those who are prepared to <ask>."
    );
  SetGender("male");
  SetTown("Glimmerdin");
  SetLevel(50);
  SetInventory( ([
    G_OBJ "chainmail" : "wear chainmail",
    G_OBJ "copper_axe" : "wield axe",
    ]) );
  SetMorality(300);
  SetCurrency("nuggets", 200);
}
