#include <lib.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetShort("a bleh");
  SetClass("fighter");
  SetKeyName("bleh");
  SetGender("male");
  SetCurrency("imperials", 2);
  SetTown("Haven");
}
