#include <lib.h>
#include <save.h>
#include <daemons.h>
inherit LIB_DAEMON;

void LoadEstates();
private mapping Estates;

mapping AddEstate(string estate, string location) {
  Estates += ([ estate : location ]);
  save_object(SAVE_ESTATES "/MASTER_LIST");
  LoadEstates();
  return Estates;
}

mapping RemoveEstate(string estate) {
  map_delete(Estates, estate);
  save_object(SAVE_ESTATES "/MASTER_LIST");
  return Estates;
}

mapping GetEstates() { return Estates; }

void LoadEstates() {
  object ob, est, dest;
  foreach(string estate in keys(Estates)) {
    ob = load_object(estate);
    if (!ob) continue;
    if (!(user_exists(lower_case(ob->GetOwner())))) {
      CHAT_D->eventSendChannel("Estate", "error", "No such user (" + ob->GetOwner() + ") to load an estate for!");
      RemoveEstate(estate);
      continue;
    }
/*    
    dest = load_object(Estates[estate]);
    if (dest) {
      if (!present("estate", dest)) {
        est = new(LIB_ESTATE);
        est->eventMove(dest);
        est->SetTown(ob->GetTown());
        est->SetOwner(ob->GetOwner());
      }
    } */
  }
}
    

static void create() {
  ::create();
  Estates = ([]);
  restore_object(SAVE_ESTATES "/MASTER_LIST.o");
  LoadEstates();
  set_heart_beat(60);
}

int GetEstate(string estate) {
  if (Estates[estate]) return 1;
  return 0;
}

void heart_beat() { 
  LoadEstates();
}

void LoadRoom(string room) {
  mapping m = Estates;
  object est = 0;
  object ob;
  foreach(string k in keys(m)) {
    if (m[k] == room) {
       ob = load_object(k);
       if (!ob) continue;
       if (!present("estate", find_object(room))) {
        est = new(LIB_ESTATE);
        est->eventMove(room);
        est->SetTown(ob->GetTown());
        est->SetOwner(ob->GetOwner());
      }
    }
  }
}

      