//Selket@Haven
//2006
#include <lib.h>
#include "../lake.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("urchin");
  SetShort("a street urchin");
  SetId( ({ "urchin", "child" }) );
  SetAdjectives( ({ "street" }) );
  SetLong(
    "A filthy, naked little child. He seems almost wild. "
  );
  SetClass("fighter");
  SetLevel(4);
  SetGender("male");
  SetRace("gnoll");
  SetBaseLanguage("Rehshai");
  SetCurrency("deben",random(500));
  SetAction(6, ({
    "!giggle",
    "!whee",
  }) );
}
