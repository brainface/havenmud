#include <lib.h>
#include <daemons.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("totem of resurrection");
  SetId( ({ "totem" }) );
  SetAdjectives( ({ "resurrection" }) );
  SetShort("a massive totem of resurrection");
  SetPreventGet("The totem is too massive to move.");
  SetLong(
    "The totem is a central focus of the area. Standing high above the "
    "other details, this totem is inscribed with ancient runes of power. "
    "Using this totem will resurrect anyone from the dead as if they had "
    "been touched by the hands of an Immortal. Be warned however, as this "
    "has a high cost."
    "\n<Using this totem returns your character to life without penalty, but costs 2 development points.>"
    );
}

mixed direct_use_obj() {
  return 1;
}

varargs int eventUse(object who, string what) {
  if (who->GetUndead() == 0) {
    send_messages("", "The totem flares a beam of light at $target_name, but dims quickly.", this_object(), who, environment(who));
    who->eventPrint("But you are not dead!");
    return 1;
  }
  if (who->GetDevelopmentPoints() < 2) {
    send_messages("", "The totem flares a beam of light at $target_name, but dims quickly.", this_object(), who, environment(who));
    who->eventPrint("But you don't have 2 development points!");
    return 1;
  }
  who->AddDevelopmentPoints(-2);
  who->SetUndead(0);
  send_messages("", "The totem flares a beam of light at $target_name, bringing $target_objective back to life!", this_object(), who, environment(who));
  CHAT_D->eventSendChannel("Totem", capitalize(who->GetKeyName()) + " used a totem to resurrect.");
  return 1;
}