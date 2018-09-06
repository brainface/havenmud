/* Acrobatics trainer
 * for staff combat actions
 * Mahkefel 2017
 *
 */
#include <lib.h>
#include "../coffee.h"

inherit LIB_TRAINER;
static void create() {
  ::create();
  SetKeyName("Helial");
  SetId( ({"helial", "wanderer", "gelfling"}) );
  SetShort("Helial the Wanderer (gelfling)");
  SetLong(
    "Inordinately tall for a gelfling, Helial bears the dust and dirt of "
    "years of travelling, a fine layer of dust and grime seemingly worked "
    "into every wrinkle in his face and fold in his unassuming clothes. "
    "The walking stick in his hands looks like it's travelled as far as he "
    "has, and the collected dents and fine cracks in it suggests every step "
    "hasn't been peaceful."
  );

  SetGender("male");
  SetRace("gelfling");
  SetClass("acrobat");
  SetLevel(150);
  SetMorality(500);
  SetCurrency("imperials",random(50)+50);
 
    AddTrainingSkill("acrobatics");
    AddTrainingSkill("pole combat");
    AddTrainingSkill("melee combat");
  SetAction(5, ({
    "!say Sit, and stay a while.",
    "!say The trick is knowing exactly when to move.",
    "!say I could tell you a few things to keep you safe on the road.",
    "!say I suppose I've been a little bit of everywhere.",
    "!say No one can bar your path if you don't let them.",
    "!say When in doubt, MOVE.",
    "!say People look at a stick of wood, and they see a crutch. People look "
      "at a sword, they see a weapon. Don't change their mind until you have to.",
  }) );
  SetCombatAction(65,({
    "!disorient",
    "!disarm",
    "!sweep",
    "!jab",

    "!jab",
    "!jab",
    "!polevault",
  }) );
  SetInventory( ([
    COFFEE_OBJ "acro_staff" : "wield staff",
    COFFEE_OBJ "acro_cloak" : "wear cloak",
    COFFEE_OBJ "acro_necklace" : "wear necklace",
  ]) );
}
