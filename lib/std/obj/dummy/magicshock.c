#include <lib.h>
inherit LIB_ITEM;

/* This is a dummy OBJ for a type of damage. */

static void create() {
  ::create();
  SetKeyName("magic shock");
  SetShort("magic shock");
}
