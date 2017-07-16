/* Mahkefel 2017
 * cotton poofs
 *
 */

#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("cotton");
  SetShort("a boll of cotton");
  SetId( ({ "boll","cotton" }) );
  SetAdjectives( ({"boll","of" }) );
  SetLong("A poofy cotton boll.");
  SetMass(5);
  SetValue(50);
  // it's not REALLY food but i assume farmers would buy/sell it.
  SetVendorType(VT_FOOD|VT_PLANT);
  SetMaterials( ({ "textile" }) );
  
  // allows it to be spun into thread.
  SetProperty("craft_fiber", 1);
}

direct_attach_obj_to_obj() {
  return 1;
}

