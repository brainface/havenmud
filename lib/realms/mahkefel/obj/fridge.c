#include <lib.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>

inherit LIB_STORAGE;

int pour(string args);

 static void create() {
  ::create();
  SetKeyName("minifridge");
  SetId( ({ "minifridge","fridge" }) );
  SetShort("a minifridge full of vodka");
  SetLong("This minifridge is full of discount vodka. So "
    "full that the door is barely sealed when shut. It "
    "gives off a comforting hum and occasionally a teeth "
    "rattling metal scraping noise as some mechanism "
    "barely continues to operate.");
  SetMass(1000);
  SetMaterials( ({ "metal" }) );
  SetValue(100);
  SetCanClose(1);
  SetClosed(1);
  SetMaxCarry(5000);
  //SetVendorType(VT_CLOTHING);
  SetDamagePoints(700);
  SetInventory( ([
    "/realms/mahkefel/obj/vodka" : 10,
    "/realms/mahkefel/obj/frozen": 6,
    "/realms/alessandra/misc/ancient": 1,
  ]));
}

