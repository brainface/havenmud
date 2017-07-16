#include <lib.h>
#include <vendor_types.h>
#include "../rook.h"

inherit LIB_ITEM;
 
static void create() {
  item::create();
  SetKeyName("statuette");
  SetId( ({ "statuette" }) );
  SetShort("a small statuette");
  SetLong("This is a small dragon statuette.  It is made "
    "pure silver and is very ornate.  Small gems make up "
    "it's small eyes, and little ivory spikes are used "
    "to make its teeth.  The details of the dragon are "
    "very accurate.  The wings are detailed out as though "
    "the dragon were ready to lift it's body into the air.");
  SetAdjectives( ({"small","dragon","silver"}) );
  SetMass(25);
  SetValue(7500);
  SetMaterial("metal");
  SetVendorType(VT_TREASURE);
}
