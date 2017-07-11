/*  A simple location spell */
#include <lib.h>
#include <domains.h>
#define DESERT  YOZRATH_VIRTUAL "desert/"
#include <music.h>
inherit LIB_SONG;

static void create() {
  ::create();
  SetSong("desert path");
  SetRules("");
  SetSongType(SONG_OTHER);
  SetSkills( ([
     "instrumental music" : 10,
     "vocal music"        : 10,
    ]) );
  SetDifficulty(15);
  SetMagicCost(20, 20);
  SetHelp(
    "This song aids the dancer in finding their way back to the city of Yozrath "
    "from anywhere in the desert."
    "\nOnly the DANCER class may use this song."
    );      
          
 }

varargs int CanSing(object who, int level, mixed q, object *t) {
  if (who->GetClass() != "dancer") {
    who->eventPrint("Only actual dancers may use this song.  You should forget it.");
    return 0;
  }
  return ::CanSing(who, level, q, t);
}

varargs int eventSing(object who, int level, mixed q, object *t) {
  int x, y;
  string loc = base_name(environment(who));
  string *nums = ({ });
  if (strsrch(loc, "/domains/yozrath/towns/yozrath") != -1) {
    message("system", "You are in Yozrath City!", who);
    return 1;
    }
  if (strsrch(loc, DESERT) == -1) {
     message("system", "But you are not in the desert!", who);
     return 0;
    }
  loc = loc[strlen(DESERT)..strlen(loc)-1];
  nums = explode(loc, ",");
  x = to_int(nums[0]);
  y = to_int(nums[1]);
  if (y < 0) loc = "south";
  if (y > 0) loc = "north";
  if (y == 0) loc = "";
  if (x < 0) loc += "west";
  if (x > 0) loc += "east";
  if (x == 0 && y == 0) {
    message("system", "You are at the center of the Yozrath Desert!",
            who);
    return 1;
  }
  message("system",
   "You are " + loc + " of the Oasis at Yozrath.", who);
  return 1;
  }

