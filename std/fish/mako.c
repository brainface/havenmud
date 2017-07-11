#include <lib.h>
#include <dirs.h>
#include <std.h>
#include <damage_types.h>

inherit LIB_FISH;

void BiteMe(object who);

static void create() {
    fish::create();
    SetKeyName("mako");
    SetId( ({ "mako", "shortfin mako" }) );
    SetShort("a shortfin mako");
    SetMass(250); 
    SetFight(60);
    SetFood(STD_FISH "mako_food");
}

int eventCatch(object who, object pole) { 
    call_out((: BiteMe, who :), 0);
    return 1;
}

void BiteMe(object who) {
    who->eventPrint("The mako bites you before it dies!");
    environment(who)->eventPrint("The mako bites " + (string)who->GetName() +
                                 " before it dies!", who);
    who->eventReceiveDamage(this_object(), PIERCE, random(50), 0,
                            (string)who->GetRandomLimb("right hand"));
}
