 /*
  * Shield Area
  * Temporarily blocks teleports to a given area.
  * Balishae Feb98
  */
#include <lib.h>
#include <magic.h>
#include <message_class.h>

inherit LIB_SPELL;

int ShieldArea(object who);
int EndShieldArea(object env);

void create(){
  ::create();
  SetSpell("shield area");
  SetRules("");
  SetSkills( ([
    "conjuring" : 55,
    "enchantment" : 55
  ]) );
  SetDifficulty(35);
  SetRequiredMagic(65);
  SetRequiredStamina(40);
  SetMagicCost(50,15);
  SetStaminaCost(25,15);
  SetSpellType(SPELL_OTHER);
  SetHelp(
          "Completely shields an area to teleportation.  Once cast, "
          "one can neither teleport in or out.  The duration of the "
          "spell is limited by the caster's level.");
}

varargs int eventCast(object who, int level, string limb, object *targets) {
  call_out((:ShieldArea:),random(3)+2,who);
}

int ShieldArea(object who) {
  int timelength;
  if (!who || undefinedp(who)) return 0;
  if (!environment(who)->GetProperty("no teleport"))
  {
    timelength = (random(15) + (who->GetSkillLevel("conjuring")
                                    + who->GetSkillLevel("enchantment") ) / 2 );
    send_messages(({"trace"}), "As $agent_name $agent_verb glowing "
                    "lines of warding about the area, the air seems to "
                    "still.", who, 0,environment(who));
    environment(who)->AddItem( ({"glowing lines","glowing line",
                                 "lines","line"}),
                                 "Glowing a pale flickering blue, the "
                                 "lines mark an area of some great "
                                 "magic.");
    environment(who)->SetProperty("no teleport",1);
    call_out((:EndShieldArea:), timelength, environment(who));
    return 1;
  }
  else
  {
    who->eventPrint("This room is already proof against teleportation.");
    return 0;
  }
}

int EndShieldArea(object env) {
  send_messages(({""}), "The glowing lines fade away.", env, 0);
  env->RemoveItem("glowing lines");
  env->SetProperty("no teleport",0);
  return 1;
}


/* Approved by Balishae on Fri Feb 20 08:07:14 1998. */
