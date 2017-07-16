//Alex@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../area.h"
inherit LIB_NPC;

static void create(){
  npc::create();
  SetKeyName("mlima");
  SetShort("Mlima the Provider");
  SetId( ({ "mlima", "hunter", "father", "provider" }) );
  SetRace("human");
  SetBaseLanguage("Barian");
  SetLimit(1);
  SetClass("fighter");
  SetLevel(30);
  SetLong(
    "Mlima is a stern hunter who says little about his knowledge of "
    "the jungle. Ever since becoming a husband and father, he has had "
    "little time to express himself. Instead, he spends most time outside "
    "the hut, foraging for his family.");
  SetGender("male");
  SetCurrency("chits", 15 + random(15));
  SetInventory( ([
    AREA_OBJ "loincloth" : "wear loincloth",
    AREA_OBJ "leafsandals" : "wear sandals",
    AREA_OBJ "club" : "wield club",
  ]) );
  SetAction(10, ({
    "!speak Yes dear...",
    "Mlima tries to look stern.",
    "Mlima stares at the floor to avoid his wife's gaze.",
  }) );
  SetMorality(50);
}

