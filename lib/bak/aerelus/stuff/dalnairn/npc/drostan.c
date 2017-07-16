// Dalnairn
// Aerelus

#include <lib.h>
#include "../dalnairn.h"
#include <vendor_types.h>
inherit LIB_OLD_VENDOR;

static void create() {
  ::create();
  SetKeyName("drostan");
  SetId( ({ "drostan", "smith", "dalnairn_people" }) );
  SetShort("Drostan the Smith");
  SetLong(
  "Drostan is an extremely strong Duergar. Years of bashing metal "
  "with his hammer has provided him with huge bulging muscles that rival "
  "that of even most of the city guards. He is an impatient man, but always "
  "has time to spare on potential customers."
  );
  SetFriends("dalnairn_people");  
  SetRace("dwarf");
  SetGender("male");
  SetClass("merchant");
  SetLevel(20);
  SetReligion("Soirin");
  SetMorality(-80);
  SetCurrency("shards", random(200));
  SetInventory( ([
         DAL_OBJ + "pants": "wear pants",
         DAL_OBJ + "shirt" : "wield shirt",
         DAL_OBJ + "shoes" : "wear shoes",
  ]) );  
    
  SetSkill("bargaining", 100, 1);  
  SetVendorType(VT_WEAPON);
  SetLocalCurrency("shards");
  SetStorageRoom(DAL_ROOM "storage/forge");
  SetMaxSingleItem(5);
  SetMaxItems(150);
 }
