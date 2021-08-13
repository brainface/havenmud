#include <lib.h>
#include <std.h>
#include <vendor_types.h>
inherit STD_CRAFTING "clothing/include/craftable";

void SetCraftResult() {
  string adj = GetCraftAdj();

  if (!sizeof(CraftSources)) return;

  if (!CraftColors) {
    CraftColors = ({ "undyed" });
  }
  
  SetShort("a spool of " + CraftColors[0] + " " + CraftSources[0] + " thread");
  SetLong("This tightly wound spool of " + CraftColors[0] + " " + 
    CraftSources[0] +" is clearly of " + adj + " quality.");
  craftable::SetCraftResult();
  SetId(GetId() + ({"spool"}));
}

static void create() {
  craftable::create();
  SetKeyName("thread");
  SetVendorType(VT_CLOTHING);
  SetMass(5);
  SetId( ({ "thread" }) );
  SetProperty("craft_thread",1);
  AddSave( craftable::GetSave() );
  call_out( (: SetCraftResult :), 0);
}

direct_attach_obj_to_obj() {
  return 1; 
}

mixed indirect_sew_str_from_obj_with_obj() {
  return 1;
}

// for dyeing.
int direct_dip_obj_in_obj() {
  return 1;
}
