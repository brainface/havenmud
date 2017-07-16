
// Snail
// Laoise
// May 2001

#include <lib.h>
#include <domains.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("snail");
    SetId("snail");
    SetAdjectives("white-shelled", "white");
    SetShort("a white-shelled snail");
    SetLong(
    "This snail drags its white shell with it where ever it goes, leaving "
    "a wet trail of sticky slime behind it as it squishes along. The snail "
    "looks distinctly like a grey slug, with eyes on stalks coming from top of "
    "its head which wave around, letting it see to all sides. The snail "
    "ripples and undulates, pushing itself along the rocks of the cave. "
    );
    SetLevel(2);
    SetRace("slug", "snail");
    SetClass("fighter");
    SetEncounter(0);
    SetMorality(0);
    SetWander(1);
    SetWanderSpeed(10);
    SetAction(5, ({ "The snail squishes slowly across the ground.",
    "The snail waves its eye stalks around in the air, looking for "
    "danger.", }) );
}

varargs int eventDie(object agent)
{
    object drink = new(AVERATH_AREAS "cave/obj/"+"snail_juice.c");
    drink->eventMove(this_object());
    return ::eventDie(agent);
}
