// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("stew");
  SetId( ({ "dwarves head stew", "stew" }) );
  SetAdjectives( ({ "dwarves", "dwarves", "dwarf", "head" }) );
  SetShort("a bowl of dwarves head stew");
  SetLong(
    "This stew is made of ground up dwarves heads in a base "
    "of sheep bullion. It is a well-loved orcish delicacy and "
    "is often served during post-victory celebrations, when the "
    "ingredients are easily avaliable."
  );
  SetMass(40);
  SetMealType(MEAL_FOOD);
  SetStrength(20);
  SetMealMessages(
    "The dwarves head stew is piping hot and delicious.", 
    "$N gobbles up a bowl of dwarves' head stew."
  );
}
