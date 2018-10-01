#include <lib.h>
#include "haven.h"
inherit LIB_SENTIENT;

static void create() {
  ::create();
  SetKeyName("char");
  SetShort("TestChar");
  SetId( ({ "guy", "char" }) );
  SetAdjectives( ({ "former" }) );
  SetLong("Not much to see, save that stuff below.");
  SetRace("elf");
  SetGender("male");
  SetClass("cavalier");
  SetLevel(48);
  SetTown("Haven");
  SetReligion("Kylin");
  SetMorality(1400);
  SetInventory( ([ "/realms/atrus/std/armour/test2" : "wear all"
   ]) );
  SetAction(5, ({
       }) );
  }
