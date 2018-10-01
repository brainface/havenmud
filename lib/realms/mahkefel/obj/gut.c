#include <lib.h>

inherit LIB_ITEM;

int GoalGetter(object who);

static void create() {
  item::create();
  SetKeyName("gut");
  SetShort("Torak's gut");
  SetId(({ "gut" }));
  SetAdjectives( ({ "torak's","toraks","torak" }) );
  SetLong(
    "Well, huh, there you go. He does have a gut. Rather girthy, too. Perhaps he's pregnant?"
    );
  SetTouch("It touches you back!");
  SetSmell("Smells like molasses and whiskey.");
}


