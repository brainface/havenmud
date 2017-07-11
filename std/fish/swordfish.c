#include <lib.h>
#include <dirs.h>
#include <std.h>
#include <damage_types.h>

inherit LIB_FISH;

void BiteMe(object who);

static void create() {
  ::create();
  SetKeyName("swordfish");
  SetShort("a swordfish");
  SetFight(80);
  SetFood(STD_FISH "swordfish_food");
  SetMass(350);
}

int eventCatch(object who, object pole) { 
    call_out((: BiteMe, who :), 0);
    return 1;
}

void BiteMe(object who) {
    who->eventPrint("The swordfish impales you before it dies!");
    environment(who)->eventPrint("The swordfish impales " + (string)who->GetName() +
                                 " before it dies!", who);
    who->eventReceiveDamage(this_object(), PIERCE, random(75), 0,
                            (string)who->GetRandomLimb("torso"));
}
