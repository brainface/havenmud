//Selket@Haven
//2006
#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <size.h>
#include <vendor_types.h>
inherit LIB_STORAGE;
static void create() {
  ::create();
  SetKeyName("basket");
  SetId( ({ "basket", }) );
  SetAdjectives( ({ "small" }) );
  SetMaterials( ({ "natural" }) );
  SetShort("a small basket");
  SetLong("This is a small woven basket made for easy transport "
          "of items from one place to another.");
  SetMass(2);
  SetValue(10);
  SetCanClose(1);
  SetClosed(1);
  SetMaxCarry(50);
  
}
