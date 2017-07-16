// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include <vendor_types.h>
#include "../karak.h"
inherit LIB_VENDOR;

static void create() {
  vendor::create();
  SetKeyName("dannel");
  SetId( ({ "armourer", "shopkeeper", "dannel", "orc" }) );
  SetShort("Dannel, the Armourer");
  SetLong(
    "As with all half-orcs, at puberty Dannel was given the choice to join "
    "the orcish Hordes to learn another trade and train with the reserves. "
    "Like many of her half-orc breathren, Dannel is part of the support "
    "network for the town and the Hordes, since no full-breed orc would "
    "have the patience to engage in commerce on a daily basis. Dannel "
    "chose to work as an armourer, and spends half her day in her shop "
    "and the other half in training, rather than the full-time training of "
    "those of the Horde. Despite this diminshed martial focus, Dannel is "
    "still part orc, therefore a warrior born, and would make a memorable "
    "opponent."
  );
  SetRace("half-orc");
  SetClass("fighter");
  SetGender("male");
  SetLevel(50);
  SetReligion("Saahagoth", "Saahagoth");
  SetMorality(-400);
  SetLocalCurrency("orcteef");
  SetProperty("no bump", 1);
  SetInventory( ([
    KARAK_OBJ + "axe"   : "wield axe",
  ]) );
  SetVendorType(VT_ARMOUR);
  SetStorageRoom(KARAK_ROOM + "str_arm");
}
