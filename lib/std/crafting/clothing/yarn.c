#include <lib.h>
#include <vendor_types.h>
#include <std.h>
inherit STD_CRAFTING "clothing/include/craftable";

void SetCraftResult() {
  string adj = GetCraftAdj();
  SetShort("a spool of " + adj + " " + CraftSources[0] + " yarn");
  SetLong("This tightly wound spool of thick " + CraftSources[0] +" is clearly of " + adj + " quality.");
  craftable::SetCraftResult();
}

static void create() {
  ::create();
  SetKeyName("yarn");
  SetVendorType(VT_CLOTHING);
  SetMass(5);
  SetId( ({ "yarn" }) );
  SetAdjectives( ({ }) );
  SetProperty("craft_yarn",1);
}

direct_attach_obj_to_obj() {
  return 1; 
}
