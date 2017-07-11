#include <lib.h>
#include <dirs.h>
#include <std.h>
#include <damage_types.h>

inherit LIB_FISH;

void BiteMe(object who);

static void create() {
    fish::create();
    SetKeyName("bonnethead shark");
    SetId( ({ "shark", "bonnethead shark" }) );
    SetShort("a bonnethead shark");
    SetMass(150); 
    SetFight(40);
    SetFood(STD_FISH "bonnethead_food");
}

int eventCatch(object who, object pole) { 
    call_out((: BiteMe, who :), 0);
    return 1;
}

void BiteMe(object who) {
    who->eventPrint("The shark bites you before it dies!");
    environment(who)->eventPrint("The shark bites " + (string)who->GetName() +
                                 " before it dies!", who);
    who->eventReceiveDamage(this_object(), PIERCE, random(50), 0,
                            (string)who->GetRandomLimb("right hand"));
}
