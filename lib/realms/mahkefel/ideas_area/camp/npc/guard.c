#include <lib.h>
#include <std.h>
#include "../camp.h"

inherit LIB_SENTIENT;

static void create() {
    ::create();

    switch(random(2)){
      case 0:
        SetRace("goden");
        SetClass("viking");
        SetShort("a haggard goden sailor");
        SetId( ({"goden","uninfected","sailor" }) );
        SetKeyName("sailor");
        SetAdjectives(({"haggard","goden"}));
        SetInventory( ([
          STD_HACK "battle_axe" : "wield axe",
          STD_CLOTHING "coat" : "wear coat",  //TODO:PARKA
        ]) );
        SetLong(
          "A fine layer of ice covers the garments of this ragged "
          "goden. His movements are sluggish and pained, a constant "
          "fight against the freezing ice assaulting him. His tail drags "
          "along sadly behind him, encrusted with its own weight of snow."
        );
        break;
      case 1:
        SetRace("human");
        SetClass("sailor");
        SetShort("a haggard human sailor");
        SetId( ({"sailor","human","uninfected" }) );
        SetKeyName("sailor");
        SetAdjectives(({"haggard","human"}) );
        SetInventory( ([
          STD_SLASH "longsword" : "wield sword",
          STD_CLOTHING "coat" : "wear coat", //TODO:PARKA
        ]) );
        SetLong(
          "This sailor looks like he wishes to be anywhere else. His boots "
          "are nearly frozen solid with ice, turning his steps into something "
          "more like determined drags. Flurried snow coats his beard, and he "
          "holds his eyes squinted nearly shut against the constant wind."
        );
        SetBaseLanguage("Gurovian");
        break;
    }

    SetGender("male");
    SetLevel(15);
    SetFriends("uninfected");

    //miscellaneous
    SetAction(3, ({
      "!say there's... something out there.",
      "!say It's friggin' cold out here.",
      "!say We can't stay here forever.",
      "!say If we're lucky, maybe we'll just freeze to death.",
      "!say something's wrong with the dogs.",
      "!emote tries to wipe snow off his face.",
      "!emote shivers.",
      "!emote shivers.",
      "!emote rubs his hands together.",
    }) );
    SetWanderSpeed(30);
    SetLimit(10);
}



