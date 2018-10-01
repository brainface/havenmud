// Summary: Chairs for the bank
// Creator: Angel Cazares - Rhakz
// For Baria
// Date: 10/17/98
//
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("chair");
  SetShort("a wooden chair");
  SetLong("This is a chair made out of wood for customers "
          "to sit down.");
  SetId( ({ "chair" }) );
  SetAdjectives( ({"wooden"}) );
  SetDamagePoints(1000);
  SetValue(1000);
  SetMass(1000);
  SetVendorType(VT_TREASURE);
  SetMaterials( ({ "natural" }) );
  SetRepairDifficulty(10);
  SetPreventGet(1);
}

