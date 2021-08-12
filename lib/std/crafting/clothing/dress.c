#include <lib.h>
#include <std.h>
#include <armour_types.h>

inherit STD_CRAFTING "clothing/include/clothing";

string GarmentName = "dress";

/*
void SetCraftResult() {
  clothing::SetCraftResult();
  }*/

static void create() {
  SetCraftName("dress");
  clothing::create();
  SetArmourType(A_BODY_ARMOUR);
  SetMass(20);
}
