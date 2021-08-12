#include <lib.h>
#include <std.h>
#include <armour_types.h>

inherit STD_CRAFTING "clothing/include/clothing";

string GarmentName = "scarf";

/*
void SetCraftResult() {
  clothing::SetCraftResult();
  }*/

static void create() {
  SetCraftName("scarf");
  clothing::create();
  SetArmourType(A_AMULET);
  SetMass(10);
}
