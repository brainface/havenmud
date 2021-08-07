#include <lib.h>
#include <std.h>
#include <vendor_types.h>
#include <armour_types.h>
#include <armour_class.h>

inherit STD_CRAFTING "clothing/include/clothing";

void SetCraftResult() {
  string adj = GetCraftAdj();
  
  // call the lib function that does generic shit
  clothing::SetCraftResult();
  
  // set the unique desc for this item.
  // made from single type of fabric
  if (CraftSources[0] == CraftSources[1]) {
  	SetShort(sprintf("a %s %s %s sock", adj, CraftPattern, CraftSources[0] ));
  	SetLong(sprintf("A sock woven from %s fabric in a %s pattern, stitched "
  		"together with %s thread. It is clearly of %s quality.",
  		CraftSources[0], CraftPattern, CraftSources[2], adj));
  } else {
    SetShort(sprintf("a %s %s %s and %s sock",
    	adj,CraftPattern,CraftSources[0],CraftSources[1]));
    SetLong(sprintf("A sock woven from %s and %s fabric in a %s pattern, "
    	"stitched together with %s thread. It is clearly of %s quality.",
    	CraftSources[0],CraftSources[1],Patterns[CraftPattern],CraftSources[2]));
  }
}


static void create() {
  clothing::create();
  SetId("sock");
  SetShort("sock");
  SetKeyName("sock");
  SetArmourType(A_SOCK);
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_CLOTHING);
  SetMass(5);
  SetId( ({ "sock" }) );  

  //AddSave( /*pattern::GetSave() + craftable::GetSave() + craftsize::GetSave() */);
}
