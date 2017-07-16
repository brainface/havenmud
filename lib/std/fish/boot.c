

#include <lib.h>
#include <std.h>
inherit LIB_FISH;

static void create() {
  ::create();
  SetKeyName("boot");
  SetShort("an old boot");
  SetFight(10);
  SetFood(STD_FISH "boot_food");
  SetMass(30);
}

