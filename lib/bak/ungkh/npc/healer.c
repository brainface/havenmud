#include <lib.h>

inherit LIB_HEALER;

static void create() {
  healer::create();

  SetKeyName("Salvia");
  SetId( ({
    "salvia","healer","kobold"
    }) );
  SetShort("salvia, the healer");
  SetLong("Tall and healthy, this kobold prides herself on her "
          "health.  Her occupation is un-heard of in her race, making "
          "her one of a kind.  A aura of comfort that would sooth "
          "even the most savage mind surrounds her.");
  SetLevel(56);
  SetReligion("Kuthar");
  SetTown("Ungkh");
  SetRace("kobold");
  SetMorality(250);
  SetClass("cleric");
  SetLocalCurrency("skins");
  SetFees( ([
    "resurrect" : 100,
    "magic" : 10,
    "stamina" : 1,
    "health" : 3,
    "restore" : 50,
  ]) );
  SetGender("female");
  SetCurrency("skins",250 + random(175));

}
