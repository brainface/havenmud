#include <lib.h>
#include <std.h>
#include <armour_types.h>

inherit STD_CRAFTING "clothing/include/clothing";

string GarmentName = "tail wrap";

/*
void SetCraftResult() {
  clothing::SetCraftResult();
  }*/

static void create() {
  SetCraftName("tail wrap");
  clothing::create();

  SetId( GetId() + ({"wrap"}) );
  AddAdjective("tail");

  SetArmourType(A_TAIL);
  SetMass(5);
}
