#include <lib.h> 
#include "prasanna.h"
inherit LIB_ITEM;

static void create() {

  item::create();
  SetKeyName("dragon");
  SetShort("a topiary of a dragon");
  SetId("dragon","topiary");
  SetLong("This sculptured holly bush is shaped like a dragon. "
          "The skin is made from overlapping leaves that form what "
          "look like scales. Its sitting form is holding a gazing "
          "globe in its short fore claws that reflects the world "
          "around it. The tail wraps around the base, making it look "
          "like a border to the soil. Its head is held high and "
          "majestic. The wings are fanned out to shroud the area "
          "around it in a deep shadow.");
  SetPreventGet("The roots are planted firmly in the ground."); 
  }
