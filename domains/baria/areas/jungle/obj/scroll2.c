/*  temporal barrier scroll, duh. */

#include <lib.h>
inherit LIB_SCROLL;

static void create() {
  scroll::create();
  SetSpell("temporal barrier");
}
