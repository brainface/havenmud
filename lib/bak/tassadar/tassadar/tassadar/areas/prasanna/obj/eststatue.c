#include <lib.h>

inherit LIB_ITEM;

static void create() {

  item::create();
  SetKeyName("statue");
  SetShort("a marble statue");
  SetId("statue");
  SetAdjectives( ({
    "marble", "flawless",
    "centerpiece", "handsome" 
    }) );
  SetLong("This statue is the centerpiece of the estate's garden. It "
          "depicts in flawless marble a handsome young man with sharp "
          "features, gazing towards the sky. A single inscription reading "
          "'Beloved Son' graces the base of the statue...identifying the "
          "subject as the son of Maeralin.");
  SetPreventGet("The statue is far too heavy to move.");
  }
