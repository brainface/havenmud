#include <lib.h>
#include "../grymxoria.h"
inherit LIB_MAYOR;

static void create() {
  mayor::create();
  SetKeyName("gunthar");
  SetShort("Gunthar, the Warlord of Grymxoria");
  SetId( ({ "gunthar", "warlord", "nosferatu" }) );
  SetLong(
    "Gunthar is muscular and large of build. There is a look "
    "of cunning and strength in his eyes. The Warlord of "
    "Grymxoria is not only the Mayor of his town, but "
    "leads his people in battle against the lesser races."
  );
  SetRace("nosferatu");
  SetGender("male");
  SetClass("cavalier");
  SetLevel(35);
  SetTown("Grymxoria");
  SetMorality(-2000);
  SetLocalCurrency("bloodgems");
  SetTax(0);
  SetInventory(  ([
    G_OBJ + "nosf_lance" : "wield lance",
    G_OBJ + "nosf_sword" : "wield sword",
  ]) );
}

