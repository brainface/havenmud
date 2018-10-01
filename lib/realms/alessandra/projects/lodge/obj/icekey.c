#include <lib.h>
#include "../lodge.h"
inherit LIB_KEY;
inherit LIB_ITEM;

int Life;
void destme();

static void create() {
  key::create();
  item::create();

  SetKeyName("ice key");
  SetKeyID("icekey01");
  SetId( ({"key"}) );
  SetShort("an ice key");
  SetLong("This key is made of pure ice.  It is almost chilllingly painful to hold in "
     "ones hand.  Its shape is contorted, making it fit for only a certain lock.  This "
     "key should be used fast, for it is melting rather quickly");
  SetAdjectives( ({"ice"}) );
  SetMaterial( ({"ice"}) );
  SetMass(1);
  SetValue(3);
  SetDamagePoints(20);

  set_heart_beat(1);
  Life = 60;

}

void heart_beat() {
  Life--;
  if (!Life) destme();
}

void destme() {
  if (environment(this_object())) {
    message("system","An ice key suddenly melts.",                     
environment(this_object()) );
  }
  eventDestruct();
}


