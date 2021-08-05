/* Mahkefel 2017
 * Crafting table thingy for making fabric
 * 
 */
#include <lib.h>

inherit LIB_STORAGE;


static void create() {
  storage::create();
  SetShort("a spinning wheel");
  SetKeyName("wheel");
  SetId( ({"wheel" }) );
  SetAdjectives( ({ "spinning" }) );
  SetLong(
    "A large wooden spinning wheel stands here."
  );
  SetMass(5000);

  SetMaxCarry(5000); // meh put a lot in there.
  SetPreventPut("The spinning wheel can't really hold anything, but fiber could be <attach>ed. (Cotton, hemp, flax, or mithril.)");
  SetPreventGet("The spinning wheel refuses to budge.");
  SetDamagePoints(5000);
  SetCanClose(0);
  SetClosed(0);
  SetCanLock(0);
  SetLocked(0);
}

int indirect_attach_obj_to_obj() {
  return 1;
}

int direct_spin_str_with_obj() {
  return 1;
}

// override inventory
mixed CanPutInto(object who, object item) {
  who->eventPrint("You can't put things into a spinning wheel. Try <attach>ing textile plants.");
}
