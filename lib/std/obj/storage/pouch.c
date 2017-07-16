//Artanis@Haven
//remade pouch to include sizes and a few fixes

#include <lib.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_STORAGE;

static void create() 
{
  ::create();
  SetKeyName("pouch");
  SetId( ({ "pouch" }) );
  SetAdjectives( ({ "small","leather" }) );
  SetShort("a small leather pouch");
  SetLong("This small pouch is made of soft leather.  "
          "Leather drawstrings allow it to be closed.");
  SetMass(1);
  SetMaterials( ({ "leather" }) );
  SetValue(30);
  SetCanClose(1);
  SetClosed(1);
  SetMaxCarry(200);
}
