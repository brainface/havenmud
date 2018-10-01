#include <lib.h>
#include <std.h>
#include <dirs.h>
inherit LIB_ROOM;
#define OWNER "laoise"
int shield(string arg);
int shielded = 1;
string *ppl = ({
    "zzlaoise",
    "drogo",
    "zeddicus",
    "yanna",
    "thoin",
  });


static void create() {
  room::create();
  SetShort("A black void");
  SetLong(
    "Suspended in the black void is a tangle of spider "
    "webbing. It thickens in the middle, forming an area for "
    "sitting and reclining. Papers scattered across the webbing "
    "suggest that this is a work area."
  );
  SetInventory( ([
    "/realms/laoise/home/frog" : 1,
  ]) );
  SetClimate("indoors");
  SetAmbientLight(40);
  SetExits( ([
    "southwest" : "/domains/gurov/towns/gurov/room/cathedral4",
    "southeast" : "/domains/estergrym/towns/grymxoria/room/church1d",
    "west" : "/domains/staff/room/portal",
    "northwest" : "/domains/estergrym/towns/targoviste/room/gate_west",
    "northeast" : "/domains/estergrym/towns/targoviste/room/east_wall3",
     "north" : DIR_STANDARD_DOMAIN "/staffroom",
    "south" : "/realms/laoise/home/other_room",
    "down" : "/domains/southern_coast/towns/haven/room/gate",
    "east" : STD_AREA "room/basic",
    "karak" : "/domains/crystal_reaches/towns/karak/room/rd3",
    "portal" : "/domains/staff/room/portal",
      ]) );
  SetObviousExits("darkness");
  SetSmell( ([
    "default" : "A sharp metallic tang cuts through the air.",
  ]) );
  SetListen( ([
    "default" : "Chittering and clicking echos through the darkness.",
  ]) );
  }


void init() {
  room::init();
  if (this_player()->GetKeyName() == OWNER) {
     add_action("shield", "shield");
  }

}


  int CanRelease(object ob) {
    object owner;
    if (owner = find_living(OWNER)) {
    owner->eventPrint("%^CYAN%^BOLD%^ " +
    capitalize(ob->GetKeyName()) + 
    " leaves your workroom.%^RESET%^");
    }
  return 1;
}

int CanReceive(object ob) {
  object owner;
  if (!shielded) {
    if (owner = find_living(OWNER)) {
    owner->eventPrint("%^CYAN%^BOLD%^ " +
    capitalize(ob->GetKeyName()) +
    " enters your workroom.%^RESET%^");
    }
  return 1;
  }
  if ((archp(ob)) ||
     (member_array(ob->GetKeyName(), ppl) != -1) ||
     (ob->GetKeyName() == OWNER) ||
     (!userp(ob))) {
    if (owner = find_living(OWNER)) {
     owner->eventPrint("%^CYAN%^BOLD%^ " +
     capitalize(ob->GetKeyName()) +
     " enters into your workroom.%^RESET%^");
     }
  return 1;
  }

  ob->eventPrint("%^CYAN%^BOLD%^You are not allowed inside Laoise's "
     "workroom without permission. %^RESET%^");
  if (owner = find_living(OWNER)) {
     owner->eventPrint("%^CYAN%^BOLD%^ " +
     capitalize(ob->GetKeyName()) +
     " tried to enter your workroom uninvited!%^RESET%^");
  }
  return 0;
}
int shield(string arg) {
  object ob = this_player();
  if (ob->GetKeyName() != OWNER) {
    ob->eventPrint("%^CYAN%^BOLD%^Or not.%^RESET%^");
     return 1;
  }
  if (!arg) {
    ob->eventPrint("%^CYAN%^BOLD%^This shield is"+ (shielded ?" on.%^RESET%^" : " off.%^RESET%^"));
     return 1;
  }
  shielded = (shielded ? 0 : 1);
    ob->eventPrint("%^CYAN%^BOLD%^This shield is now"+ (shielded ?" on.%^RESET%^" : " off.%^RESET%^"));
  return 1;
}
