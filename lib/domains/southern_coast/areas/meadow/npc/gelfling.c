// One of those cheesy salesmans that sell you junk
// For Platypus Bay
// Urien@Haven 06JUL08

#include <lib.h>
#include "../meadow.h"
inherit LIB_BARKEEP;

static void create() {
 ::create();
 SetKeyName("shopkeep");
 SetShort("a gelfling shopkeep");
 SetId( ({ "gelfling", "shopkeep", "shopkeeper" }) );
 SetAdjectives( ({ "young", "salesman"}) );
 SetRace("gelfling");
 SetBaseLanguage("Eltherian");
 SetGender("male");
 SetClass("merchant");
 SetLimit(1);
 SetLevel(5);
 SetLong(
    "This young gelfling salesman has a really bright smile. His shiny black hair "
    "covers his pointed ears on the side of his head. Black eyebrows stand out above his "
    "hazel eyes and small freckles litter his cheeks which compliment his oval "
    "face."
  );
 SetAction(5, ({
    "!say Come one, come all. Lovely bait for sale",
    "!say Shrimp? Ham? Fishing poles? I have it all!",
    "!say The Shrimp and Ham are bait for fishing",
    "!wink",
    "!smile",
    "!beam"
  }) );
 SetMenuItems( ([
    "shrimp"   : MEADOW_OBJ  "shrimp",
    "ham"      : MEADOW_OBJ  "ham",
    "old pole" : MEADOW_OBJ  "oldpole",
    ]) );
 SetLocalCurrency("imperials");
 SetCurrency("imperials",10);
 }

