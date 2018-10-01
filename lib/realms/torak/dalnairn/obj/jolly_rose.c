//
// Dalnairn Total Recode
// Torak@Haven 2014 - 2017
// 

#include <lib.h>
#include <vendor_types.h>
#include <daemons.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("flag");
  SetMaterials( ({ "textile" }) );
  SetId( ({ "flag", "rose" }) );
  SetAdjectives( ({ "black", "rose", "jolly" }) );
  SetDamagePoints(100);
  SetMass(1);
  SetVendorType(VT_TREASURE);
  SetShort( "a black jolly rose flag" );
  SetLong( 
    "A white skull and saber crossed with thorned rose adorn the field of this black flag."
  );
  SetProperty(
    "history", 
      "This flag is the official Jolly Roger of the Dailnairn Dwarves. "
      "Combining the rose of soirin with the crossed saber and skull "
      "to honor their religion and strike terror into the prey.");
}
