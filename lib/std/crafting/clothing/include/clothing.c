#include <lib.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <std.h>

inherit STD_CRAFTING "clothing/include/craftable";
inherit STD_CRAFTING "clothing/include/pattern";
inherit STD_CRAFTING "clothing/include/craftsize";
inherit LIB_ARMOUR;

int DamagePointsPerLevel = 20;

void SetCraftResult() {
  string adj = GetCraftAdj();
  string color, fabric;

  // not initialized yet go away
  if (sizeof(CraftSources) < 3) return;
  
  craftable::SetCraftResult();

  if (!CraftColors) {
    CraftColors = ({ "undyed", "undyed", "undyed" });
  }

  SetCraftColors( CraftColors );
  SetCraftPattern( CraftPattern );  
  SetCraftSize( CraftSize );
  SetSize(CraftSize);
  SetDamagePoints(DamagePointsPerLevel * GetLevel());

  // set the unique desc for this item.
  if (CraftColors[0] == CraftColors[1]) {
    color = CraftColors[0];
  } else {
    color = CraftColors[0] + " and " + CraftColors[1];
  }
  if (CraftSources[0] == CraftSources[1]) {
    fabric = CraftSources[0];
  } else {
    fabric = "mixed fabric";
  }

  SetShort(sprintf("a %s %s %s", color, fabric, CraftName));

  SetLong(sprintf("A %s woven from %s %s and %s %s fabric in a %s pattern, "
    "stitched together with %s %s thread. It is clearly of %s quality.",
    CraftName, CraftColors[0], CraftSources[0], CraftColors[1], CraftSources[1],
    CraftPattern, CraftColors[2], CraftSources[2], adj));

}

static void create() {
  armour::create();
  craftable::create();
  SetId( ({CraftName}) );
  SetShort(CraftName);
  SetKeyName(CraftName);
  
  SetArmourType(A_SOCK);
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_CLOTHING);
  SetMass(5);

  //call_out( (: SetCraftResult :), 0);

  AddSave( pattern::GetSave() + craftable::GetSave() + craftsize::GetSave() );
}
