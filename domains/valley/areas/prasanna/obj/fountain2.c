#include <lib.h> 
#include <meal_types.h>
#include "prasanna.h"

inherit LIB_MEAL;

static void create() {
        meal::create();
        SetKeyName("fountain");
  SetPortions(-1);
        SetShort("a fountain of a mermaid");
        SetId("mermaid","fountain");
        SetMealType (MEAL_DRINK);        
        SetLong("This fountain is carved from a rose-gray granite. The "
                "mermaid balances neatly on her tail, her expression one "
                "of sweet joy. Flecks of mica sparkle in her "
                "seaweed-and-shell twined hair. The large urn perched on "
                "her shoulder must have provided the water for the bath, "
                "drawn by some unknown mechanism from a now-dry source.");           
        SetPreventGet("The fountain is far too heavy to move."); 
        SetEmptyItem(PR_OBJ "/fountain2");
        SetStrength(0);
        SetMealMessages("The fountain is empty.","$N tries to drink from an empty fountain.");
}

