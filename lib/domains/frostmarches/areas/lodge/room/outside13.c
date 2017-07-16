#include <lib.h>
#include "../lodge.h"
inherit LIB_ROOM;

static void create() {
  room::create();  
  SetShort("deep in the woods");
  SetDayLong("The trees around this area are creepy looking. The trees "
        "are big in size and have no leaves left on them making the "
        "bright sky visible. Small, dead bushes raise out of the ground, "
        "and pierce through the snow. Smoke can be seen in the air "
        "and a small structure can barely be made out in the distance. "
        "The snow is cold and looking at it, is partially blinding.  The "
        "snow gets quite deep, but the path is still noticeable. Dead "
        "leaves roll around on the ground adding a lifeless concept to this area. "
      "Big footprints are deeply imprinted into the snow.");
  SetNightLong("The trees around this area are creepy looking.  The trees "
        "are big in size and have no leaves left on them making the "
        "dark sky visible. Small, dead bushes raise out of the ground, "
        "and pierce through the snow. Smoke can be seen in the air "
        "and a small structure can barely be made out in the distance. "
        "The snow is cold and looking at it, is partially blinding. The "
        "snow gets quite deep, but the path is still noticeable. Dead "
        "leaves roll around on the ground adding a lifeless concept to this area. "
      "Big footprints are deeply imprinted into the snow.");
  SetAmbientLight(20);
  SetClimate("arctic");
  SetItems( ([
        "woods" : (:GetLong:),
        ({"tree","trees"}) : "These trees are exceptionally big.  They're dead with "
        "no leaves so the sky can be seen through their tops.  These "
        "things are creepy looking.",
        ({"sky"}) : "The sky is gray and hazey.  It gives a spooky feeling "
        "to the rest of the woods.",
        ({"bush","bushes"}) : "The bushes are dead, due to the cold.  "
        "They pierce through the snow and are probably big bushes when "
        "the snow is melted.",
        ({"smoke"}) : "Big columns of dark smoke can be seen in the air.  "
        "There must be something up ahead supporting fire.",
        ({"structure"}) : "This structure can barely be seen.  There is definitely "
        "something up ahead.",
        ({"snow"}) : "The snow is bright and will make anyone wince.  "
      "It is really cold and fairly deep.",
        ({"path","trail"}) : "This path leads off further into the woods.  It can easily "
        "be followed.",
        ({"leaves"}) : "These leaves have fallen off of the trees and bushes.  "
        "They're scattered around and are pretty much dead.",
  ({"print","prints","footprint","footprints"}) : "These footprints are huge.  "
        "They belong to a robust creature.  Something says there is trouble "
        "ahead."
  ]) );
  SetItemAdjectives( ([
        "tree" : ({"big","dead"}),
        "sky" : ({"gray","hazey"}),
        "bush" : ({"dead"}),
        "smoke" : ({"big"}),
        "snow" : ({"bright","deep"}),
        "leaves" : ({"dead"}),
        "footprint" : ({"huge"}),
  ]) );
  SetExits( ([
      "east" : L_ROOM + "outside6.c",
      "west" : L_ROOM + "outside14.c",
  ]) );
  SetInventory( ([
  ]) );
  SetSmell( ([
        "default" : "The smell of smoke is fills the air.",
  ]) );
  SetListen( ([
      "default" : "The crunching of footsteps being made silence off further in the path.",
  ]) );
}
