
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
    SetAdjectives("brown", "hermit");
    SetShort("a brown hermit crab");
    SetLong(
    "This is a small brown shell, built just like one you would see on "
    "a snail, which is the living space for a hermit crab. The shy crab "
    "hides inside, occasionally poking its head and legs out to test the "
    "air. When it senses it is safe the hermit crab's legs emerge from "
    "its shell, it raises its shell up off the ground and skitters along "
    "the rocks."
    );
    SetLevel(3);
    SetRace("arachnid", "hermit crab");
    SetClass("fighter");
    SetEncounter(0);
    SetMorality(0);
    SetWander(1);
    SetWanderSpeed(10);
    SetAction(5, ({ "The hermit crab pokes its legs out.",
    "The hermit crab skitters along the rock." }) );
}
