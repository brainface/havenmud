#include <lib.h>
#include <damage_types.h>

inherit LIB_ITEM;

void SetArgs(string limb, object who, int level, int xdamage);

string limb;
int life, damage;
object who;

static void create() {
  item::create();
  SetKeyName("gangrene");
  SetId( ({ "gangrene_thingy" }) );
  SetShort("");
  SetPreventGet("There is no gangrene_thingy here.");
  SetPreventDrop("There is no gangrene_thingy here.");
  SetLong("There is no gangrene_thingy here.");
  SetInvis(1);
  AddSave( ({ "limb", "life", "who", "damage" }) );
  set_heart_beat(8);
}

void SetArgs(string xlimb, object xwho, int level, int xdamage) {
  limb = xlimb;
  who = xwho;
  life = level;
  damage = xdamage;
}

void heart_beat() {
  if(!environment()){eventDestruct();return;}
  if (!living(environment()) ||
  !life ||
  !environment()->GetLimb(limb))
  {
    eventDestruct();
  return;
  }
  environment()->eventReceiveDamage(this_object(), DISEASE, damage, 0, limb);
  environment()->eventPrint("Your " + limb + " rots a little more.");
  life--;
}
