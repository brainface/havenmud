#include <lib.h>
#include "../lodge.h"
inherit LIB_ROOM;

 static void create() {
    room::create();
   SetShort("outside a lodge");
    SetDayLong("The trees around this area are creepy looking. The trees "
          "are big in size and have no leaves left on them making the "
          "bright sky visible. Small, dead bushes raise out of the ground, "
          "and pierce through the snow. A big lodge lies right here. It "
          "looks as if it can be entered and no harm or trouble seems to "
          "come from taking a look at it. Big footprints enter and leave the lodge. "
         "The area around the lodge is rather eerie and looks uneasy.");
      SetNightLong("The trees around this area are creepy looking. The trees "
          "are big in size and have no leaves left on them making the "
          "dark sky visible. Small, dead bushes raise out of the ground, "
          "and pierce through the snow. A big lodge lies right here. It "
          "looks as if it can be entered and no harm or trouble seems to "
          "come from taking a look at it. Big footprints enter and leave the lodge. "
         "The area around the lodge is rather eerie and looks uneasy.");
   SetAmbientLight(20);
   SetClimate("arctic");
    SetItems( ([
        "woods" : (:GetLong:),
       ({"tree","trees"}) : "These trees are exceptionally large.  They are dead with "
          "no leaves so the sky can be seen through their tops.  These "
          "things are creepy looking.",
          ({"sky"}) : "The sky is gray and hazey.  It gives a spooky feeling "
          "to the rest of the woods.",
          ({"bush","bushes"}) : "The bushes are dead, due to the cold.  They "
          "pierce through the snow and are probably big bushes when the snow "
          "is melted.",
          ({"smoke"}) : "Big columns of dark smoke can be seen in the air.  "
          "There must be something up ahead supporting fire.",
       ({"print","prints","footprint","footprints"}) : "These footprints are huge.  "
          "They belong to a robust creature.  Something says there is "
          "trouble ahead.",
          ({"lodge"}) : "This lodge seems to bring no trouble.  It looks warm and "
        "welcoming.  Big footprints enter and leave the lodge.",
   ]) );
   SetItemAdjectives( ([
          "tree" : ({"large"}),
          "sky" : ({"gray","hazey"}),
          "bush" : ({"big"}),
          "footprint" : ({"huge"}),
          "lodge" : ({"warm","welcoming"}),
   ]) );
    SetExits( ([
       "west" : L_ROOM + "outside10.c",
   ]) );
  SetEnters( ([  //torak 2013 -- you ENTER lodges
       "lodge" : L_ROOM + "mainfloor.c",
  ]) );
    SetSmell( ([
          "default" : "The smell of smoke and sweat filter the room.",
   ]) );
    SetListen( ([
          "default" : "Quiet hisses circulate through the area.",
   ]) );
 }
