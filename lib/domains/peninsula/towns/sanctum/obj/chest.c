#include <lib.h>
#include <std.h>
inherit LIB_STORAGE;

static void create() {
object cash = new(LIB_PILE);
  storage::create();
  cash->SetPile("imperials", 50000);
  cash->eventMove(this_object());
  SetKeyName("chest");
  SetId( ({ "chest", "box", "tylus_storage" }) );
  SetShort("a large wooden chest");
  SetAdjectives( ({ "large", "wooden" }) );
  SetLocked(1);
  SetClosed(1);
  SetCanLock(1);
  SetLockStrength(600);
  SetMaxCarry(1000000);
  SetInventory( ([
    STD_LIGHT "torch" : 2,
    
    ]) );
  SetLong("This large wooden box holds the goods that Tylus has "
          "for sale.  It looks durable.");
  SetPreventGet("The box is firmly nailed to the floor.");
}
