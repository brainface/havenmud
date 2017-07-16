#include <lib.h>
#include <meal_types.h>
#include "../rome.h"
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("fountain");
  SetShort("a large marble fountain");
  SetId( ({ "fountain" }) );
  SetAdjectives( ({ "large", "marble" }) );
  SetPortions(-1);
  SetPreventGet("The fountain is much too large to pick up.");
  SetLong("This marvel of modern construction is a feat to behold. "
          "A large basin lies at the bottom of the fountain, filled "
          "with sparkingly clean water. Arranged around the fountain "
          "are four statues representing the four main religions of the Empire, "
          "each with the water flowing in a unique way to fill the "
          "marble basin.");
  SetStrength(100);
  SetMealType(MEAL_DRINK);
  SetMealMessages( ({
    "$N drink from the fountain.",
    "$N drinks from the fountain.",
    }) );
  SetItems( ([
    ({ "statue", "statues" }) : "Did you mean the Kylin statue, "
          "Soirin statue, Eclat statue, or Thorian statue?",
    ({ "kylin statue" }) : "The Kylin statue has water flowing "
          "from the mouth of a dragon in to the cups of a balance. "
          "From there the water flows into the basin.",
    ({ "soirin statue" }) : "The Soirin statue has water flowing "
          "from the tip of a dagger into a golden chalice.  From "
          "there the water flows into the basin.",
    ({ "thorian statue" }) : "The Thorian statue has water flowing "
          "from the mouth of a bloated corpse (made of stone!) into "
          "something that looks like a flower garden.  From there, "
          "the water drains into the basin.",
    ({ "eclat statue" }) : "The Eclat statue has two river nymphs "
         "holding large ceramic water buckets from which water "
         "flows directly into the basin.",
    ]) );
}
