
// Hermit Crab
// Laoise
// May 2001

#include <lib.h>
#include <domains.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("hermit crab");
    SetId("crab");
    SetAdjectives("tan", "hermit");
    SetShort("a tan hermit crab");
    SetLong(
    "This is a small tan shell, built just like one you would see on "
    "a snail, which is the living space for a hermit crab. The shy crab "
    "hides inside, occasionally poking its head and legs out to test the "
    "air. When it senses it is safe the hermit crab emerges its legs out "
    "of the shell and skitters along the rocks."
    );
    SetLevel(4);
    SetRace("arachnid", "hermit crab");
    SetClass("fighter");
    SetEncounter(0);
    SetMorality(0);
    SetWander(1);
    SetWanderSpeed(10);
    SetAction(5, ({ "The hermit crab pokes its legs out.",
    "The hermit crab skitters along the rock." }) );
}
