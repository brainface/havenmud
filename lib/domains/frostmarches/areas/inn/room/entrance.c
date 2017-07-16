#include "../inn.h"
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("outside of the Morning Star Inn");
  SetClimate("arctic");
  SetLong("This is the entrance to the Morning Star Inn.  The building has "
          "strong oak walls and a second floor at the rear.  The one window "
          "has a grimy look, allowing only a little of the light from inside "
          "to escape.  There is a puddle of vomit on the ground and a sign "
          "above the door.");
  SetItems( ([
             ({ "sign above the door", "sign" }) : "The sign proclaims this "
                "building to be the Morning Star Inn.",
             ({ "puddle of vomit", "vomit puddle", "vomit", "puddle" }) :
                "The vomit is fresh and very fluid.  It appears to have "
                "pieces of bread in it.",
             ({ "pieces of bread", "piece of bread", "bread", "piece", 
                "pieces" }) :
                "Upon closer examination of the vomit and the pieces of "
                "bread, it immediately becomes obvious that vomit should "
                "not be looked at too closely.",
             ({ "entrance", "door", "oak planks", "planks",
                "reinforcing cross-sections", "cross-sections" }) :
                "The door leading into the Morning Star Inn is made of oak "
                "planks with reinforcing cross-sections and rests upon "
                "leather hinges.",
             ({ "leather hinges", "hinges", "hinge" }) :
                "The hinges are still uncracked and flexible.  They could "
                "probably see many years of use.",
             ({ "morning star inn", "inn" }) :
                "This is the Morning Star Inn, a good place to sleep or get "
                "drunk...or both.",
             ({ "building" }) :
                "This is a decent sized two story building.",
             ({ "morning inn" }) :
                "The name of this inn is 'Morning Star Inn', not "
                "'Morning Inn.'",
             ({ "star inn" }) :
                "The name of this inn is 'Morning Star Inn', not 'Star Inn.'",
             ({ "real estate", "estate" }) :
                "This is the land the Morning Star Inn was built on.",
             ({ "second floor", "floor" }) : 
                "The second floor of the Morning Star Inn looms high above.",
             ({ "rear" }) :
                "The rear of the Morning Star Inn has a second floor.",
             ({ "strong oak wall", "strong oak walls", "strong wall",
                "strong walls", "oak wall", "oak walls", "wall", "walls" }) :
                "Made of strong oak, these walls look like they could resist "
                "much damage.",
             ({ "grimy window", "window" }) :
                "This window seems as though it has not been cleaned in "
                "years."
             ]) );
  SetListen( ([ 
              "default" : "The sounds of drunken singing and laughter can "
              "be heard from inside."
              ]) );
  SetSmell( ([
             ({ "puddle of vomit", "vomit puddle", "vomit", "puddle" }) :
                "The vomit smells terrible!"
             ]) );
  SetInventory( ([ I_NPC "/drunkard" : 1 ]) );
  SetRead( ([
            ({"sign above the door", "sign"}) :
              "THE MORNING STAR INN\n"
              "    FOOD, DRINK\n"
              "       ROOMS"
            ]) );
  SetEnters( ([ "inn" : I_ROOM + "/main" ]) );
  SetExits( ([ "west" : "/domains/frostmarches/virtual/frostmarchrd/0,24" ]) );
  SetDomain("FrostMarches");
}
