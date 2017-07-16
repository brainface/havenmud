#include <lib.h>
#include <std.h>

inherit LIB_ROOM;

#define OWNER "tassadar"

int welcome(string person);
int shield(string arg);
int eject(string person);

string *ppl = ({ "" });
int shielded = 1;

static void create() {
  room::create();
  SetShort("%^BLUE%^BOLD%^FLASH%^B_RED%^Tassadar's gardens"
     "%^RESET%^");
  SetLong("A large garden filled with lovely %^YELLOW%^flowers"
          "%^RESET%^. It looks " 
          "as if people through the ages have come here to "
          "%^BOLD%^relax%^RESET%^."
          " and conjure thoughts and ideals for the better of Kailie."); 
  SetClimate("outdoors");
  SetAmbientLight(50);
  SetObviousExits("%^YELLOW%^down, %^BLUE%^south, %^WHITE%^up, %^RED%^north, "
    "%^RESET%^");
  SetExits( ([
  ]) );
  restore_object("/realms/tassadar/workroom3");
  SetDomain("Heaven");
  SetInventory( ([
    "/realms/tassadar/fountain" : 1,
  ]) );}

void init() {
  room::init();
  if (this_player()->GetKeyName() == OWNER) {
    add_action("welcome", "welcome");
    add_action("shield", "shield");
    add_action("eject", "eject");
    add_action("commands", "commands");
  }
}

int CanReceive(object ob) {
  object owner;
  if (!shielded) {
    if (owner = find_living(OWNER)) {
      owner->eventPrint("BOLD%^BLUE%^FLASH%^" +
        capitalize(ob->GetKeyName()) +
        " enters the room.%^RESET%^");
    }
    return 1;
  }
  if ((securep(ob)) ||
     (member_array(ob->GetKeyName(), ppl) != -1) ||
     (ob->GetKeyName() == OWNER) ||
     (!userp(ob))) {
    if (owner = find_living(OWNER)) {
      owner->eventPrint("BOLD%^BLUE%^FLASH%^" +
        capitalize(ob->GetKeyName()) +
        " enters the room.%^RESET%^");
    }
    return 1;
  }
  ob->eventPrint("%^BOLD%^BLACK%^B_WHITE%^FLASH%^No, be gone!%^RESET%^");
  if (owner = find_living(OWNER)) {
    owner->eventPrint("%^BOLD%^BLUE%^FLASH%^" +
      capitalize(ob->GetKeyName()) +
      " tried to enter.%^RESET%^");
  }
  return 0;
}

int welcome(string person) {
  object ob = this_player();

  if (ob->GetKeyName() != OWNER) {
    ob->eventPrint("WTF are you doin?.");
    return 1;
  }

  if (!person) {
    ob->eventPrint("%^YELLOW%^BOLD%^______________________________%^RESET%^");


      foreach(string p in ppl) {
      ob->eventPrint("     " + capitalize(p));
    }
    ob->eventPrint("%^YELLOW%^BOLD%^%^RESET%^");
    return 1;
  }

  if (member_array(person, ppl) == -1) {
    ppl += ({ lower_case(person) });
    save_object("/realms/tassadar/atrus/arena", 1);
    ob->eventPrint("Person %^RED%^added%^RESET%^");
    return 1;
  }

  ppl -= ({ person });
  save_object("/realms/tassadar/atrus/arena", 1);
  ob->eventPrint("Person %^WHITE%^removed%^RESET%^.");
  return 1;
}

int shield(string arg) {
  object ob = this_player();

  if (ob->GetKeyName() != OWNER) {
    ob->eventPrint("WTF are you doin?");
    return 1;
  }

  if (!arg) {
    ob->eventPrint("The shield is " + (shielded ? "up." : "down."));
    return 1;
  }
  
  shielded = (shielded ? 0 : 1);
  ob->eventPrint("The shield is now " + (shielded ? "up." : "down."));
  return 1;
}

int eject(string person) {
  object ob = this_player();

  if (ob->GetKeyName() != OWNER) {
    ob->eventPrint("WTF are you doin?");
    return 1;
  }

  if (!person || person == OWNER) {
    ob->eventPrint("Eject yourself?");
    return 1;
  }

  if (present(person)) {
    find_living(person)->eventMove("/domains/heaven/room/clouda");
    find_living(person)->eventPrint("%^BOLD%^YELLOW%^B_RED%^FLASH%^You have "
      "been thrown out like a dog!%^RESET%^");
    ob->eventPrint(capitalize(person) + " has been ejected.");
    return 1;
  }

  ob->eventPrint("No.");
  return 1;
}

int commands() {
  this_player()->eventPrint("Commands are:\nwelcome\nshield\neject");
  return 1;
}
