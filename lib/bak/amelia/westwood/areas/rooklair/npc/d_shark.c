#include <lib.h>
#include <dirs.h>
#include <damage_types.h>
#include "../rook.h"

inherit LIB_FISH;

void BiteMe(object who);

static void create() {
  fish::create();
  SetKeyName("dragon shark");
  SetId( ({ "shark", "dragon shark" }) );
  SetShort("a dragon shark");
  SetLong("This isnt really a dragon, just a fish that is large "
    "enough to be feared as much as one.");
  SetMass(300); 
  SetFight(40);
  SetFood(R_OBJ + "d_shark");
}

int eventCatch(object who, object pole) { 
    call_out((: BiteMe, who :), 0);
    return 1;
}

void BiteMe(object who) {
    who->eventPrint("The shark bites you before it dies!");
    environment(who)->eventPrint("The shark bites " + (string)who->GetName() +
                                 " before it dies!", who);
    who->eventReceiveDamage(this_object(), KNIFE, random(50), 0,
                            (string)who->GetRandomLimb("right hand"));
}
