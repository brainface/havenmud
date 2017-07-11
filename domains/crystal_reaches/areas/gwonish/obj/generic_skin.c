#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("ruined pelt");
  SetDamagePoints(1);
  SetShort("a ruined pelt");
  SetLong("The pelt has deteriorated to a point of near worthlessness.");
  SetId( ({"pelt", "skin"}) );
  SetAdjectives( ({"ruined"}) );
  SetValue(1);
  SetMass(1);
  SetVendorType(VT_FUR);
 }
