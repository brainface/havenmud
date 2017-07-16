#include <lib.h>
#include "/domains/havenwood/towns/parva.h"
#include "/domains/havenwood/areas/assassin_hall/assassin_hall.h"

inherit LIB_ROOM;

int GuildCheck();

static void create() {
   room::create();
   SetTown("Parva");
   SetAmbientLight(30);
   SetClimate("indoors");
   SetShort("a tunnel under the inn");
   SetLong("A ladder in this narrow tunnel lead upwards towards Minkin's "
           "Inn and down towards the home of the Organization. The tunnel "
           "itself is fashioned from rough laid brick and is oddly well "
           "maintained."
           );
   SetItems( ([ "brick"  : "The brick is old and moldy, slick to the touch.",
                "ladder" : "The ladder is corroded and leads up to the inn."
             ]) );
   SetListen("The shuffling of chairs and the murmur of conversation can be heard above in the inn.");
   SetSmell("The smell of good food mingles with the rotting smell of the tunnel.");
   SetExits( ([
      "out"  : P_ROOM + "/inn",
      ]) );
  SetProperty("no attack", 1);
  SetProperty("no magic", 1);
   AddExit("east", AH_ROOM + "assassin_guildhall", (: GuildCheck :) );
}

int GuildCheck() {
  object who = this_player();
  
  if (who->GetGuild() != "twilight" && !creatorp(who)) {
    who->eventPrint("Something prevents you from going east.");
    return 0;
  }
  return 1;
}
