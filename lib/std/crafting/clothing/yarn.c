#include <lib.h>
#include <vendor_types.h>
#include <std.h>
inherit STD_CRAFTING "clothing/include/craftable";

void SetCraftResult() {
  string adj = GetCraftAdj();

  if(!sizeof(CraftSources)) return;

  if (!CraftColors) {
    CraftColors = ({ "undyed"});
  }
 
  SetShort("a spool of " + CraftColors[0] + " " + CraftSources[0] + " yarn");
  SetLong("This tightly wound spool of thick " + CraftColors[0] + " " + 
    CraftSources[0] +" is clearly of " + adj + " quality.");
  craftable::SetCraftResult();
  SetId(GetId() + ({"spool"}));
}

static void create() {
  craftable::create();
  SetKeyName("yarn");
  SetVendorType(VT_CLOTHING);
  SetMass(5);
  SetId( ({ "yarn" }) );
  SetAdjectives( ({ }) );
  SetProperty("craft_yarn",1);
  AddSave( craftable::GetSave() );
}

direct_attach_obj_to_obj() {
  return 1; 
}

// for dyeing.
int direct_dip_obj_in_obj() {
  return 1;
}
