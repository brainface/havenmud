//
// filename: scroll
// Thoin@Haven
//
//  dissolve lock scroll

#include <lib.h>
inherit LIB_SCROLL;

static void create() {
  scroll::create();
  SetSpell("dissolve lock");
}
