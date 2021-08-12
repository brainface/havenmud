#include <lib.h>
#include <std.h>
#include <armour_types.h>

inherit STD_CRAFTING "clothing/include/clothing";

string GarmentName = "shirt";

/*
void SetCraftResult() {
  clothing::SetCraftResult();
  }*/

static void create() {
  SetCraftName("shirt");
  clothing::create();
  SetArmourType(A_SHIRT);
  SetMass(15);
}
