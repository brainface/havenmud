//Selket@Haven
//2006
#include <lib.h>
#include "../lisht.h"
inherit LIB_BARKEEP;

static void create() {
  barkeep::create();
  SetKeyName("Hathor");
  SetShort("Hathor, Merry Tender of The Blue Lotus Inn ");
  SetId( ({ "hathor", "tender", "bartender", "barkeep" }) );
  SetAdjectives( ({ "merry" }) );
  SetLong("Hathor is a slightly heavy-set gnoll. She loves to "
          "party and drink with her patrons almost as much as "
          "she likes to count the money her goods bring in. Her "
    "eyes set in her plump face move over the room like "
          "a hawk's, making sure nobody is getting more or less "
          "than they paid for.");
  SetRace("gnoll");
  SetGender("female");
  SetClass("merchant");
  SetLevel(7);
  SetMenuItems( ([
    "sweet beer"  : LISHT_OBJ + "sweetbeer",
    "honey cake"  : LISHT_OBJ + "honeycake",
  ]) );
  SetLocalCurrency("deben");
  SetMorality(-200);
  SetCurrency("deben", 200);
  SetBaseLanguage("Rehshai");
  SetInventory( ([
    LISHT_OBJ "ldress" : "wear dress",
    LISHT_OBJ "girtle" : "wear girtle",
  ]) );
}
