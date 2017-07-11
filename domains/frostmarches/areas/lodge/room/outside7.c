#include <lib.h>
#include "../lodge.h"
inherit LIB_ROOM;

 static void create() {
   room::create();
  SetShort("a cold pathway through the woods");
   SetDayLong("The trees around this area are creepy looking.  The trees "
         "are big in size and have no leaves left on them making the bright sky "
         "visible. Small, dead bushes raise out of the ground, and pierce "
         "through the snow.  Small animal tracks can be seen leaping from "
         "bush to bush.  The snow is cold and looking at it, is partially blinding.  "
         "The snow gets quite deep, but the path is still noticeable.  Dead leaves "
         "roll around on the ground adding a lifeless concept to this area.  "
       "Big footprints lead ahead in the trail.");
   SetNightLong("The trees around this area are creepy looking.  The trees "
         "are big in size and have no leaves left on them making the dark sky "
         "visible. Small, dead bushes raise out of the ground, and pierce "
         "through the snow.  Small animal tracks can be seen leaping from "
         "bush to bush.  The snow is cold and looking at it, is partially blinding.  "
         "The snow gets quite deep, but the path is still noticeable.  Dead leaves "
         "roll around on the ground adding a lifeless concept to this area.  "
       "Big footprints lead ahead in the trail.");
  SetAmbientLight(20);
  SetClimate("arctic");
   SetItems( ([
        "woods" : (:GetLong:),
         ({"tree","trees"}) : "These trees are exceptionally large.  "
       "They are dead with no leaves so the sky can be seen through "
         "their tops.  These things are creepy looking.",
         ({"sky"}) : "The sky is gray and hazey.  It gives a spooky "
         "feeling to the rest of the woods.",
         ({"bush","bushes"}) : "The bushes are dead, due to the cold.  "
         "They pierce through the snow and are probably big bushes "
         "when the snow is melted.",
         ({"tracks"}) : "These tracks are left behind from small animals.  "
         "They are going from bush to bush and carry no sign of threat.",
         ({"snow"}) : "The snow is bright and will make anyone wince.  "
       "It is really cold and is fairly deep.",
         ({"path","trail"}) : "This path leads off further into the woods.  "
         "It can easily be followed.",
         ({"leaves"}) : "These leaves have fallen off of the trees and bushes.  "
       "They are scattered around and are pretty much dead.",
       ({"print","prints","footprint","footprints"}) : "These footprints are huge.  "
         "They belong to a robust creature.  Something says there is trouble "
         "ahead.",
   ]) );
  SetItemAdjectives( ([
         "tree" : ({"large"}),
         "sky" : ({"gray","hazey"}),
         "bush" : ({"dead","big"}),
         "snow" : ({"bright","cold","deep"}),
         "leaves" : ({"dead"}),
         "footprint" : ({"huge"}),
  ]) );
   SetExits( ([
      "north" : L_ROOM + "outside8.c",
   ]) );
   SetInventory( ([
   ]) );
   SetSmell( ([
         "default" : "The scent of the outdoors revolves here.",
   ]) );
   SetListen( ([
       "default" : "Whirling winds and the hungry howls of animals echo through the "
       "woods.",
   ]) );
}
