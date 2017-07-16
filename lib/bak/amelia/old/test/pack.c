#include <lib.h>
#include <armour_types.h>

inherit "/realms/amelia/test/worn_storage.c";

static void create() 
{
  ::create();
  SetKeyName("backpack");
  SetId( ({ "backpack", "pack" }) );
  SetAdjectives( ({ "large", "canvas" }) );
    SetShort("a large canvas pack");
  SetLong("This pack straps onto one's back and allows a few weapons and "
    "pieces of armour to be held inside.");
  SetMass(30);
  SetValue(60);
  SetCanClose(1);
  SetClosed(1);
  SetMaxCarry(400);
  SetArmourType(A_CLOAK);
}

