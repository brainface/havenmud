/* Mahkefel 2017
 * Crafting table thingy for making fabric
 * 
 */
#include <lib.h>

inherit LIB_STORAGE;


static void create() {
  storage::create();
  SetShort("a wooden loom");
  SetKeyName("loom");
  SetId( ({"loom" }) );
  SetAdjectives( ({ "wooden" }) );
  SetLong(
    "A large wooden square loom stands here."
  );
  SetMass(5000);

  SetMaxCarry(5000); // meh put a lot in there.
  SetPreventPut("The loom can't really hold anything, but yarn could be <attach>ed");
  SetPreventGet("The loom refuses to budge.");
  SetDamagePoints(5000);
  SetCanClose(0);
  SetClosed(0);
  SetCanLock(0);
  SetLocked(0);
}

indirect_attach_obj_to_obj() {
  return 1;
}

direct_weave_str_with_obj() {
  return 1;
}
