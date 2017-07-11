#include <lib.h>
#include <vendor_types.h>
#include "../path.h"
inherit LIB_VENDOR;

static void create() {
	::create();
	SetKeyName("bruce");
	SetStorageRoom(G_ROOM "shop_storage");
	SetMaxSingleItem(100);
        SetVendorType(VT_ALL);
	SetRace("dwarf");
	SetClass("merchant");
	SetLevel(20);
	SetMorality(500);
	SetShort("Bruce the Shopkeep");
	SetId( ({ "bruce", "shopkeep", "glim_wander" }) );
	SetAdjectives( ({ "shop", }) );
	SetLong(
	  "Bruce of Glimmerdin is the one permanent resident of the Great Hall. "
	  "His shop stands, small and barely profitable, in the Center of "
	  "the Hall."
	  );
	SetAction(6, ({
		"!speak You should <ask bruce to browse>",
		"!speak You could <ask bruce to sell> if you see something you like.",
		"!speak If you have something to sell, you could <ask bruce to buy> it!",
		"!speak I will not be undersold!",
		"!speak No reasonable offer refused!",
	}) );
  SetCombatAction(8, ({
  	"!yell Come quick, help help!",
  	"!yell I am under attack!",
  }) );
  SetLocalCurrency("nuggets");
  SetTown("Glimmerdin");
  SetMaxItems(1000);
  SetLimit(1);
}
