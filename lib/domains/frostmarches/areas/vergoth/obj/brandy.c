#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
#include "../vergoth.h"

static void create() {
  meal::create();
  SetId( ({ "brandy","decanter" }) );
  SetKeyName("brandy");
  SetShort("a decanter of brandy");
  SetLong("This is a small decanter of fine brandy.  It is light brown in "
	"color and smells very old.  The decanter is made of a light gray "
	"crystal of some sort.");
  SetMealType(MEAL_DRINK|MEAL_ALCOHOL);
  SetStrength(50);
  SetMealMessages("You drink a sip of brandy.","$N drinks a sip of brandy.");
  SetEmptyName("decanter");
  SetEmptyShort("an empty decanter");
  SetEmptyLong("This is an empty decanter.  It is made of a light gray "
	"crystal and smells of old brandy.");
 }