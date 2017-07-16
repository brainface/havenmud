#include <lib.h>
#include <damage_types.h>
#include "../underdark.h"

inherit LIB_FISH;

void BiteMe(object who);

static void create() {
    fish::create();
    SetKeyName("small kraken");
    SetId( ({ "kraken", "small kraken" }) );
    SetShort("a small Kraken");
    SetLong("A small squid like creature that lives in dark, fresh water.");
    SetMass(100); 
    SetFight(40);
    SetFood( U_OBJ + "small_krakenfood");
}

int eventCatch(object who, object pole) { 
    call_out((: BiteMe, who :), 0);
    return 1;
}

void BiteMe(object who) {
    who->eventPrint("The kraken bites you before it dies!");
    environment(who)->eventPrint("The kraken bites " + (string)who->GetName() +
                                 " before it dies!", who);
    who->eventReceiveDamage(this_object(), PIERCE, random(20), 0,
                            (string)who->GetRandomLimb("right hand"));
}
