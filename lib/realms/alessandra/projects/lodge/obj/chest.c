#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include "../lodge.h"
inherit LIB_STORAGE;
static void create() {
object cash = new(LIB_PILE);  
  storage::create();
  cash->SetPile("imperials", 17000);
  cash->eventMove(this_object());
  SetKeyName("chest");
  SetId( ({"chest"}) );
  SetShort("a large chest");
  SetLong("This chest is big and hollow, probably one of the "
     "only things neatly kept. It looks like it could hold "
     "a small treasure.");
  SetAdjectives( ({"large"}) );
  SetMass(2000000);
  SetValue(0);
  SetMaterial( ({"wood"}) );
  SetDamagePoints(1000);
}
