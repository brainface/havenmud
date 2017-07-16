#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create()  {
     room::create();
      SetClimate("indoors");
      SetShort("empty room");
      SetLong("This small, empty room is utterly devoid of signs of human "
        "life.  From the lack of even footprints in the dust, it is obvious "
     "that no one has disturbed it in quite some time. Several discolorations "
      "dot the room, owing their origins to furniture long gone. On the far wall, "
      "a brass torch holder can be seen, without its torch. Other than "
      "the single torch holder, the walls are empty of adornment. ");
     SetItems( ([
        ({ "empty room", "room"}) :
                 "This room appears to have been empty for quite some time.",
          ({ "torch-holder", "torch holder" }) :
                 "This brass torch holder contains no torch.",
      ({"stones", "floor" }) : "The dust covered stone floor is totally undisturbed."
            "It has obviously remained so for many, many years.",
      ({"discolorations" }) : "These faint discolorations in the walls and floors"
               "are the tell-tale signs of furniture long removed.",
      ({ "wall", "walls" }) : "The plain stone walls are empty except for the single"
      "torch holder. ",
           ]) );
    SetSmell( ([
                "default" : "The small room smells of dust." 
                       ]) );
    SetListen( ([
                "default" :  "The faint sound of water dripping "
                    "on stone can be heard. "
             ]) );
     SetExits( ([
          "west" : AVERATH_CITY + "keep3"
                   ]) );
}
