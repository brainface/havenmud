// Mahkefel 2010: smith for arcanith
#include <lib.h>
#include <vendor_types.h>
#include <domains.h>
#include "../ruins.h"

inherit LIB_VENDOR;

static void create() {
  vendor::create();
  SetKeyName("golem");
  SetId( ({ "servitor","golem" }) );
  SetShort("A repaired servitor golem");
  SetLong(
    "This strange humanoid device was found when the kobolds migrated "
    "to these ruins. Its body is a complex mass of smooth steel plates "
    "covering tiny whirring gears, powered by some ancient enchantment. "
    "Someone has painted a snout and whiskers on its metallic face."
  );
  SetRace("golem");
  SetGender("neuter");
  SetBaseLanguage("Koblich");
  SetTown("Arcanith");
  SetMorality(0);
  SetClass("merchant");
  SetLevel(20);
  AddCurrency("senones", random(100)+5);

  SetStorageRoom(ROOM "/storage/store_relic");
  SetLocalCurrency("senones");
  SetVendorType(VT_ALL);
  SetMaxItems(150);
  SetMaxSingleItem(20);

  // from original file
  SetLimit(1);
  SetAction(5, ({
    "!say Welcome to the storeroom of relics!",
    "!say Do you require armour?",
    "!say The customer should <ask golem to browse>.",
    "!emote polishes an old shield.",
    "!say Please do not damage anything.",
  }) );
}

