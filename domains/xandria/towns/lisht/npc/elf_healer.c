#include <lib.h>
inherit LIB_HEALER;

static void create() {
  ::create();
  SetKeyName("Joseph");
  SetShort("Joseph the Healer");
  SetId( ({ "healer", "joseph" }) );
  SetAdjectives( ({ }) );
  SetTown("Lisht");
  SetFees( ([
    "resurrect" : 25,
    "magic"     : 20,
    "stamina"   : 10,
    "health"    : 3,
    "restore"   : 5,
    ]) );
  SetLocalCurrency("deben");
  SetRace("elf");
  SetBaseLanguage("Alatherian");
  SetGender("male");
  SetClass("priest");
  SetLevel(2);
  SetLong("Joseph is always there to help when you're in need of restoration. "
          "He can \"resurrect\" you, \"restore <limb>\"s for you, \"heal\" "
          "either your <magic>, <health>, or <stamina>, or just talk to you. "
          "There is a slight fee for his services.");
}
