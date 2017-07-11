#include <lib.h>
#include <music.h>
#include <damage_types.h>

inherit LIB_SONG;

void eventAria(object who, int level, object target, int length, int i);
void eventGeneralMessages(object who, int level, object target, int length, int i, string Room);

static void create() {
   song::create();
   SetSong("aria of angels");
   SetRules("");
   SetSongType(SONG_OTHER);
   SetMagicCost(150, 100);
   SetSkills( ([
          "vocal music" : 150,
          "instrumental music" : 150,
    ]) );
   SetDifficulty(175);
  SetHelp("This beautiful song fills the room around the singer with such wondrous harmony "
          "that all who hear it are healed by it's soothing melody.");
}

int CanSing(object who, int level, string limb, object array t) {
   if(environment(who)->GetProperty("aria_angel")) {
        who->eventPrint("The aria of angels melody is already playing here.");
        return 0;
   }
   return song::CanSing(who, level, limb, t);
}

int eventSing(object who, int level, mixed limb, object array t) {
   string Room;
   int i = 0;
   int length = (level/10)+1;
   int chance = level + random((int)who->GetSkillLevel("vocal music"));

   object *targets = filter(all_inventory(environment(who)), (: living :) );
   targets = filter(targets, (: noncreatorp :) );
   Room = base_name(environment(who));

   if(chance < 40) {
      send_messages("attempt","$agent_name $agent_verb "
                    "to sing but cannot get any words "
                    "out.",who,0,environment(who));
      return 1;
   }

   else {
      send_messages("begin","$agent_name $agent_verb to sing a beautiful harmony "
                    "that would enchant the gods themselves. It begins to echo "
                    "in the area.",who,0,environment(who));
      find_object(Room)->SetProperty("aria_angel",1);
      foreach(object targ in targets) {
        targ->SetProperty("aria_angel",1);
        call_out( (: eventAria, who, level, targ, length, i :), 10);
      }
      call_out( (: eventGeneralMessages, who, level, targets, length, i, Room :), 10);
      return 1;
   }

}

void eventAria(object who, int level, object target, int length, int i) {
   int damage = GetHealing(level);

   if(!target) return 0;

   if(!environment(target)->GetProperty("aria_angel")) {
        target->RemoveProperty("aria_angel");
        return;
   }
   if(target && (i < length)) {
        target->eventPrint("You feel %^BOLD%^%^BLUE%^calm%^RESET%^ as you listen to the aria.");
      target->eventHealDamage(damage, 1);
      i = i+1;
      call_out( (: eventAria, who, level, target, length, i :), 60);
      return;
   }
   target->RemoveProperty("aria_angel");
   return;
}

void eventGeneralMessages(object who, int level, object target, int length, int i, string Room) {
     object rainroom;
     rainroom = find_object(Room);
  if(environment(who) != rainroom) { return 0; }
     if(i<length) {
                i++;
     message("ariaangel", "The %^BOLD%^%^CYAN%^aria%^RESET%^ continues to echo throughout the area.", rainroom);
                foreach(object targ in all_inventory(rainroom)) {
                   if((living(targ)) && !targ->GetProperty("aria_angel")) {
                        targ->SetProperty("aria_angel",1);
                        call_out( (: eventAria, who, level, targ, length, i :), 0);
                        }
                }
      call_out( (: eventGeneralMessages, who, level, target, length, i, Room :), 60);
                return;
        }
   message("ariaangel", "The %^BOLD%^%^YELLOW%^aria%^RESET%^ slowly comes to an end.", rainroom);
   rainroom->RemoveProperty("aria_angel");
        return;
}



