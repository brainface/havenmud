#include <lib.h>
#include "../lodge.h"
inherit LIB_KEY;
inherit LIB_ITEM;
static void create() {
  key::create();
  item::create();
  SetKeyName("ice key");
  SetId( ({ "key" }) );
  SetKeyID("ice_key");
  SetShort("an ice key");
  SetLong(
    "This key is made of pure ice. It is almost chillingly painful to hold "
     "in ones hand. Its shape is contorted, making it fit only for a certain "
    "lock. This key should be used fast, for it is melting rather quickly."
  );
  SetAdjectives( ({"ice"}) );
  SetMaterial( ({ "natural" }) );
  SetMass(1);
  SetValue(3);
  SetDamagePoints(20);
}
