
// Oceanid
// Laoise
// May 2001

#include <lib.h>
#include <domains.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("oceanid");
    SetId("oceanid");
    SetAdjectives("oceanid", "petite");
    SetShort("a petite oceanid");
    SetLong(
    "This petite female appears to have solidified directly from light "
    "blue ocean water, which exists throughout these caves. Being made "
    "entirely from the environment in which she dwells, this mystical "
    "creature appears to be a type of nymph, specifically an oceanid. "
    "Nymphs dwell within different parts of nature, sharing their "
    "livelihood with that which they live in and protect. This water "
    "nymph shares her soul with the ocean from which she comes, being "
    "able to exit and reenter her element at will."
    );
    SetLevel(5);
    SetRace("nymph", "oceanid");
    SetClass("fighter");
    SetGender("female");
    SetEncounter(0);
    SetMorality(300);
    SetWander(1);
    SetWanderSpeed(10);
    SetProperty("cave_wander", 1);
    AddCurrency("ducats", random(3));
    SetInventory( ([
    AVERATH_AREAS "cave/obj/"+"water_breastplate.c" : "wear breastplate",
    AVERATH_AREAS "cave/obj/"+"water_circlet.c" : "wear circlet",
    AVERATH_AREAS "cave/obj/"+"water_sword.c" : "wield sword",
    ]) );
}
