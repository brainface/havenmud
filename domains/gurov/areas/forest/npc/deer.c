#include <lib.h>
inherit LIB_NPC;

static void create(){
    ::create();
    SetShort("a white-tailed northern deer");
    SetId( ({ "deer", "gurov_animal" }) );
    SetAdjectives( ({ "white", "tailed", "northern" }) );
    SetLong("This is a plain white tailed northern deer.");
    SetRace("deer");
    SetClass("animal");
    SetLevel(6);
    SetWander(1);
    SetLimit(8);
    SetGender("male");
    SetKeyName("deer");
}
