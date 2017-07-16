#include <lib.h>
#include <daemons.h>

inherit LIB_ITEM;

int sab(string message);
int sabemote(string message);

static void create() {
  item::create();
  SetKeyName("device");
  SetId( ({ "awesome device", "device" }) );
  SetShort("Sab's Awesome Device");
  SetLong("This is an awesome device for the awesome Sab.");
  SetValue(0);
  SetMass(2000000);
  SetInvis(1);
}

void init() {
  item::init();
  add_action("sab", "sab");
  add_action("sabemote", "sabemote");
}

int sab(string message) {
  CHAT_D->eventSendChannel("Sab", "imm", message, 0, 0, 0);
  return 1;
}

int sabemote(string message) {
  CHAT_D->eventSendChannel("Sab", "imm", message, 1, 0, 0);
  return 1;
}
