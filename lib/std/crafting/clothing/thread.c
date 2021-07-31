#include <lib.h>
#include <std.h>
#include <vendor_types.h>
inherit STD_CRAFTING "clothing/include/craftable";
void SetCraftResult() {
  string adj = GetCraftAdj();
  SetShort("a spool of " + adj + " " + CraftSources[0] + " thread");
  SetLong("This tightly wound spool of " + CraftSources[0] +" is clearly of " + adj + " quality.");
  craftable::SetCraftResult();
}

static void create() {
  ::create();
  SetKeyName("thread");
  SetVendorType(VT_CLOTHING);
  SetMass(5);
  SetId( ({ "thread" }) );
  SetProperty("craft_thread",1);
}

direct_attach_obj_to_obj() {
  return 1; 
}

mixed indirect_sew_str_from_obj_with_obj() {
  return 1;
}
