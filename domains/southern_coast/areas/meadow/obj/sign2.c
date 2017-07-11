/*  a road sign at the bay
    Kyla 10-16-97
*/
#include <lib.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName( "sign" );
  SetId( ({ "sign" }) );
  SetAdjectives( ({ "road", "small" }) );
  SetShort("a small road sign");
  SetLong("A small road sign with writing on it.");
  SetRead("default", "Caution! Wild Platypi!");
  SetPreventGet("You can't take the sign.");
  SetMaterials( ({ "wood" }) );
  }
