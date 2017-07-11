
/* Ranger Spell to turn objects into food.
 * Created 12 Sept 1997
 * Duuktsaryth@Haven
 */
#include <lib.h>
#include <magic.h>
#define FOOD_OBJ "/std/meal/food/ranger_food"
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("transmorph");
  SetRules("OBJ");
  SetSkills( ([
     "enchantment" : 15,
     "natural magic" : 15,
     ]) );
  SetMagicCost(40, 20);
  SetSpellType(SPELL_OTHER);
  SetHelp(
     "Turns any object or objects into a foodlike substance "
     "which can be eaten."
    );
 }

int CanCast(object who, int level, mixed limb, object *targets) {
  mixed can_get;
  if (!sizeof(targets)) {
      message("system", "Cast it on what?.", who);
      return 0;
  }
  foreach(object thing in targets) {
    can_get = thing->CanGet(who);
    if (!intp(can_get)) {
      who->eventPrint(can_get);
      return 0;
    }
    if ((environment(thing) != who) && (environment(thing) != environment(who))) {
       message("system", capitalize(thing->GetShort()) + " is not on your person or in the area!", who);
       return 0;
    }
    if (thing->GetUserCorpse()) { 
      who->eventPrint("That corpse refuses to be turned into food.");
      return 0;
    }
if (thing->GetValue() == 0) {
      who->eventPrint("That would be worthless to eat.");
      return 0;
    }
    if(thing->GetProperty("transmorphed")) {
      message("system", capitalize(thing->GetShort()) + "has already been transmorphed!", who);
      return 0;
    }
  }
  return spell::CanCast(who, level, limb, targets);
}

varargs int eventCast(object who, int level, mixed limb, object array targets) {
  object new_food;

  foreach(object foodie in targets) {
     new_food = new(FOOD_OBJ);
     new_food->SetProperty("transmorphed", 1);
     new_food->SetShort("a meal that looks like " + foodie->GetShort());
     new_food->SetLong("This is a foodlike substance that looks like it "
                         "used to be " + foodie->GetShort() + ".");
     new_food->SetStrength(foodie->GetValue());
     //debug("Str should be : ");
     //debug(foodie->GetValue());
     new_food->SetMass(foodie->GetMass());
     new_food->SetValue(0);
     new_food->SetId(new_food->GetId() + foodie->GetId());
     new_food->SetAdjectives(new_food->GetAdjectives() + foodie->GetAdjectives());
   send_messages("turn",
      "$agent_name $agent_verb $target_name into food!",
        who, foodie, environment(who));
   new_food->eventMove(environment(foodie));
   foodie->eventDestruct();
   }
     return 1;
}

