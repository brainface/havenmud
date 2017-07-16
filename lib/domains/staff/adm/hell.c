/*  Hell.  A bad place to be, overall.
 *  Duuktsarth@Haven  10-11-97
 */
#include <lib.h>
#include <std.h>
inherit LIB_ROOM;

static void create() {
  room::create();
SetProperty("no exits",1);
SetProperty("no weather", 1);
  SetDomain("Planes");
SetProperty("no magic", 1);
  SetProperty("no teleport",1);
  SetProperty("no attack",1);
  SetShort("Hell");
  SetLong("The fiery pits of hell are an unpleasant and dull "
          "place to be.  You should have been nicer in life. "
          "You should pray for redemption, or simply start "
          "over and be nicer.");
  SetProperty("lower plane",1);
  SetObviousExits("atonement is an escape");
  AddExit("south", "/domains/staff/room/death");
  SetInventory( ([
    STD_OBJ "rule_book" : 1,
   ]) );
 }

void init() {
  ::init();
  if (creatorp(this_player())) return;
  this_player()->RestrictChannel( ({ "ooc", }) );
  this_player()->RestrictChannel( ({ "non" }) );
     
  add_action("tell", "tell");
  add_action("reply", "reply");
  add_action("wizhelp", "wizhelp");
  add_action("emote", "emote");
  }

int eventReleaseObject() {
   previous_object()->UnrestrictChannel( ({ "ooc" }) );
   return 1;
}
int tell(string useless) {
  this_player()->eventPrint("You cannot tell.  You have been damned.");
  return 1;
  }

int reply(string useless) {
  this_player()->eventPrint("You cannot tell.  You have been damned.");
  return 1;
  }

int wizhelp(string useless) {
   this_player()->eventPrint("You cannot ask for help. You have been damned.");
   return 1;
   }

int emote(string useless) {
  this_player()->eventPrint("You cannot emote. You have been damned.");
  return 1;
  }

void heart_beat() {
  object *people = all_inventory(this_object());
  if (!sizeof(people)) return 0;
  foreach(object person in people) {
    if(!immortalp(person)) {
    message("system", "You burn insufferably.", person);
         }
       }
  return;
  }
