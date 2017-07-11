//Selket@Haven
//2006
#include <lib.h>
#include "../lisht.h"
inherit LIB_HEALER;

static void create() {
  ::create();
  SetKeyName("irenakhty");
  SetShort("Chief Physician Irenakhty");
  SetId( ({ "physician", "irenakhty", "healer" }) );
  SetRace("gnoll");
  SetGender("male");
  SetClass("priest");
  SetLevel(10);
  SetCurrency("deben", 30);
  SetMorality(-50);
  SetLong(
    "Irenakhty is a reknowned healer, who can cure wounds and restore "
    "both the limbs and bodies of the ailing. His starched shenti's pockets "
    "are filled with the gruesome tools of his trade, and his body is painted "
    "with arcane symbols that increase the efficacy of his healings.");
  SetReligion("Enniae");
  SetBaseLanguage("Rehshai");
  SetLocalCurrency("deben");
  SetFees( ([
    "resurrect" : 30,
    "stamina" : 3,
    "health" : 8,
    "restore" : 15,
  ]) );
  SetTown("Lisht");
  SetLimit(1);
  SetAction(10, ({
    "!speak My remedies have been proven effective thousands of times.",
    "!speak Come forth to me, and be healed by she who causes us to breathe.",
    "!emote looks over your limbs with glimmering eyes.",
  }) );
  SetInventory( ([
    LISHT_OBJ "shenti" : "wear shenti",
  ]) );
}
