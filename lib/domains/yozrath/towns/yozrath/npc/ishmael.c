/*  A moron of a vendor */
/*  cp'd and edited for a time for the havenwood. */
#include <vendor_types.h>
#include <lib.h>
#include "../yozrath.h"
inherit LIB_VENDOR;

static void create() {
  vendor::create();
  SetKeyName("Ishmael");
  SetVendorType(VT_ALL);
  SetShort("Ishmael the Fool");
  SetLong("Ishmael is a local of note. His business practices get him into "
          "trouble with many of Kailie's merchants, as he has no business "
          "sense at all.");
  SetRace("human");
  SetBaseLanguage("Padashi");
  SetClass("fighter");
  SetGender("male");
  SetId( ({ "merchant", "ishmael" }) );
  SetAdjectives( ({ "fool" }) );
  SetLocalCurrency("dinar");
  SetLevel(1);
  SetMorality(100);
  SetSkill("bargaining", 1, 4);
  SetStorageRoom(YOZRATH_ROOM "_shop");
  SetInventory( ([
    YOZRATH_OBJ "thobe" : "wear thobe",
  ]) );
  SetMaxSingleItem(50);
  SetMaxItems(200);
  SetLimit(1);
 }
