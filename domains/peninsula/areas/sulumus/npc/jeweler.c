// Proximo@Via Imperialis
// 06/16/2003

#include <lib.h>
#include <std.h>
#include <vendor_types.h>
#include "../sulumus.h";

inherit LIB_VENDOR;

void TheyEnter();

static void create() {
  ::create();
  SetKeyName("raspina");
  SetId( ({ "raspina", "jeweler", "collector" }) );
  SetAdjectives( ({ "sulumus" }) );
  SetShort("Raspina the Sulumus Jeweler and Collector of Treasure");
  SetLong(
     "This old crone is an odd looking woman, frail yet wise, sitting very still and "
     "quietly. She seems to have a fond affection for herbal recipies, as she is "
     "occasionally seen stirring a mixture. She also seems to have a keen eye for "
     "quality in jewelery and other such treasures, for it is her business to know. "
  );
  SetRace("human"); SetBaseLanguage("Imperial");
  RemoveLanguage("Human");
  SetLanguage("Imperial", 100, 1);
  SetGender("female");
  SetClass("merchant");
  SetVendorType(VT_TREASURE);
  SetSkill("bargaining", 1, 1);
  SetInventory( ([
     S_OBJ + "dress" : "wear dress",
     STD_WEAPON + "club" : "wield club",
     S_OBJ + "necklace" : "wear necklace",
  ]) );
  SetSkill("blunt combat", 1, 3);
  SetLevel(12);
  SetMorality(-55);
  SetStorageRoom(S_ROOM "str_jew");
  SetLimit(1);
  SetLocalCurrency("imperials");
  SetEncounter( (: TheyEnter :) );
}

void TheyEnter() {
     eventForce("sit down");
}
