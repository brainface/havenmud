#include <lib.h>
#include <std.h>
#include <vendor_types.h>
inherit STD_CRAFTING "clothing/include/craftable";
inherit STD_CRAFTING "clothing/include/pattern";

void SetCraftResult() {
  string adj = GetCraftAdj();

  // made from single type of fabric
  if (CraftSources[0] == CraftSources[1]) {
    SetShort("a "+adj+" "+CraftPattern +" bolt of "+ CraftSources[0] + " fabric");
    SetLong("A rolled up bolt of fabric made of " + CraftSources[0] + " yarn " +
  	 "arrayed in a " + CraftPattern + " pattern. It is clearly of " + adj + " quality.");
  } else {
    SetShort("a "+adj+" "+CraftPattern +" bolt of "+ CraftSources[0] + " and " + CraftSources[1] + " fabric");  	  
    SetLong("A rolled up bolt of fabric made of " + CraftSources[0] + " yarn and " + CraftSources[1] + " yarn " +
  	 "arrayed in a " + CraftPattern + " pattern. It is clearly of " + adj + " quality.");
  }

  craftable::SetCraftResult();
}

static void create() {
  craftable::create();
  pattern::create();
  SetKeyName("fabric");
  SetVendorType(VT_CLOTHING);
  SetMass(5);
  SetId( ({ "fabric", "bolt" }) );
  SetProperty( "craft_fabric", 1 );
}

mixed direct_sew_str_from_obj_with_obj() {
  return 1;
}
