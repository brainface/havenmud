/*  Continuation of road  */

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetShort ("a trail towards the mountain");
  SetClimate("arctic");
  
  SetExits( ([
     "east" : ROOM "/path5",
     "west" : ROOM "/path3",
  ]) );

  SetDayLong("The lonely trail continues its trek across the frozen tundra.  "
             "The mountain to the northeast dominates the skyline.  "
             "The peak of the mountain is shrouded in clouds.  There seems "
             "to be a strange light halfway up the mountain.");

  SetNightLong("The dark path continues it trek through the dark, frozen "
               "tundra.  A large patch of inky blackness covers the sky to "
               "the northwest, bloting out the stars.  The mountain rises "
               "into the night sky like a black spire.  A silver light "
               "shines from a plateau halfway up the mountain.");

  SetItems( ([
    ({ "small frozen trail", "dark path", "lonely trail", "trail",
       "path", "small trail", "frozen trail" })  :
       "The small frozen trail weaves throught the snow-covered terrain.",
    ({ "dark, frozen tundra","dark frozen tundra", "terrain", "frozen tundra",
       "tundra", "dark tundra", "snow-covered terrain" })   :
       "The terrain is covered in a blanket of ice and snow.  There "
       "appears to be a mountain to the northeast.",
    ({ "dark", "darkness" })  :
       "The darkness covers everything like a blanket.",
    ({ "mountain", "patch", "large patch", "inky blackness", "blackness",
       "large patch of inky blackness", "black spire", "spire" })  :
       "The mountain to the northeast, fills the sky with its majesty.  "
       "The peak is out of sight; it is covered by clouds.  An eerie glow "
       "raidiates from a plateau half way up the mountain.",
    ({ "strange silvery glow", "light", "glow", "eerie glow", "silvery glow",
       "strange light" })  :
       "A strange silvery glow radiates from a mountain plateau.",
    ({ "mountain plateau", "plateau" })  :
       "A mountain plateau lies halfway up this mountain.  Something on the "
       "mountain sheads a silver light.",
    ({ "mountain peak", "peak" })  :
       "The mountain peak is covered in white clouds.",
    ({ "fluffy white clouds", "fluffy white cloud", "fluffy clouds", 
       "fluffy cloud", "white clouds", "white cloud", "cloud", "clouds" })  :
       "Fluffy white clouds conceal the top of the mountain.",
     ({ "blanket of ice and snow", "ice and snow", "snow", "ice" })  :
       "Ice and snow cover the frozen tundra.",
   ]) );

  SetSmell( ([
    "default"  : "The cold air smells fresh and clean.  A faint hint of dirt "
                 "is carried by the wind.",
  ]) );
 
  SetListen( ([
    "default"  : "The roar of the wind is lessened slightly by the mountain.",
  ]) );
}
