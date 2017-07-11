#include <lib.h>
#include "../lisht.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("aaron");
  SetShort("a small elven boy");
  SetId( ({ "aaron", "boy", "elf" }) );
  SetAdjectives( ({ "small", "elven" }) );
  SetRace("elf");
  SetGender("male");
  SetBaseLanguage("Alatherian");
  SetClass("merchant");
  SetSkill("blunt combat", 1, 2);
  SetLevel(10);
  SetMorality(350);
  SetLong(
    "This small boy seems overawed by the wonders of the world, though "
    "even in his young age a trace of future cynicism can be found."
    );
  SetLimit(1);  
}