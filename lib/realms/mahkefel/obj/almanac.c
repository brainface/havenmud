#include <lib.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("almanac Of Prices of Merchants of Kaille");
  SetShort("a worn out book with many pages missing");
  SetId(({ "almanac", "book", "almanac of prices","almanac of prices of merchants of kaille" }));
  SetAdjectives( ({ "golden" }) );
  SetLong(
		"This book's spine proudly reads 'An Almanac of the Goods of "
		"Merchants of Kaille'. The cover shows a simple map of Khallie "
		"surrounded by drawings of various clothing and tools. The ink "
    "has ran from the effects of humidity and many handprints, and "
		"is now blurry and hard to read. The back cover is caved in, "
		"as if many pages have been ripped out."
  );
  SetRead("default", 
					"Huram's General Store of Keryth provides the following wares:
sensible winter coats.......960 senones
stylish black pants.........480 senones
leather gloves (per pair)...540 senones
wool blankets................10 senones
"
    "The remaining pages have been torn out, or are illegible from "
    "the effects of humidity and age."
  );

}

