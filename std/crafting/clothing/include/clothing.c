#include <lib.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>

inherit "/std/crafting/clothing/include/craftable";
inherit LIB_ARMOUR;

string CraftPattern;
int CraftSize;
int CraftDamagePoints = 100;

string SetCraftPattern(string pattern) {return CraftPattern = pattern; }
string GetCraftPattern() {return CraftPattern;}
int SetCraftSize(int size) {return CraftSize = size;}

mapping Patterns = ([
	"checked" : ({1, "checkerboard"}),
	"chevron" : ({25, "alternating chevron"}),
	"fleur-de-lis" : ({50, "fleur-de-lis"}),
	"brocade" : ({100, "detailed floral"}),
	"chinoiserie" : ({200, "detailed scenic"}),
]);
	
void SetCraftResult() {
  ::SetCraftResult();
  SetCraftPattern( CraftPattern );  
  SetSize(CraftSize);
  SetDamagePoints(CraftDamagePoints);
}

static void create() {
  armour::create();
  craftable::create();
  SetId("craftything");
  SetShort("craftything");
  SetKeyName("craftything");
  
  SetArmourType(A_SOCK);
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_CLOTHING);
  SetMass(5);

  call_out( (: SetCraftResult :), 0);

  AddSave( ({  "CraftDamagePoints", "CraftPattern", "CraftSize" }) );
}

