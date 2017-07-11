// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include <vendor_types.h>
#include "../karak.h"
inherit LIB_VENDOR;

static void create() {
  vendor::create();
  SetKeyName("tachmaran");
  SetId( ({ "tachmaran", "orc", "shopkeep", "keep", }) );
  SetAdjectives( ({ "shop" }) );
  SetShort("Tachmaran the shopkeep");
  SetLong(
    "Of average height for a female, this half-orc appears to be engaged in "
    "generalized commerce. Like others who have chosen to split their time "
    "between the axillary military and a profession, she can usually be "
    "found with the axe of the professional warrior, but is not, perhaps, "
    "as visciously adept as those of her race who train full-time."
  );
  SetRace("half-orc");
  SetClass("fighter");
  SetGender("female");
  SetLevel(50);
  SetVendorType(VT_ALL);
  SetMaxItems(400);
  SetMaxSingleItem(40);
  SetLocalCurrency("orcteef");
  SetInventory( ([
    KARAK_OBJ + "axe" : "wield axe",
  	]) );
  SetStorageRoom(KARAK_ROOM + "str_gen");
  SetReligion("Saahagoth", "Saahagoth");
  SetMorality(-250);
}
