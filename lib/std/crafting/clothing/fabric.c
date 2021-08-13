#include <lib.h>
#include <std.h>
#include <vendor_types.h>
inherit STD_CRAFTING "clothing/include/craftable";
inherit STD_CRAFTING "clothing/include/pattern";


void SetCraftResult() {
  string adj = GetCraftAdj();

  if ( !sizeof(CraftSources) ) return;

  if (!CraftColors) {
    CraftColors = ({ "undyed", "undyed"});
  }

  // made from single type of fabric
  if (CraftColors[0] == CraftColors[1]) {
    SetShort("a "+CraftPattern +" bolt of "+ CraftColors[0] + " fabric");
  } else {
    SetShort("a "+CraftPattern +" bolt of "+ CraftColors[0] + " and " 
      + CraftColors[1] + " fabric");  	  
  }

  SetLong("A rolled up bolt of fabric made of " + CraftColors[0] + " " 
    + CraftSources[0] + " yarn and " + CraftColors[1] + " " + 
    CraftSources[1] + " yarn " + "arrayed in a " + CraftPattern + 
    " pattern. It is clearly of " + adj + " quality.");

  craftable::SetCraftResult();
}

static void create() {
  //pattern::create();
  craftable::create();

  SetKeyName("fabric");
  SetVendorType(VT_CLOTHING);
  SetMass(5);
  SetId( ({ "fabric", "bolt" }) );
  SetProperty( "craft_fabric", 1 );
  AddSave( pattern::GetSave() + craftable::GetSave() );
}

mixed direct_sew_str_from_obj_with_obj() {
  return 1;
}
