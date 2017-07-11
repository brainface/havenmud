#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

mapping Vendors;

static void create() {
  ::create();
  SetNoClean(1);
  Vendors = ([ ]);
}

void eventReset(object vendor) {
/*
  object room;
  int v_time;
  string file;
  int i = 0;
  
  if (!vendor) return;
  if (!environment(vendor)) return;
  
  file = base_name(vendor);
  if (!Vendors[file]) Vendors[file] = time();
  v_time = Vendors[file];
  
  if (vendor)
  room = load_object(vendor->GetStorageRoom());
  if (!room) return;
  
  if ( (time() - v_time) > 43200) {
    if (sizeof(all_inventory(room)) > 30)
    foreach(object o in all_inventory(room)) {
      i++;
      o->eventDestruct();
      }
    Vendors[file] = time();
    if (i) CHAT_D->eventSendChannel("VENDOR", "reports", "Cleaned " + i + " items from " + vendor->GetKeyName() + " in " + short_file(base_name(environment(vendor))));
    }
*/    
}

int GetVendorTime(object file) {
  if (Vendors[base_name(file)]) return Vendors[base_name(file)];
  return -1;
}
