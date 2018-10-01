#include <lib.h>
inherit LIB_HEALER;

static void create() {
  ::create();
  SetKeyName("ethelred");
  SetShort("Ethelred the Healer");
  SetId( ({ "healer", "ethelred" }) );
  SetAdjectives( ({ }) );
  SetTown("Averath");
  SetFees( ([
    "resurrect" : 100,
    "magic" : 10,
    "stamina" : 1,
    "health" : 3,
    "restore" : 50,
    ]) );
  SetLocalCurrency("ducats");
  SetRace("human");
  SetGender("male");
  SetClass("cleric");
  SetLevel(2);
  SetLong("Ethelred is always there to help when you're in need of restoration. "
          "He can \"resurrect\" you, \"restore <limb>\"s for you, \"heal\" "
          "either your <magic>, <health>, or <stamina>, or just talk to you. "
          "There is a slight fee for his services.");
}
