/*   Workroom V3.0 for Il Duuk */
#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;
inherit LIB_TOUCH;

int Allowed(object ob);
int shield(string args);
private int Shielded = 1;
private string *WhoAllowed = ({ "duuk",
                                "azzie",
                                "yanna",
                        });

static void create() {
  ::create();
  SetShort("a nexus of swirling mists");
  SetDomain("Planes");
  SetTown("Duuk's Workroom");
  SetClimate("indoors");
  SetAmbientLight(50);
  SetLong("The mists of the universe converge here into a nexus "
          "point. All around there are wyrmholes and rifts leading "
          "to various places in the Heavens. The chaos "
          "of the mists seems to be almost orderly in its patterns of "
          "shift and change, each wisp of cloud seeming to beg for "
          "the naive wanderer to follow its course. Off to "
          "the south the mists seem almost inviting, as if they are "
          "beckoning explorers to space. To the east the "
          "mists seem to firm up and oddly resemble Kailie.");
  SetListen( ([
    "default" : "The whisper of the mists is a "
                "gentle purr against the silence.",
    ]) );
  SetSmell( ([
    "default" : "The mists have no discernable smell.",
    ]) );
  SetTouch( ([
     "default" : "The mists caress you into a dreamlike state.",
    ]) );
  SetExits( ([
    "quests"   : "/domains/southern_coast/virtual/havenroad/mission_tent",
    "underland" : "/domains/valley/towns/underland/room/gate",
    "averath"  : "/domains/averath/towns/averath/room/wharf",
    "havenwood" : "/domains/havenwood/towns/havenwood/room/gelf4",
     "arena" : "/domains/peninsula/towns/sanctum/room/arena1",
     "kresh"  : SOUTHERN_COAST_TOWNS "kresh/room/m_1",
    "lisht" : XANDRIA_TOWNS "lisht/room/gnoll/gate",
    "yozrath"    : "/domains/yozrath/towns/yozrath/room/oasis3",
    "arcanith"   : "/domains/frostmarches/towns/arcanith/room/ruins2",
    "keryth"     : "/domains/frostmarches/towns/keryth/room/road3",
    "kysanth"   : "/domains/baria/areas/jungle/lair",
    "grymxoria" : "/domains/estergrym/towns/grymxoria/room/road1",
    "gurov"     : "/domains/gurov/towns/gurov/room/cathedral3",
    "karak"     : "/domains/crystal_reaches/towns/karak/room/rd1",
    "ocean" : "/domains/innersea/virtual/ocean/0,-100",
    "gwonish" : "/domains/crystal_reaches/towns/gwonish/room/gw12",
    "lloryk" : "/domains/crystal_reaches/towns/lloryk/room/wharf",
      "glimmerdin"  : "/domains/crystal_reaches/towns/glimmerdin/room/keep",
      "north" : "/domains/staff/staffroom",
    "south" : "stuff/offroom",
    "east" : "/domains/southern_coast/towns/haven/room/imperial_road/ir2",
      "west" : "stuff/west",
    "stryke" : "/domains/havenwood/areas/stryke/lair/2_i",
     ]) );
  SetObviousExits("various mists lead away");
  Shielded = 0;
  SetInventory( ([
     ]) );
  }

void init() {
  ::init();
  add_action("shield", "shield");
  add_action("Check", ({
       "ed", "rm", "update", "quit", "dest", "duc",
       "home", "goto", "call", "eval",
        }) );
  }

int CanReceive(object ob) {
  if (!Allowed(ob)) {
        message("system",
   "%^BLUE%^An elven female stops you before you manage to enter and "
   "asks if you have an appointment.  Seeing that you do not, she "
   "promptly bars the door.%^RESET%^", ob);
/*
  message("system", 
      "%^BLUE%^" + capitalize(ob->GetKeyName()) + " just tried "
      "to visit uninvited.  How rude!%^RESET%^", this_object() );
*/
    }
  else return Allowed(ob);
  }

int CanRelease(object ob) {
  if (Shielded) return 0;
  return 1;
   }

int shield(string args) {
  if (this_player()->GetKeyName() != "duuk" &&
      this_player()->GetKeyName() != "louise") {
     message("system",
        (Shielded ? "The shield is up." : "The shield is down."),
         this_player() );
      return 1;
     }

  if (args == "up") {
     send_messages("raise",
        "$agent_name $agent_verb the shield.",
          this_player(), 0, this_object() );
       return (Shielded = 1);
     }
  if (args == "down") {
     send_messages("lower",
        "$agent_name $agent_verb the shield.",
          this_player(), 0, this_object() );
       Shielded = 0;
        return 1;
      }
  if (!args) {
      message("system",
         (Shielded ? "The shield is up." : "The shield is down."),
         this_player() );
       return 1;
      }
  return 0;
  }

int Allowed(object ob) {
  if (!ob) ob = this_player();
  if (!Shielded) return 1;
  if (member_array(ob->GetKeyName(), WhoAllowed) != -1) 
     return 1;
  else return 0;
  }

int Check(string args) {
   if (Allowed(this_player())) { return 0; }
  else {
      message("system", "You are prevented by the shield.",
              this_player() );
         return 1;
       }
  }

varargs int eventDig(object who, object what) {
  if (!who) {
  	debug("Woot No Who! " + identify(what));
  	return 1;
  	}
  debug(identify(who) + " " + identify(what));
  return 1;
}
