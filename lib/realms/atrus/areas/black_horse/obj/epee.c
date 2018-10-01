/* A matching custom epee for the cane scabbard. */

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;
inherit LIB_STORAGE;

static void create() 
  {
  ::create();
  SetKeyName("epee");
  SetId( ({ "epee" }) );
  SetAdjectives( ({ "mithril", "thin" }) );
  SetShort("a thin mithril epee");
  SetLong("This light epee is incredibly sharp. The hilt is wrapped in leather "
          "with studs poking through it to offer a supreme grip, it would be "
          "difficult to disarm this weapon. The cross guard is made of two "
          "opposing ivy leaves constructed of mithril. The blade is very sharp "
          "with a point that could pierce demonhide.");
  SetProperty("magic", "This blade is not significantly magical.");
  SetProperty("history", "The history of this weapon traces it's roots back to "
              "a gnomish master smith named Reldegan Mandrake. His weapons "
              "were usually crafted to be enchanted by his brother Fizzle, but "
              "this particular blade was so perfectly made that Fizzle refused "
              "to touch it. This blade was specifically made for Maurice Anderman.");
  SetMass(25);
  SetValue(1500);
  SetVendorType(VT_WEAPON);
  SetClass(40);
  SetDamagePoints(1800);
  SetMaterial( ({ "mithril" }) );
  SetWarmth(0);
  SetRepairSkills( ([ "mithril working" : 100,
                      "leather working" : 25, ]) );
  SetRepairDifficulty(60);
  }

int eventDisarm(){
  return 0;
  }
