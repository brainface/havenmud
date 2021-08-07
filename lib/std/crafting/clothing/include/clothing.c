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

int CraftDamagePoints = 100;

void SetCraftResult() {
  ::SetCraftResult();

  if (!CraftColors) {
    CraftColors = ({ "undyed", "undyed", "undyed" });
  }
  SetCraftColors( CraftColors );
  SetCraftPattern( CraftPattern );  
  SetCraftSize( CraftSize );
  SetSize(CraftSize);
  SetDamagePoints(CraftDamagePoints);
}

static void create() {
  armour::create();
  craftable::create();
  SetId("clothything");
  SetShort("clothything");
  SetKeyName("clothything");
  
  SetArmourType(A_SOCK);
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_CLOTHING);
  SetMass(5);

  call_out( (: SetCraftResult :), 0);

  AddSave( pattern::GetSave() + craftable::GetSave() + craftsize::GetSave() );
}

