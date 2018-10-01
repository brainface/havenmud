/*  A wanted poster */
#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ITEM;
void ReadMe();

static void create() {
  item::create();
  SetKeyName("poster");
  SetPreventGet("It is nailed firmly to the wall.");
  SetMass(450);
  SetShort("a wanted poster");
  SetLong("This is a poster listing the names and crimes of all "
	  "people wanted in Grymxoria.  One could read it.");
  SetRead("default", "The poster lists no names right now." );
  }

