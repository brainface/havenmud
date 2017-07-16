#include <lib.h>
inherit LIB_ROOM;
#include "ditmar.h"

int PreExit();

static void create() {
   room::create();
   SetTown("Ditmar");
   SetClimate("indoors");
   SetAmbientLight(8);
   SetShort("Ditmar Cemetary");
   SetLong("The cave here is not very large in size, but prominent "
           "tombs sit at either side of a path that goes straight through "
           "to a ramp heading down into more levels of the cemetary.  "
           "To the west, the path leads out into the rest of Ditmar.  "
           "Stalagmites and stalactites make the going hard through "
           "here, as most have been allowed to grow unhampered.");
   SetItems( ([
                ({ "Ditmar Cemetary","cemetary","ditmar","ditmar "
                   "cemetary","cave" }) :
                   (: GetLong :),
                ({ "prominent tombs","tombs","tomb" }) :
                   "The tombs at this level are ornate and well "
                   "adorned.  Most have designs and colors similar to "
                   "those of stalagmites and stalactites, set in "
                   "basic shapes of heavenly angels and beautiful "
                   "waterfalls.",
                ({ "stalagmites and stalactites","stalagmites",
                   "stalagmite","stalactites","stalactite" }) :
                   "In much of the cemetary, the stalagmites and "
                   "stalactites have been given free reign.  They "
                   "have grown large and into strange shapes, almost "
                   "like ghostly guards watching over the dead.  "
                   "A straight path goes through them to the ramp, "
                   "however.",
                ({ "straight path","path" }) :
                   "Little adornment needed for itself, the path is "
                   "plain and straight, leading directly through the "
                   "Ditmar Cemetary to the plain ramp.",
                ({ "plain ramp","ramp","stone earth","earth","stone" }) :
                   "The ramp at the east end of the Cemetary is "
                   "plain, going down into the depths of the stone "
                   "earth.",
           ]) );
   SetItemAdjectives( ([
                         "tombs" : ({ "prominent" }),
                    ]) );
   SetSmell( ([
               "default" : "While the rest of Ditmar is fresh and "
                  "untainted despite its great depth in the ground, "
                  "the cemetary smells old and hidden away.",
          ]) );
   SetListen( ([ 
                 "default" : "Faint noises seem to come from the ramp.",
            ]) );
   SetExits( ([
                "west" : D_ROOM + "/cave_b",
           ]) );
   AddExit("down",D_ROOM + "/cemet", (: PreExit :));
}

int PreExit() {
   this_player()->eventPrint("%^RED%^No one may enter the lower levels "
                             "until safeties have been constructed to "
                             "protect Ditmar Citizens from the "
                             "strange creatures below.");
   return 0;
}