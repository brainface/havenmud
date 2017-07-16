//
// Charisma spell for Bards
// Thoin@Haven

#include <lib.h>
#include <music.h>

int eventEndPlanar(object);
inherit LIB_SONG;

static void create() {
  song::create();
  SetSong("melodic allure");
  SetSongType(SONG_OTHER);
  SetRules("", "LIV");
  SetSkills(  ([
     "vocal music" : 60,
     "instrumental music" : 60,
               ])  );
  SetMagicCost(50, 50);
  SetDifficulty(25);
  SetHelp(
    "This beautiful song allows the bard to appear more beautiful and alluring as if "
   "the Goddess Alessandra has blessed the bard's beauty.");
}

int CanSing(object who, int level, mixed limb, object array targets) {
  object target = targets[0];
  if(target->GetProperty("melodic_allure")) {
    message("system", "That person already has an air of allure surrounding them."
            , who);
    return 0;
  }
  return song::CanSing(who, level, limb, targets);
}

int eventSing(object who, int level, string limb, object array targets)  {
  int amt, dur;
  object target = targets[0];
  amt = (level + who->GetSkillLevel("vocal music") +
    who->GetSkillLevel("instrumental music"))/15;
   dur = (level * (15 + 10 + who->GetSkillLevel("vocal music")/20));
  target->SetProperty("melodic_allure", 1);
  call_out( (: eventEndPlanar, target :), dur);

/* FUMBLE FUMBLE FUMBLE */

  if (!(random(to_int(level/3)))) {
    target->AddStatBonus("charisma", -amt, dur);
      send_messages( ({ "sing", "cause" }), "$agent_name $agent_verb a note "
        "off key that $agent_verb $target_name to become hideously "
        "ugly.", who, target,
        environment(target));
  return 1;
  }

/* SUCCESS SUCCESS SUCCESS */

  if (target == who) {
    send_messages( ({ "sing", "use" }), "$agent_name $agent_verb a beautiful melody "
                  "that echoes of angels causing $agent_name to become radiantly "
                  "beautiful.", who, 0, environment(who));
  }
  else {
    send_messages( ({ "sing", "use" }), "$agent_name $agent_verb a beautiful melody "
                  "that echoes of angels causing $target_name to become radiantly "
                  "beautiful.", who, target, environment(target));
  }
  target->AddStatBonus("charisma", amt, dur);
  return 1;
}

int eventEndPlanar(object who) {
        if (!who) {
                return 1;
        }
        who->RemoveProperty("melodic_allure");
        who->RemoveStatBonus("charisma");
        who->eventPrint("%^YELLOW%^The allure about you fades.%^RESET%^");
        return 1;
}

