#include <lib.h>
#include <daemons.h>
#define TARGET  "/domains/havenwood/areas/parvahosp/npc/hurt"
#define BANDIT  "/std/invasions/bandit/bandit"
#define THING   "/realms/duuk/stuff/thing"
inherit LIB_ROOM;
int PreExit(string dir);
int Shielded = 0;
static void create() {
  room::create();
  SetShort("a room");
  SetProperties( ([
     "wood repair" : 1,
     "metal repair" : 1,
     "natural repair" : 1,
     "textile repair" : 1,
     ]) );
  SetClimate("indoors");
  SetAmbientLight(40);
  SetInventory( ([
    "/realms/duuk/stuff/thing" : 1,
    ]) );
  SetAmbientLight(40);
  SetExits( ([
    "down" : "/domains/averath/towns/averath/room/wharf",
     ]) );
  AddExit("north", "../workroom", (: PreExit :) );
  SetLong("This is a small room.  There is a sign on the wall. \n"
          "There is an inn to the south.");
  SetItems( ([
    "inn" : "This is a test inn.",
    "coffeehouse" : "nessa's place",
     "sign"  : "This is a sign.  It has words on it.",
    ]) );
  SetRead( ([
     "sign" : "Functions of this room which are very nice: \n"
             "summon <thing, filename, no argument> \n"
             "healme \n"
             ,
    ]) );
  SetEnters( ([
     "inn" : "/domains/southern_coast/areas/wtraveller/room/wtraveller",
     "coffeehouse" : "/domains/southern_coast/areas/coffeehouse/room/coffeehouse",
     ]) );
 }

void init() {
  ::init();
  add_action("spellme", "spellme");
  add_action("songme", "songme");
  add_action("shield", "shield");
  add_action("summon", "summon");
  add_action("healme", "healme");
 }

int spellme(string args) {
  int x;
  if (!(SPELLS_D->GetSpell(args))) {
     this_player()->eventPrint("No such spell.");
     return 1;
     }
  if (x = (this_player()->eventLearnSpell(args))) {
     this_player()->eventPrint("You succeed.");
    return 1;
    } 
  else {
     this_player()->eventPrint("You failed to learn that spell.");
      return 1;
   }
  }
int summon(string args) {
   object thing;
  if (!args) args = THING;
  if (args == "thing") args = THING;
  if (args == "bandit") args = BANDIT;
  if (args == "target") args = TARGET;
  thing = new(args);
  if (!thing) {
     this_player()->eventPrint("BadThing[tm]");
     return 1;
   }
  thing->eventMove(this_object());
   thing->eventForce("speak You summoned me?");
  return 1;
  }

int healme() {
  this_player()->eventCompleteHeal(2500);
  this_player()->eventPrint("You feel much better now.");
  this_player()->SetUndead(0);
  this_player()->SetParalyzed(0);
  this_player()->SetSleeping(0);
  this_player()->SetRecoveryTime(0);
 return 1;
 }

int PreExit(string dir) {
  if (Shielded && !userp(this_player())) {
     return 0;
     }
   return 1;
   }

int shield(string str) {
  if (Shielded) {
       Shielded = 0;
         }
       else {
          Shielded = 1;
         }
   return Shielded;
  }

int songme(string song) {
  if (this_player()->eventLearnSong(song)) {
    message("system", "Yes.", this_player());
    return 1;
    }
    message("system", "No.", this_player());
    return 0;
 }
